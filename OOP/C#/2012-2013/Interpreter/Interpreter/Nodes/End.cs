using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Interpreter.Nodes
{
    class End : Statement
    {
        //public Statement Next;

        /*public End()
        {
            Next = null;
        }
        */
        public override Value Interpreter()
        {
            /*if (this.Next != null)
                this.Next.Interpreter();*/
            return new Value();
        }
    }
}
