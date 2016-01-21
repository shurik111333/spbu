using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
//using System.Threading.Tasks;

namespace Interpreter
{
    internal sealed partial class Parser
    {
        internal static class Lexer
        {
            public const char Add = '+', Minus = '-', Divide = '/', Multiply = '*', OpenBracket = '(', CloseBracket = ')', Space = ' ', Semicolon = ';', EqualSign = '=',
                              Underline = '_', OpenBlockBracket = '{', CloseBlockBracket = '}', Point = '.', Not = '!', Higher = '>', Lower = '<', Quote = '"', LineFeed = '\n',
                              Tab = '\t', Colon = ':', OpenSquadBracket = '[', CloseSquadBracket = ']', EOF = '\0', Comma = ',';

            public const string Exp = "Ee", Degree = "**", Spaces = " \r\n\t", If = "if", Else = "else", For = "for", Print = "print", ExpNotation = "E,+-", While = "while",
                                GoTo = "goto";

            private const string digits = "1234567890", letters = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM";

            private static string expression;

            public static Nodes.Node.Coords Coords
            {
                get
                {
                    return ArrayOfLexems[position].StartCoords;
                }
            }

            private static char symbol
            {
                get
                {
                    return GetSymbol(endPosition);
                }
            }

            private static int position;

            private static int x;
            private static int y;

            private static int startPosition;
            private static int endPosition;

            private static Lexem[] ArrayOfLexems;

            public static void Init(string expr)
            {
                if (expr == null)
                    throw new ArgumentNullException("expr");
                expression = expr;
                x = 1;
                y = 1;
                startPosition = 0;
                endPosition = 0;
                MakeLexems();
                position = 0;
            }

            public enum LexType
            {
                Number,
                OpenBreaket,
                CloseBracket,
                Add,
                Divide,
                Multiply,
                Minus,
                Degree,
                Semicolon,
                Error,
                Variable,
                EOF,
                EqualSign,
                OpenBlockBracket,
                CloseBlockBracket,
                If,
                Else,
                Equal,
                Higher,
                Lower,
                LowEqual,
                HighEqual,
                NotEqual,
                For,
                Print,
                Quote,
                String,
                While,
                Colon,
                GoTo,
                OpenSquadBracket,
                CloseSquadBracket
            }

            public struct Lexem
            {
                public LexType LexType;
                public float Value;
                public string VarName;
                public Nodes.Node.Coords StartCoords;
                public Nodes.Node.Coords EndCoords;

                private static Nodes.Node.Coords GetEndCoords()
                {
                    PushCoordinates();
                    return new Nodes.Node.Coords(x, y);
                }

                private void SetCoords()
                {
                    StartCoords = new Nodes.Node.Coords(x, y);
                    EndCoords = GetEndCoords();
                }

                public Lexem(LexType type)
                {
                    LexType = type;
                    Value = 0;
                    VarName = "";
                    StartCoords = default(Nodes.Node.Coords);
                    EndCoords = default(Nodes.Node.Coords);
                    SetCoords();
                }

                public Lexem(float number)
                {
                    LexType = LexType.Number;
                    Value = number;
                    VarName = "";
                    StartCoords = default(Nodes.Node.Coords);
                    EndCoords = default(Nodes.Node.Coords);
                    SetCoords();
                }

                public Lexem(string name)
                {
                    LexType = LexType.Variable;
                    Value = 0;
                    VarName = name;
                    StartCoords = default(Nodes.Node.Coords);
                    EndCoords = default(Nodes.Node.Coords);
                    SetCoords();
                }

                public Lexem(int start, int end)
                {
                    LexType = LexType.String;
                    Value = 0;
                    VarName = expression.Substring(start, end - start + 1);
                    StartCoords = default(Nodes.Node.Coords);
                    EndCoords = default(Nodes.Node.Coords);
                    SetCoords();
                }
            }

            private static char GetSymbol(int position)
            {
                return position < expression.Length ? expression[position] : EOF;
            }

            private static void PushCoordinates()
            {
                for (int i = startPosition; i < endPosition; i++)
                {
                    switch (GetSymbol(i))
                    {
                        case LineFeed:
                            x = 1;
                            y++;
                            break;
                        case Tab:
                            x += 3;
                            break;
                        default:
                            x++;
                            break;
                    }
                }
                startPosition = endPosition;
            }

            private static void MakeLexems()
            {
                List<Lexem> Lexems = new List<Lexem>();
                Lexem lexem;
                do
                {
                    lexem = GetLexem();
                    Lexems.Add(lexem);
                } while (lexem.LexType != LexType.EOF);
                ArrayOfLexems = Lexems.ToArray();
            }

            public static Lexem LookAhead()
            {
                return ArrayOfLexems[position];
            }

            public static Lexem RollBack()
            {
                if (position == 0)
                {
                    position++;
                }
                position--;
                return ArrayOfLexems[position];
            }

            public static Lexem LookBack()
            {
                if (position == 0)
                {
                    return ArrayOfLexems[position];
                }
                return ArrayOfLexems[position - 1];
            }

            public static Lexem NextLexem()
            {
                return (position < ArrayOfLexems.Length - 1) ? ArrayOfLexems[position++] : ArrayOfLexems[position];
            }

            private static Lexem GetLexem()
            {
                SkipSpaces();
                Lexem result = default(Lexem);
                switch (symbol)
                {
                    case EOF:
                        result = new Lexem(LexType.EOF);
                        break;
                    case Add:
                        result = new Lexem(LexType.Add);
                        break;
                    case Minus:
                        result = new Lexem(LexType.Minus);
                        break;
                    case Multiply:
                        endPosition++;
                        if (symbol == Multiply)
                        { 
                            result = new Lexem(LexType.Degree);
                        }
                        else
                        {
                            endPosition--;
                            result = new Lexem(LexType.Multiply);
                        }
                        break;
                    case Divide:
                        result = new Lexem(LexType.Divide);
                        break;
                    case OpenBracket:
                        result = new Lexem(LexType.OpenBreaket);
                        break;
                    case CloseBracket:
                        result = new Lexem(LexType.CloseBracket);
                        break;
                    case Semicolon:
                        result = new Lexem(LexType.Semicolon);
                        break;
                    case EqualSign:
                        endPosition++;
                        if (symbol == EqualSign)
                        {
                            result = new Lexem(LexType.Equal);
                        }
                        else
                        {
                            endPosition--;
                            result = new Lexem(LexType.EqualSign);
                        }
                        break;
                    case OpenBlockBracket:
                        result = new Lexem(LexType.OpenBlockBracket);
                        break;
                    case CloseBlockBracket:
                        result = new Lexem(LexType.CloseBlockBracket);
                        break;
                    case OpenSquadBracket:
                        result = new Lexem(LexType.OpenSquadBracket);
                        break;
                    case CloseSquadBracket:
                        result = new Lexem(LexType.CloseSquadBracket);
                        break;
                    case Colon:
                        result = new Lexem(LexType.Colon);
                        break;
                    case Not:
                        endPosition++;
                        if (symbol == EqualSign)
                        {
                            result = new Lexem(LexType.NotEqual);
                        }
                        else
                        {
                            Parser.ErrorList.Add(new Error(LexerException.IncorrectOperator, new Nodes.Node.Coords(x, y)));
                            result = GetLexem();
                        }
                        break;
                    case Higher:
                        endPosition++;
                        if (symbol == EqualSign)
                        {
                            result = new Lexem(LexType.HighEqual);
                        }
                        else
                        {
                            endPosition--;
                            result = new Lexem(LexType.Higher);
                        }
                        break;
                    case Lower:
                        endPosition++;
                        if (symbol == EqualSign)
                        {
                            result = new Lexem(LexType.LowEqual);
                        }
                        else
                        {
                            endPosition--;
                            result = new Lexem(LexType.Lower);
                        }
                        break;
                    case Quote:
                        int newPos = endPosition + 1;
                        while (newPos < expression.Length && expression[newPos] != Quote && expression[newPos] != LineFeed)
                        {
                            newPos++;
                        }
                        result = new Lexem(endPosition + 1, newPos - 1);
                        endPosition = newPos;
                        break;
                    default:
                        if (digits.Contains(symbol))
                        {
                            result = GetNumber();
                            break;
                        }
                        if (letters.Contains(symbol) || symbol == Underline)
                        {
                            result = GetVar();
                            break;
                        }
                        Parser.ErrorList.Add(new Error(LexerException.IncorrectSymbol, new Nodes.Node.Coords(x, y)));
                        endPosition++;
                        PushCoordinates();
                        result = GetLexem();
                        break;
                }
                endPosition++;
                PushCoordinates();
                return result;
            }

            private static void SkipSpaces()
            {
                while (Spaces.Contains(symbol))
                {
                    endPosition++;
                }
                PushCoordinates();
            }
   

            private static Lexem GetVar()
            {
                while ((letters.Contains(symbol) || digits.Contains(symbol) || symbol == Underline))
                {
                    endPosition++;
                }
                string result = expression.Substring(startPosition, endPosition - startPosition);
                endPosition--;
                switch (result)
                {
                    case If:
                        return new Lexem(LexType.If);
                    case Else:
                        return new Lexem(LexType.Else);
                    case For:
                        return new Lexem(LexType.For);
                    case Print:
                        return new Lexem(LexType.Print);
                    case While:
                        return new Lexem(LexType.While);
                    case GoTo:
                        return new Lexem(LexType.GoTo);
                    default:
                        return new Lexem(result);
                }
            }

            private enum ExponentParts
            {
                IntegerPart,
                Point,
                FractionPart,
                Exp,
                Sign,
                Power
            }

            private static Lexem GetNumber()
            {
                endPosition = GetEndOfNumber();
                Lexem result;
                float number = 0;
                bool correctNumber = true;
                try
                {
                    number = float.Parse(expression.Substring(startPosition, endPosition - startPosition + 1).Replace(Point, Comma));
                }
                catch (Exception)
                {
                    correctNumber = false;
                }
                finally
                {
                    result = new Lexem(number);
                    if (!correctNumber)
                        Parser.ErrorList.Add(new Error(LexerException.IncorrectNumber, result.StartCoords, result.EndCoords));
                }
                return result;
            }
            
            private static int GetEndOfNumber()
            {
                ExponentParts currPart = ExponentParts.IntegerPart;
                while (endPosition < expression.Length)
                {
                    switch (currPart)
                    {
                        case ExponentParts.IntegerPart:
                            if (digits.Contains(symbol))
                                break;
                            if (symbol == Point)
                            {
                                currPart = ExponentParts.Point;
                                break;
                            }
                            if (Exp.Contains(symbol))
                            {
                                currPart = ExponentParts.Exp;
                                break;
                            }
                            return endPosition - 1;
                        case ExponentParts.Point:
                            if (digits.Contains(symbol))
                            {
                                currPart = ExponentParts.FractionPart;
                                break;
                            }
                            return endPosition - 1;
                        case ExponentParts.FractionPart:
                            if (digits.Contains(symbol))
                                break;
                            if (Exp.Contains(symbol))
                            {
                                currPart = ExponentParts.Exp;
                                break;
                            }
                            return endPosition - 1;
                        case ExponentParts.Exp:
                            if (digits.Contains(symbol))
                            {
                                currPart = ExponentParts.Power;
                                break;
                            }
                            if (symbol == Add || symbol == Minus)
                            {
                                currPart = ExponentParts.Sign;
                                break;
                            }
                            return endPosition - 1;
                        case ExponentParts.Sign:
                            if (digits.Contains(symbol))
                            {
                                currPart = ExponentParts.Power;
                                break;
                            }
                            return endPosition - 1;
                        case ExponentParts.Power:
                            if (digits.Contains(symbol))
                                break;
                            return endPosition - 1;
                    }
                    endPosition++;
                }
                return endPosition - 1;
            }
        }
    }
}
