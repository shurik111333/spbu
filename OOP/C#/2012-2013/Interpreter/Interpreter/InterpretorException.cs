using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Interpreter
{
    class InterpretorException : Exception
    {
        public readonly Nodes.Node.Coords Coords;
        public readonly string Exception;

        public const string 
            UnknownLabel = "Unknown Label", 
            UnknownVariable = "Unknown variable", 
            IncorrectIndex = "Incorrect index",
            DivByZero = "Division by zero", 
            UnknownBinOper = "Unknown binary operation", 
            IncorrectBinOper = "Incorrect binary operation",
            FloatHaventIndex = "Float variable have not index",
            DiffTypesInExpression = "Different types in expression",
            UnknownCond = "Unknown condition";

        public InterpretorException()
            : base()
        { }

        public InterpretorException(string message)
            : base(message)
        { }

        public InterpretorException(string message, Exception innerException)
            : base(message, innerException)
        { }

        public InterpretorException(string exception, Nodes.Node.Coords coords)
        {
            this.Exception = exception;
            this.Coords = coords;
        }
    }
}
