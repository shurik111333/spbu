using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Interpreter
{
    class LexerException : Exception
    {
        public const string IncorrectSymbol = "Incorrect symbol", IncorrectStatement = "Incorrect statement", IncorrectOperator = "Incorrect operator",
                            IncorrectNumber = "Incorrect number", ImpossibleRollBack = "Impossible do a RollBack";

        public LexerException()
            : base()
        { }

        public LexerException(string message)
            : base(message)
        { }

        public LexerException(string message, Exception innerException)
            : base(message, innerException)
        { }
    }
}
