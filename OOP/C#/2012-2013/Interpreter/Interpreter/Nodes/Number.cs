using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Interpreter.Nodes
{
    internal class Number : Expression
    {
        public readonly float Value;

        public Number(float number)
        {
            Value = number;
        }

        public override Value Interpreter()
        {
            return new Value(Value, Variable.VarType.Float);
        }
    }
}
