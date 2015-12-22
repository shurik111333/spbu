using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Interpreter.Nodes
{
    internal class Variable : Expression
    {
        public string Name {get; set;}

        public Variable()
        { }

        public enum VarType
        {
            Float,
            String,
            ArrayFloat,
            ArrayString
        }

        internal Variable(string name)
        {
            if (name == null)
            {
                throw new ArgumentNullException("name");
            }
            
            Name = name;
        }

        public override Value Interpreter()
        {
            return Memory.Vars[Name];
        }
    }
}
