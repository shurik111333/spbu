using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
//using System.Threading.Tasks;

namespace Interpreter
{
    internal sealed partial class Parser
    {
        internal class Lexer
        {
            public const char Add = '+', Minus = '-', Divide = '/', Multiply = '*', OpenBracket = '(', CloseBracket = ')', Space = ' ', Semicolon = ';', EqualSign = '=',
                              Underline = '_', OpenBlockBracket = '{', CloseBlockBracket = '}', Comma = ',', Not = '!', Higher = '>', Lower = '<', Quote = '"', LineFeed = '\n',
                              Tab = '\t', Exp = 'E', Colon = ':', OpenSquadBracket = '[', CloseSquadBracket = ']';

            public const string Degree = "**", Spaces = " \r\n\t", If = "if", Else = "else", For = "for", Print = "print", ExpNotation = "E,+-", While = "while",
                                GoTo = "goto";

            private const string digits = "1234567890", letters = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM";

            private static string expression;

            public static int x { private set; get; }
            public static int y { private set; get; }

            private static int position;

            private static Lexem[] ArrayOfLexems;

            public Lexer(string expr)
            {
                if (expr == null)
                    throw new ArgumentNullException("expr");
                expression = expr;
                x = 1;
                y = 1;
                //Lexems = new Stack<Lexem>();
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
                public int Position;

                public Lexem(LexType type)
                {
                    LexType = type;
                    Value = 0;
                    VarName = "";
                    Coords = new Nodes.Node.Coords(x, y);
                    EndCoords = new Nodes.Node.Coords();
                    Position = position;
                }

                public Lexem(float number)
                {
                    LexType = LexType.Number;
                    Value = number;
                    VarName = "";
                    Coords = new Nodes.Node.Coords(x, y);
                    EndCoords = new Nodes.Node.Coords();
                    Position = position;
                }

                public Lexem(string name)
                {
                    LexType = LexType.Variable;
                    Value = 0;
                    VarName = name;
                    Coords = new Nodes.Node.Coords(x, y);
                    EndCoords = new Nodes.Node.Coords();
                    Position = position;
                }

                public Lexem(int start, int end)
                {
                    LexType = LexType.String;
                    Value = 0;
                    VarName = expression.Substring(start, end - start + 1);
                    Coords = new Nodes.Node.Coords(x, y);
                    EndCoords = new Nodes.Node.Coords();
                    Position = position;
                }
            }


            //{ private set { position = 0; } get{}; }

            private static void MakeLexems()
            {
                List<Lexem> Lexems = new List<Lexem>();
                int startPos;
                position = 0;
                while (true)
                {
                    startPos = position;
                    Lexem result = GetLexem(true);
                    if (result.LexType == LexType.EOF)
                        break;
                    position++;
                    PushCoordinates(startPos, position);
                    result.EndCoords = new Nodes.Node.Coords(x,y);
                    Lexems.Add(result);
                    SkipSpacesCoords();
                }
                ArrayOfLexems = Lexems.ToArray();
            }

            private static void PushCoordinates(int start, int finish)
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
            }

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
                if (position >= ArrayOfLexems.Length)
                    return new Lexem(LexType.EOF);
                return ArrayOfLexems[position];
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
                if (position >= ArrayOfLexems.Length)
                    return new Lexem(LexType.EOF);
                x = ArrayOfLexems[position].Coords.X;
                y = ArrayOfLexems[position].Coords.Y;
                position++;
                return ArrayOfLexems[position - 1];
            }

            private static Lexem GetLexem(bool goToNext)
            {
                if (position >= expression.Length)
                {
                    return new Lexem(LexType.EOF);
                }
                int start;
                Lexem result;
                switch (expression[position])
                {
                    case Add:
                        return new Lexem(LexType.Add);
                    case Minus:
                        return new Lexem(LexType.Minus);
                    case Multiply:
                        start = position;
                        position++;
                        if (position < expression.Length && expression[position] == Multiply)
                        {
                            if (!goToNext)
                                position = start;
                            return new Lexem(LexType.Degree);
                        }
                        else
                        {
                            position = start;
                            return new Lexem(LexType.Multiply);
                        }
                    case Divide:
                        return new Lexem(LexType.Divide);
                    case OpenBracket:
                        return new Lexem(LexType.OpenBreaket);
                    case CloseBracket:
                        return new Lexem(LexType.CloseBracket);
                    case Semicolon:
                        return new Lexem(LexType.Semicolon);
                    case EqualSign:
                        start = position;
                        position++;
                        if (position < expression.Length && expression[position] == EqualSign)
                        {
                            if (!goToNext)
                                position = start;
                            return new Lexem(LexType.Equal);
                        }
                        else
                        {
                            position = start;
                            return new Lexem(LexType.EqualSign);
                        }
                    case OpenBlockBracket:
                        return new Lexem(LexType.OpenBlockBracket);
                    case CloseBlockBracket:
                        return new Lexem(LexType.CloseBlockBracket);
                    case OpenSquadBracket:
                        return new Lexem(LexType.OpenSquadBracket);
                    case CloseSquadBracket:
                        return new Lexem(LexType.CloseSquadBracket);
                    case Colon:
                        return new Lexem(LexType.Colon);
                    case Not:
                        start = position;
                        position++;
                        if (position < expression.Length && expression[position] == EqualSign)
                        {
                            if (!goToNext)
                                position = start;
                            return new Lexem(LexType.NotEqual);
                        }
                        else
                        {
                            position = start;
                            Parser.ErrorList.Add(new Error(LexerException.IncorrectOperator, new Nodes.Node.Coords(x, y)));
                            return new Lexem(LexType.Error);
                        }
                    case Higher:
                        start = position;
                        position++;
                        if (position < expression.Length && expression[position] == EqualSign)
                        {
                            if (!goToNext)
                                position = start;
                            return new Lexem(LexType.HighEqual);
                        }
                        else
                        {
                            position--;
                            return new Lexem(LexType.Higher);
                        }
                    case Lower:
                        start = position;
                        position++;
                        if (position < expression.Length && expression[position] == EqualSign)
                        {
                            if (!goToNext)
                                position = start;
                            return new Lexem(LexType.LowEqual);
                        }
                        else
                        {
                            position = start;
                            return new Lexem(LexType.Lower);
                        }
                    case Quote:
                        int newPos = position + 1;
                        while (newPos < expression.Length && expression[newPos] != Quote)
                        {
                            newPos++;
                        }
                        Lexem res = new Lexem(position + 1, newPos - 1);
                        if (goToNext)
                            position = newPos;
                        return res;
                    default:
                        if (digits.Contains(expression[position]))
                        {
                            return new Lexem(GetNumber(goToNext));
                        }
                        if (Spaces.Contains(expression[position]))
                        {
                            start = position;
                            SkipSpaces();
                            result = GetLexem(goToNext);
                            if (!goToNext)
                                position = start;
                            return result;
                        }
                        if (letters.Contains(expression[position]) || expression[position] == Underline)
                        {
                            return GetVar(goToNext);
                        }
                        if (goToNext)
                            Parser.ErrorList.Add(new Error(LexerException.IncorrectSymbol, new Nodes.Node.Coords(x, y)));
                        start = position;
                        position++;
                        result = GetLexem(goToNext);
                        if (!goToNext)
                            position = start;
                        return result;
                }
            }

            public static void SkipSpaces()
            {
                while (position < expression.Length && Spaces.Contains(expression[position]))
                {
                    position++;
                }
            }

            public static void SkipSpacesCoords()
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

            private static Lexem GetVar(bool goToNext)
            {
                StringBuilder result = new StringBuilder(string.Empty);
                int positionOfVar = position;
                while (positionOfVar < expression.Length && (letters.Contains(expression[positionOfVar]) || digits.Contains(expression[positionOfVar]) || expression[positionOfVar] == Underline))
                {
                    result.Append(expression[positionOfVar]);
                    positionOfVar++;
                }
                if (goToNext)
                    position = positionOfVar - 1;
                switch (result.ToString())
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
                        return new Lexem(result.ToString());
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

            private static float GetNumber(bool goToNext)
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

            public static Lexem RollBack()
            {
                if (position == 0)
                {
                    position++;
                }
                position--;
                x = ArrayOfLexems[position].Coords.X;
                y = ArrayOfLexems[position].Coords.Y;
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
        }
    }
}
