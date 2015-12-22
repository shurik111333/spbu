using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Interpreter.Nodes
{
    internal class Expression : Node
    {
        public Node.Coords Coords { set; get; }

        public override Value Interpreter()
        {
            return new Value();
        }
    }
}
