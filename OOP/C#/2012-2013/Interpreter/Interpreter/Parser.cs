using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
//using System.Threading.Tasks;

namespace Interpreter
{
    internal sealed partial class Parser
    {
        public static List<Error> ErrorList;

        public struct Error
        {
            public string Description;
            public Nodes.Node.Coords Start;
            public Nodes.Node.Coords End;

            public Error(string error, Nodes.Node.Coords coords)
            {
                Description = error;
                Start = coords;
                End = coords;
            }

            public Error(string error, Nodes.Node.Coords start, Nodes.Node.Coords end)
            {
                Description = error;
                Start = start;
                End = end;
            }
        }

        //private static List<Nodes.Statement> Statements;

        public static Nodes.Program Program(string expression)
        {
            if (expression == null)
            {
                throw new ArgumentNullException("expression");
            }
            ErrorList = new List<Error>();
            //Lexer lexer = new Lexer(expression);
            Lexer.Init(expression);
            Nodes.Statement FirstStatement;
            Memory.Labels = new Dictionary<string, Nodes.Statement>();
            try
            {
                FirstStatement = StatementList();
            }
            catch (ParserException)
            {
                return null;
            }
            catch (LexerException)
            {
                return null;
            }
            return new Nodes.Program(FirstStatement);
        }

        private static Nodes.Statement StatementList()
        {
            Nodes.Statement CurrStatement = Statement();
            Nodes.Statement PrevStatement = CurrStatement.Tail;
            Nodes.Statement FirstStatement = CurrStatement.Head;
            CurrStatement = Statement();
            while (CurrStatement != null)
            {
                PrevStatement.Next = CurrStatement.Head;
                PrevStatement = CurrStatement.Tail;
                CurrStatement = Statement();
            }
            return FirstStatement;
        }

        private static Nodes.Statement Statement()
        {
            if (Lexer.LookAhead().LexType == Lexer.LexType.EOF)
                return null;
            Nodes.Statement statement;
            statement = If();
            if (statement != null)
                return statement;
            statement = For();
            if (statement != null)
                return statement;
            statement = Print();
            if (statement != null)
                return statement;
            statement = While();
            if (statement != null)
                return statement;
            statement = Assignment();
            if (statement != null)
            {
                if (Lexer.LookAhead().LexType != Lexer.LexType.Semicolon)
                    ErrorList.Add(new Error(ParserException.NeedSemicolon, Lexer.LookBack().EndCoords));
                else
                    Lexer.NextLexem();
                return statement;
            }
            statement = GoTo();
            if (statement != null)
                return statement;
            statement = Label();
            if (statement != null)
                return statement;
            ErrorList.Add(new Error(ParserException.IncorrectStatement, Lexer.LookAhead().StartCoords, Lexer.LookAhead().EndCoords));

            /*while (Lexer.LookAhead().LexType != Lexer.LexType.Semicolon && Lexer.LookAhead().LexType != Lexer.LexType.EOF)
                Lexer.NextLexem();
            if (Lexer.LookAhead().LexType == Lexer.LexType.EOF)
                return null;*/
            Lexer.NextLexem();
            return Statement();
			
        }

        private static Nodes.Statement Label()
        {
            Lexer.Lexem currLexem = Lexer.NextLexem();
            if (currLexem.LexType == Lexer.LexType.Variable && Lexer.LookAhead().LexType == Lexer.LexType.Colon)
            {
                Lexer.NextLexem();
                Nodes.Statement result = Statement();
                Memory.Labels.Add(currLexem.VarName, result);
                return result;
            }
            else
            {
                if (currLexem.LexType != Lexer.LexType.EOF)
                    Lexer.RollBack();
                return null;
            }
        }

        private static Nodes.GoTo GoTo()
        {
            //Nodes.Node.Coords coords = new Nodes.Node.Coords(Lexer.Coords.X, Lexer.Y);
            Nodes.Node.Coords coords = Lexer.Coords;
            if (Lexer.LookAhead().LexType != Lexer.LexType.GoTo)
                return null;

            Lexer.NextLexem();

            Nodes.GoTo result = null;
            if (Lexer.LookAhead().LexType != Lexer.LexType.Variable)
            {
                ErrorList.Add(new Error(ParserException.NeedLabel, Lexer.LookBack().EndCoords));
                result = new Nodes.GoTo("");
            }
            else
            {
                result = new Nodes.GoTo(Lexer.NextLexem().VarName);
                result.Head = result;
                result.Tail = result;
            }

            if (Lexer.LookAhead().LexType != Lexer.LexType.Semicolon)
                ErrorList.Add(new Error(ParserException.NeedSemicolon, Lexer.LookBack().EndCoords));
            else
                Lexer.NextLexem();
            result.Coords = coords;
            return result;
        }

        private static Nodes.While While()
        {
            Nodes.Node.Coords coords = Lexer.Coords;
            if (Lexer.LookAhead().LexType != Lexer.LexType.While)
                return null;

            Lexer.NextLexem();

            if (Lexer.LookAhead().LexType != Lexer.LexType.OpenBreaket)
                ErrorList.Add(new Error(ParserException.MissedOpenBracket, Lexer.LookBack().EndCoords));
            else
                Lexer.NextLexem();

            Nodes.Condition condition = Condition();

            if (Lexer.LookAhead().LexType != Lexer.LexType.CloseBracket)
                ErrorList.Add(new Error(ParserException.MissedCloseBracket, Lexer.LookBack().EndCoords));
            else
                Lexer.NextLexem();

            Nodes.End end = new Nodes.End();

            Nodes.Block block = Block();

            block.Last.Tail.Next = condition;
            
            condition.NextFalse = end;
            condition.NextTrue = block.First.Head;

            //Statements.Add(end);
            Nodes.While result = new Nodes.While(condition, block.First, end);

            result.Coords = coords;

            return result;
        }

        private static Nodes.Print Print()
        {
            Nodes.Node.Coords coords = Lexer.Coords;
            if (Lexer.LookAhead().LexType != Lexer.LexType.Print)
                return null;

            Lexer.NextLexem();
            //Lexer.SkipSpacesCoords();

            if (Lexer.LookAhead().LexType != Lexer.LexType.OpenBreaket)
                ErrorList.Add(new Error(ParserException.MissedOpenBracket, Lexer.LookBack().EndCoords));
            else
                Lexer.NextLexem();

            Nodes.Print result;
            if (Lexer.LookAhead().LexType == Lexer.LexType.String)
                result = new Nodes.Print(Lexer.NextLexem().VarName, new Print());
            else
                result = new Nodes.Print(Expr(), new Print());

            if (Lexer.LookAhead().LexType != Lexer.LexType.CloseBracket)
                ErrorList.Add(new Error(ParserException.MissedCloseBracket, Lexer.LookBack().EndCoords));
            else
                Lexer.NextLexem();

            if (Lexer.LookAhead().LexType != Lexer.LexType.Semicolon)
                ErrorList.Add(new Error(ParserException.NeedSemicolon, Lexer.LookBack().EndCoords));
            else
                Lexer.NextLexem();

            //Statements.Add(result);
            result.Head = result;
            result.Tail = result;
            result.Coords = coords;

            return result;
        }

        private static Nodes.For For()
        {
            Nodes.Node.Coords coords = Lexer.Coords;
            if (Lexer.LookAhead().LexType != Lexer.LexType.For)
            {
                return null;
            }

            Lexer.NextLexem();
            //Lexer.SkipSpacesCoords();

            if (Lexer.LookAhead().LexType != Lexer.LexType.OpenBreaket)
            {
                ErrorList.Add(new Error(ParserException.MissedOpenBracket, Lexer.LookBack().EndCoords));
            }
            else
                Lexer.NextLexem();

            /*if (Lexer.LookAhead().LexType != Lexer.LexType.Variable)
                Lexer.NextLexem();*/

            Nodes.Assignment assgn = Assignment();

            //Statements.Add(assgn);

            if (Lexer.LookAhead().LexType != Lexer.LexType.Semicolon)
                ErrorList.Add(new Error(ParserException.NeedSemicolon, Lexer.LookBack().EndCoords));
            else
                Lexer.NextLexem();

            /*Lexer.Lexem nextLexem = Lexer.LookAhead();
            if (nextLexem.LexType != Lexer.LexType.Number && nextLexem.LexType != Lexer.LexType.Variable && nextLexem.LexType != Lexer.LexType.OpenBreaket)
                Lexer.NextLexem();*/

            Nodes.Condition cond = Condition();
            assgn.Next = cond;
            //Statements.Add(cond);

            if (Lexer.LookAhead().LexType != Lexer.LexType.Semicolon)
                ErrorList.Add(new Error(ParserException.NeedSemicolon, Lexer.LookBack().EndCoords));
            else
                Lexer.NextLexem();

            /*if (Lexer.LookAhead().LexType != Lexer.LexType.Variable)
                Lexer.NextLexem();*/

            Nodes.Assignment chngAssgn = Assignment();
            chngAssgn.Next = cond;

            Nodes.End end = new Nodes.End();
            cond.NextFalse = end;
            

            if (Lexer.LookAhead().LexType != Lexer.LexType.CloseBracket)
                ErrorList.Add(new Error(ParserException.MissedCloseBracket, Lexer.LookBack().EndCoords));
            else
                Lexer.NextLexem();

            Nodes.Block FirstStatement = Block(); //TODO
            cond.NextTrue = FirstStatement.First.Head;

            //Statements.Add(end);

            return new Nodes.For(assgn, cond, chngAssgn, FirstStatement.First.Head, end, coords);
        }

        private static Nodes.If If()
        {
            Nodes.Node.Coords coords = Lexer.Coords;
            if (Lexer.LookAhead().LexType != Lexer.LexType.If)
            {
                return null;
            }

            Lexer.NextLexem();
            //Lexer.SkipSpacesCoords();

            if (Lexer.LookAhead().LexType != Lexer.LexType.OpenBreaket)
            {
                ErrorList.Add(new Error(ParserException.MissedOpenBracket, Lexer.LookBack().EndCoords));
            }
            else
                Lexer.NextLexem();

            /*Lexer.Lexem nextLexem = Lexer.LookAhead();
            if (nextLexem.LexType != Lexer.LexType.Number && nextLexem.LexType != Lexer.LexType.Variable && nextLexem.LexType != Lexer.LexType.OpenBreaket)
                Lexer.NextLexem();*/

            Nodes.Condition condition = Condition();

            if (Lexer.LookAhead().LexType != Lexer.LexType.CloseBracket)
            {
                ErrorList.Add(new Error(ParserException.MissedCloseBracket, Lexer.LookBack().EndCoords));
            }
            else
                Lexer.NextLexem();

            Nodes.End end = new Nodes.End();

            //TODO

            Nodes.Block ifBlock = Block();

            Nodes.Block elseBlock = null;
            if (Lexer.LookAhead().LexType == Lexer.LexType.Else)
            {
                Lexer.NextLexem();
                elseBlock = Block();
            }

            condition.NextTrue = ifBlock.First.Head;
            if (elseBlock != null)
                condition.NextFalse = elseBlock.First.Head;
            else
                condition.NextFalse = end;


            //Statements.Add(end);
            return new Nodes.If(condition, ifBlock.First, elseBlock.First, end, coords);
        }

        private static Nodes.Condition Condition()
        {
            Nodes.Node.Coords coords = Lexer.Coords;
            Nodes.Expression left = Expr();
            Lexer.Lexem currLexem = Lexer.NextLexem();
            Nodes.Condition.CompareSign sign;
            switch (currLexem.LexType)
            {
                case Lexer.LexType.Equal:
                    sign = Nodes.Condition.CompareSign.Equal;
                    break;
                case Lexer.LexType.HighEqual:
                    sign = Nodes.Condition.CompareSign.HighEqual;
                    break;
                case Lexer.LexType.Higher:
                    sign = Nodes.Condition.CompareSign.Higher;
                    break;
                case Lexer.LexType.LowEqual:
                    sign = Nodes.Condition.CompareSign.LowEqual;
                    break;
                case Lexer.LexType.Lower:
                    sign = Nodes.Condition.CompareSign.Lower;
                    break;
                case Lexer.LexType.NotEqual:
                    sign = Nodes.Condition.CompareSign.NotEqual;
                    break;
                default:
                    if (currLexem.LexType != Lexer.LexType.EOF)
                        Lexer.RollBack();
                    ErrorList.Add(new Error(ParserException.NeedCompareSign, Lexer.LookBack().EndCoords));
                    sign = Nodes.Condition.CompareSign.Error;
                    break;
            }
            Nodes.Expression right = Expr();
            Nodes.Condition result = new Nodes.Condition(left, sign, right);
            //Statements.Add(result);
            result.Head = result;
            result.Tail = result;
            result.Coords = coords;

            return result;
        }

        //private static Nodes.Statement Block(Nodes.Statement End)
        private static Nodes.Block Block()
        {
            Nodes.Block result = null;
            Nodes.Statement FirstStatement = null;
            if (Lexer.LookAhead().LexType == Lexer.LexType.OpenBlockBracket)
            {
                Lexer.NextLexem();

                Nodes.Statement PrevStatement = null, CurrStatement = null;

                while (Lexer.LookAhead().LexType != Lexer.LexType.CloseBlockBracket && Lexer.LookAhead().LexType != Lexer.LexType.EOF)
                {
                    CurrStatement = Statement();
                    if (PrevStatement == null)
                        FirstStatement = CurrStatement.Head;
                    else
                    {
                        PrevStatement.Next = CurrStatement.Head;
                    }

                    PrevStatement = CurrStatement.Tail;
                }

                /*if (CurrStatement != null)
                    CurrStatement.Tail.Next = End;*/

                if (Lexer.LookAhead().LexType != Lexer.LexType.CloseBlockBracket)
                {
                    ErrorList.Add(new Error(ParserException.MissedBlockBracket, Lexer.LookBack().EndCoords));
                }
                else
                    Lexer.NextLexem();
                if (FirstStatement == null)
                {
                    result = new Nodes.Block();
                }
                else
                {
                    result = new Nodes.Block(FirstStatement.Head, CurrStatement != null ? CurrStatement.Tail : PrevStatement.Tail);
                }
            }
            else
            {
                FirstStatement = Statement();

                if (FirstStatement == null)
                {
                    ErrorList.Add(new Error(ParserException.NeedStatement, Lexer.LookAhead().StartCoords));
                    result = new Nodes.Block();
                }
                else
                    result = new Nodes.Block(FirstStatement.Head, FirstStatement.Tail);
                
                /*else
                    FirstStatement.Tail.Next = End;*/
            }
            return result;
        }

        private static Nodes.Assignment Assignment()
        {
            Nodes.Node.Coords coords = Lexer.Coords;
            if (Lexer.LookAhead().LexType != Lexer.LexType.Variable)
                return null;
            Lexer.Lexem currLexem = Lexer.NextLexem();
            if (Lexer.LookAhead().LexType == Lexer.LexType.EqualSign)
            {
                Lexer.NextLexem();
                if (Lexer.LookAhead().LexType == Lexer.LexType.String)
                {
                    Nodes.Expression strValue = Expr();
                    /*if (Lexer.LookAhead().LexType != Lexer.LexType.Semicolon)
                        ErrorList.Add(new Error(ParserException.NeedSemicolon, Lexer.LookBack().EndCoords));
                    else
                        Lexer.NextLexem();*/
                    Nodes.Assignment result = new Nodes.Assignment(new Nodes.Variable(currLexem.VarName), strValue, coords);
                    result.Head = result;
                    result.Tail = result;
                    return result;
                }
                else
                    return VariableAssignment(currLexem, coords);
            }
            else
                if (Lexer.LookAhead().LexType == Lexer.LexType.OpenSquadBracket)
                {
                    Lexer.NextLexem();
                    return ArrayAssignment(currLexem, coords);
                }
                else
                {
                    Lexer.RollBack();
                    return null;
                }
        }

        private static Nodes.Assignment ArrayAssignment(Lexer.Lexem currLexem, Nodes.Node.Coords coords)
        {
            Nodes.Expression index = Expr();
            if (Lexer.LookAhead().LexType != Lexer.LexType.CloseSquadBracket)
                ErrorList.Add(new Error(ParserException.NeedCloseSquadBracket, Lexer.LookBack().EndCoords));
            else
                Lexer.NextLexem();

            if (Lexer.LookAhead().LexType == Lexer.LexType.EqualSign)
            {
                Lexer.NextLexem();
                Nodes.Expression value = Expr();
                /*if (Lexer.LookAhead().LexType != Lexer.LexType.Semicolon)
                    ErrorList.Add(new Error(ParserException.NeedSemicolon, Lexer.LookBack().EndCoords));
                else
                    Lexer.NextLexem();*/
                Nodes.Assignment result = new Nodes.Assignment(new Nodes.ElementOfArray(currLexem.VarName, index), value, coords);
                result.Head = result;
                result.Tail = result;
                return result;
            }
            else
            {
                while (Lexer.LookBack().LexType != Lexer.LexType.Variable)
                    Lexer.RollBack();
                Lexer.RollBack();
                return null;
            }
        }

        private static Nodes.Assignment VariableAssignment(Lexer.Lexem currLexem, Nodes.Node.Coords coords)
        {
            Nodes.Expression value = Expr();
            /*if (Lexer.LookAhead().LexType != Lexer.LexType.Semicolon)
            {
                throw new ParserException();
            }
            Lexer.NextLexem();*/
            /*if (Lexer.LookAhead().LexType != Lexer.LexType.Semicolon)
                ErrorList.Add(new Error(ParserException.NeedSemicolon, Lexer.LookBack().EndCoords));
            else
                Lexer.NextLexem();*/
            Nodes.Assignment result = new Nodes.Assignment(new Nodes.IntVar(currLexem.VarName), value, coords);
            //Statements.Add(result);
            result.Head = result;
            result.Tail = result;

            return result;
        }

        private static Nodes.Expression Expr()
        {
            Nodes.Node.Coords coords = Lexer.Coords;
            Nodes.Expression left = Term();

            while (Lexer.LookAhead().LexType == Lexer.LexType.Add || Lexer.LookAhead().LexType == Lexer.LexType.Minus)
            {
                if (Lexer.LookAhead().LexType == Lexer.LexType.Add)
                {
                    Lexer.NextLexem();
                    Nodes.Expression right = Term();
                    left = new Nodes.BinaryOperation(Nodes.BinaryOperation.TypeOfOperations.Add, left, right);
                }
                else
                    if (Lexer.LookAhead().LexType == Lexer.LexType.Minus)
                    {
                        Lexer.NextLexem();
                        Nodes.Expression right = Term();
                        left = new Nodes.BinaryOperation(Nodes.BinaryOperation.TypeOfOperations.Minus, left, right);
                    }
            }
            left.Coords = coords;
            return left;
        }

        private static Nodes.Expression Term()
        {
            Nodes.Expression left = Deg();
            while (Lexer.LookAhead().LexType == Lexer.LexType.Multiply || Lexer.LookAhead().LexType == Lexer.LexType.Divide)
            {
                if (Lexer.LookAhead().LexType == Lexer.LexType.Multiply)
                {
                    Lexer.NextLexem();
                    Nodes.Expression right = Deg();
                    left = new Nodes.BinaryOperation(Nodes.BinaryOperation.TypeOfOperations.Multiply, left, right);
                }
                else
                    if (Lexer.LookAhead().LexType == Lexer.LexType.Divide)
                    {
                        Lexer.NextLexem();
                        Nodes.Expression right = Deg();
                        left = new Nodes.BinaryOperation(Nodes.BinaryOperation.TypeOfOperations.Division, left, right);
                    }
            }
            return left;
            /*StringBuilder result = Deg();
            Lexer.Lexem currLexem = Lexer.LookAhead();
            while (true)
            {
                if (currLexem.LexType == Lexer.LexType.Divide)
                {
                    Lexer.NextLexem();
                    result.Append(Lexer.Space);
                    result.Append(Deg());
                    result.Append(Lexer.Space);
                    result.Append(Lexer.Divide);
                }
                else
                    if (currLexem.LexType == Lexer.LexType.Multiply)
                    {
                        Lexer.NextLexem();
                        result.Append(Lexer.Space);
                        result.Append(Deg());
                        result.Append(Lexer.Space);
                        result.Append(Lexer.Multiply);
                    }
                    else
                        break;
                currLexem = Lexer.LookAhead();
            }
            return result;*/
            /*Nodes.Expression left = Deg();
            Lexer.Lexem currLexem = Lexer.LookAhead();
            if (currLexem.LexType == Lexer.LexType.Multiply)
            {
                Lexer.NextLexem();
                return new Nodes.BinaryOperation(Nodes.BinaryOperation.TypeOfOperations.Multiply, left, Term());
            }
            if (currLexem.LexType == Lexer.LexType.Divide)
            {
                Lexer.NextLexem();
                return new Nodes.BinaryOperation(Nodes.BinaryOperation.TypeOfOperations.Division, left, Term());
            }*/
        }

        private static Nodes.Expression Deg()
        {
            Nodes.Expression left = Factor();
            Lexer.Lexem currLexem = Lexer.LookAhead();
            if (currLexem.LexType == Lexer.LexType.Degree)
            {
                //int countLexems = 1;
                Lexer.NextLexem();
                return new Nodes.BinaryOperation(Nodes.BinaryOperation.TypeOfOperations.Degree, left, Deg());
                /*for (int i = 0; i < countLexems - 1; i++)
                {
                    result.Append(Lexer.Space);
                    result.Append(Lexer.Degree);
                }*/
            }
            return left;
        }

        private static Nodes.Expression Factor()
        {
            Lexer.Lexem currLexem = Lexer.NextLexem();
            if (currLexem.LexType == Lexer.LexType.Number)
            {
                return new Nodes.Number(currLexem.Value);
            }
            if (currLexem.LexType == Lexer.LexType.OpenBreaket)
            {
                Nodes.Expression result = Expr();
                if (Lexer.LookAhead().LexType != Lexer.LexType.CloseBracket)
                {
                    ErrorList.Add(new Error(ParserException.MissedCloseBracket, Lexer.LookBack().EndCoords));
                }
                else
                    Lexer.NextLexem();
                return result;
            }
            if (currLexem.LexType == Lexer.LexType.Variable)
            {
                if (Lexer.LookAhead().LexType != Lexer.LexType.OpenSquadBracket)
                    return new Nodes.Variable(currLexem.VarName);
                else
                {
                    Lexer.NextLexem();
                    Nodes.Expression index = Expr();
                    if (Lexer.LookAhead().LexType != Lexer.LexType.CloseSquadBracket)
                        ErrorList.Add(new Error(ParserException.NeedCloseSquadBracket, Lexer.LookBack().EndCoords));
                    else
                        Lexer.NextLexem();
                    return new Nodes.ElementOfArray(currLexem.VarName, index);
                }
            }
            if (currLexem.LexType == Lexer.LexType.String)
            {
                return new Nodes.MyString(currLexem.VarName);
            }
            /*if (currLexem.LexType == Lexer.LexType.EOF)
            {
                throw new ParserException();
            }*/
            if (currLexem.LexType != Lexer.LexType.EOF)
                Lexer.RollBack();
            ErrorList.Add(new Error(ParserException.IncorrectExpression, Lexer.LookBack().StartCoords, Lexer.LookBack().EndCoords));
            return new Nodes.Expression();
        }

    }
}