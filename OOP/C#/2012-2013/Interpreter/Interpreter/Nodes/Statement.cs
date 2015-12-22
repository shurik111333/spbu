using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Interpreter.Nodes
{
    internal class Statement : Node
    {
        public Statement Next { set; get; }
        public Statement Head { set; get; }
        public Statement Tail { set; get; }

        public Node.Coords Coords { set; get; }

        public Statement()
        {
            Next = null;
        }

        public override Value Interpreter()
        {
            return new Value();
        }
    }
}
