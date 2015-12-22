using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Interpreter
{
    class ParserException : Exception
    {
        public const string IncorrectStatement = "Incorrect statement", NeedSemicolon = "Expected semicolon", MissedCloseBracket = ") is missed",
                            MissedOpenBracket = "( is missed", IncorrectCondition = "Condition is incorrect", MissedBlockBracket = "} is missed",
                            IncorrectExpression = "Incorrect expression", NeedStatement = "Expected a correct statement", NeedLabel = "Expected label",
                            NeedCloseSquadBracket = "Expected ]", NeedEqualSign = "= expected";

        public ParserException()
            : base()
        { }
        public ParserException(string message)
            : base(message)
        { }
        public ParserException(string message, Exception innerException)
            : base(message, innerException)
        { }
    }
}
