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
                              Underline = '_', OpenBlockBracket = '{', CloseBlockBracket = '}', Comma = ',', Not = '!', Higher = '>', Lower = '<', Quote = '"', LineFeed = '\n',
                              Tab = '\t', Exp = 'E', Colon = ':', OpenSquadBracket = '[', CloseSquadBracket = ']';

            public const string Degree = "**", Spaces = " \r\n\t", If = "if", Else = "else", For = "for", Print = "print", ExpNotation = "E,+-", While = "while",
                                GoTo = "goto";

            private const string digits = "1234567890", letters = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM";

            private static string expression;

            public static Nodes.Node.Coords Coords
            {
                private set;

                public get
                {
                    return ArrayOfLexems[position].Coords;
                }
            }

            private static int x;
            private static int y;

            private static int position;

            private static Lexem[] ArrayOfLexems;

            public static void Init(string expr)
            {
                if (expr == null)
                    throw new ArgumentNullException("expr");
                expression = expr;
                x = 1;
                y = 1;
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
                public Nodes.Node.Coords Coords;
                public Nodes.Node.Coords EndCoords;

                private static Nodes.Node.Coords GetEndCoords(Nodes.Node.Coords startCoords)
                {
                    return new Nodes.Node.Coords(position - startCoords.X + 1, startCoords.Y);
                }

                public Lexem(LexType type)
                {
                    LexType = type;
                    Value = 0;
                    VarName = "";
                    Coords = new Nodes.Node.Coords(x, y);
                    EndCoords = GetEndCoords(Coords);
                }

                public Lexem(float number)
                {
                    LexType = LexType.Number;
                    Value = number;
                    VarName = "";
                    Coords = new Nodes.Node.Coords(x, y);
                    EndCoords = GetEndCoords(Coords);
                }

                public Lexem(string name)
                {
                    LexType = LexType.Variable;
                    Value = 0;
                    VarName = name;
                    Coords = new Nodes.Node.Coords(x, y);
                    EndCoords = GetEndCoords(Coords);
                }

                public Lexem(int start, int end)
                {
                    LexType = LexType.String;
                    Value = 0;
                    VarName = expression.Substring(start, end - start + 1);
                    Coords = new Nodes.Node.Coords(x, y);
                    EndCoords = GetEndCoords(Coords);
                }
            }


            //{ private set { position = 0; } get{}; }

            private static void MakeLexems()
            {
                List<Lexem> Lexems = new List<Lexem>();
                //int startPos;
                position = 0;
                Lexem result;
                do
                {
                    result = GetLexem();
                    Lexems.Add(result);

                    //startPos = position;
                    /*if (result.LexType == LexType.EOF)
                        break;*/
                    //position++;
                    //PushCoordinates(startPos, position);
                    //result.EndCoords = new Nodes.Node.Coords(x,y);
                    
                    //SkipSpacesCoords();

                } while (result.LexType != LexType.EOF);
                ArrayOfLexems = Lexems.ToArray();
            }

            /*private static void PushCoordinates(int start, int finish)
            {
                for (int i = start; i < finish; i++)
                {
                    if (i < expression.Length && expression[i] == LineFeed)
                    {
                        y++;
                        x = 1;
                    }
                    else
                        if (i < expression.Length && expression[i] == Tab)
                            x += 3;
                        else
                            x++;
                }
            }*/

            public static Lexem LookAhead()
            {
                //int startPos = position;
                /*if (position >= expression.Length)
                {
                    return new Lexem(LexType.EOF);
                }
                Lexem result = GetLexem(false);
                for (int i = startPos; i < position; i++)
                {
                    if (i < expression.Length && expression[i] == '\n')
                    {
                        y++;
                        x = 1;
                    }
                    else
                        x++;
                }
                return result;*/
                /*if (position >= ArrayOfLexems.Length)
                    return new Lexem(LexType.EOF);*/
                return ArrayOfLexems[position];
            }

            public static Lexem RollBack()
            {
                if (position == 0)
                {
                    position++;
                }
                position--;
                //x = ArrayOfLexems[position].Coords.X;
                //y = ArrayOfLexems[position].Coords.Y;
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
                /*if (position >= expression.Length)
                {
                    return new Lexem(LexType.EOF);
                }
                int startPos = position;
                Lexem result = GetLexem(true);
                Lexems.Push(result);
                position++;
                for (int i = startPos; i < position; i++)
                {
                    if (i < expression.Length && expression[i] == LineFeed)
                    {
                        y++;
                        x = 1;
                    }
                    else
                        if (i < expression.Length && expression[i] == Tab)
                            x += 3;
                        else
                            x++;
                }
                return result;*/
                /*if (position >= ArrayOfLexems.Length)
                    return new Lexem(LexType.EOF);*/
                //x = ArrayOfLexems[position].Coords.X;
                //y = ArrayOfLexems[position].Coords.Y;
                /*if (position < ArrayOfLexems.Length - 1)
                    position++;*/
                return (position < ArrayOfLexems.Length - 1) ? ArrayOfLexems[position++] : ArrayOfLexems[position];
            }

            private static Lexem GetLexem(bool goToNext = true)
            {
                if (position >= expression.Length)
                {
                    return new Lexem(LexType.EOF);
                }
                SkipSpaces();
                int start = position;
                Lexem result = default(Lexem);
                switch (expression[position])
                {
                    case Add:
                        result = new Lexem(LexType.Add);
                        break;
                    case Minus:
                        result = new Lexem(LexType.Minus);
                        break;
                    case Multiply:
                        if (position + 1 < expression.Length && expression[position + 1] == Multiply)
                        {
                            position++;
                            result = new Lexem(LexType.Degree);
                        }
                        else
                        {
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
                        if (position + 1 < expression.Length && expression[position + 1] == EqualSign)
                        {
                            position++;
                            result = new Lexem(LexType.Equal);
                        }
                        else
                        {
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
                        position++;
                        if (position < expression.Length && expression[position] == EqualSign)
                        {
                            result = new Lexem(LexType.NotEqual);
                        }
                        else
                        {
                            position--;
                            Parser.ErrorList.Add(new Error(LexerException.IncorrectOperator, new Nodes.Node.Coords(x, y)));
                            result = new Lexem(LexType.Error);
                        }
                        break;
                    case Higher:
                        position++;
                        if (position < expression.Length && expression[position] == EqualSign)
                        {
                            result = new Lexem(LexType.HighEqual);
                        }
                        else
                        {
                            position--;
                            result = new Lexem(LexType.Higher);
                        }
                        break;
                    case Lower:
                        position++;
                        if (position < expression.Length && expression[position] == EqualSign)
                        {
                            result = new Lexem(LexType.LowEqual);
                        }
                        else
                        {
                            position = start;
                            result = new Lexem(LexType.Lower);
                        }
                        break;
                    case Quote:
                        int newPos = position + 1;
                        while (newPos < expression.Length && expression[newPos] != Quote && expression[position] != LineFeed)
                        {
                            newPos++;
                        }
                        result = new Lexem(position + 1, newPos - 1);
                        position = newPos;
                        /*if (goToNext)
                            position = newPos;*/
                        //return res;
                        break;
                    default:
                        if (digits.Contains(expression[position]))
                        {
                            result = new Lexem(GetNumber());
                            break;
                        }
                        /*if (Spaces.Contains(expression[position]))
                        {
                            start = position;
                            SkipSpaces();
                            result = GetLexem(goToNext);
                            return result;
                        }*/
                        if (letters.Contains(expression[position]) || expression[position] == Underline)
                        {
                            result = GetVar();
                            break;
                        }
                        Parser.ErrorList.Add(new Error(LexerException.IncorrectSymbol, new Nodes.Node.Coords(x, y)));
                        position++;
                        result = GetLexem();
                        break;
                }
                position++;
                x += position - start;
                return result;
            }

            private static void SkipSpaces()
            {
                while (position < expression.Length && Spaces.Contains(expression[position]))
                {
                    if (expression[position] == LineFeed)
                    {
                        y++;
                        x = 1;
                    }
                    else
                        if (expression[position] == Tab)
                            x += 3;
                        else
                            x++;
                    position++;
                }
            }

            /*public static void SkipSpacesCoords()
            {
                while (position < expression.Length && Spaces.Contains(expression[position]))
                {
                    if (expression[position] == LineFeed)
                    {
                        y++;
                        x = 1;
                    }
                    else
                        if (expression[position] == Tab)
                            x += 3;
                        else
                            x++;
                    position++;
                }
            }*/

            private static Lexem GetVar()
            {
                //StringBuilder result = new StringBuilder(string.Empty);
                int positionOfVar = position;
                while (positionOfVar < expression.Length && (letters.Contains(expression[positionOfVar]) || digits.Contains(expression[positionOfVar]) || expression[positionOfVar] == Underline))
                {
                    //result.Append(expression[positionOfVar]);
                    positionOfVar++;
                }
                string result = expression.Substring(position, positionOfVar - position);
                position = positionOfVar - 1;
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
                Comma,
                FractionPart,
                Exp,
                Sign,
                Power
            }

            private static float GetNumber(bool goToNext = true)
            {
                int start = position;
                int end = GetEndOfNumber();
                if (!goToNext)
                    position = start;
                float result;
                if (!float.TryParse(expression.Substring(start, end - start + 1), out result))
                {
                    int shift = 0;
                    while (!float.TryParse(expression.Substring(start, end - start + 1 - shift), out result))
                    {
                        shift++;
                    }
                }
                if (goToNext)
                   position = end;
                return result;
            }

            private static int GetEndOfNumber()
            {
                ExponentParts currPart = ExponentParts.IntegerPart;
                while (true)
                {
                    position++;
                    switch (currPart)
                    {
                        case ExponentParts.IntegerPart:
                            if (position >= expression.Length)
                                return position - 1;
                            if (digits.Contains(expression[position]))
                                break;
                            if (expression[position] == Comma)
                            {
                                currPart = ExponentParts.Comma;
                                break;
                            }
                            if (expression[position] == Exp)
                            {
                                currPart = ExponentParts.Exp;
                                break;
                            }
                            return position - 1;
                        case ExponentParts.Comma:
                            if (position >= expression.Length || IsDelimiterNumber(position))
                            {
                                Parser.ErrorList.Add(new Error(LexerException.IncorrectNumber, new Nodes.Node.Coords(x, y)));
                                return position - 1;
                            }
                            if (digits.Contains(expression[position]))
                            {
                                currPart = ExponentParts.FractionPart;
                                break;
                            }
                            Parser.ErrorList.Add(new Error(LexerException.IncorrectNumber, new Nodes.Node.Coords(x, y)));
                            return position;
                        case ExponentParts.FractionPart:
                            if (position >= expression.Length)
                                return position - 1;
                            if (digits.Contains(expression[position]))
                                break;
                            if (expression[position] == Exp)
                            {
                                currPart = ExponentParts.Exp;
                                break;
                            }
                            Parser.ErrorList.Add(new Error(LexerException.IncorrectNumber, new Nodes.Node.Coords(x, y)));
                            return position;
                        case ExponentParts.Exp:
                            if (position >= expression.Length || IsDelimiterNumber(position))
                            {
                                Parser.ErrorList.Add(new Error(LexerException.IncorrectNumber, new Nodes.Node.Coords(x, y)));
                                return position - 1;
                            }
                            if (digits.Contains(expression[position]))
                            {
                                currPart = ExponentParts.Power;
                                break;
                            }
                            if (expression[position] == Add || expression[position] == Minus)
                            {
                                currPart = ExponentParts.Sign;
                                break;
                            }
                            Parser.ErrorList.Add(new Error(LexerException.IncorrectNumber, new Nodes.Node.Coords(x, y)));
                            return position;
                        case ExponentParts.Sign:
                            if (position >= expression.Length)
                            {
                                Parser.ErrorList.Add(new Error(LexerException.IncorrectNumber, new Nodes.Node.Coords(x, y)));
                                return position - 1;
                            }
                            if (digits.Contains(expression[position]))
                            {
                                currPart = ExponentParts.Power;
                                break;
                            }
                            Parser.ErrorList.Add(new Error(LexerException.IncorrectNumber, new Nodes.Node.Coords(x, y)));
                            return position;
                        case ExponentParts.Power:
                            if (position >= expression.Length || IsDelimiterNumber(position))
                                return position - 1;
                            if (digits.Contains(expression[position]))
                                break;
                            Parser.ErrorList.Add(new Error(LexerException.IncorrectNumber, new Nodes.Node.Coords(x, y)));
                            return position;
                    }
                }
            }

            private static bool IsDelimiterNumber(int position)
            {
                return !(digits.Contains(expression[position]) || ExpNotation.Contains(expression[position]));
            }
        }
    }
}
