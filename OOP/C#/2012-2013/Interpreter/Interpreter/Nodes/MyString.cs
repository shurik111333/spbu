using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Interpreter.Nodes
{
    class MyString : Expression
    {
        public readonly string Value;

        public MyString(string value)
        {
            Value = value;
        }

        public override Node.Value Interpreter()
        {
            return new Value(this.Value, Variable.VarType.String);
        }
    }
}
