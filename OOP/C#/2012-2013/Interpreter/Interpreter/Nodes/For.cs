using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Interpreter.Nodes
{
    internal class For : Statement
    {
        public readonly Assignment Assignment, ChngAssignment;
        public readonly Condition Condition;
        public readonly Statement FirstStatement;

        public For(Assignment assn, Condition cond, Assignment chngAssn, Statement first, End end, Node.Coords coords)
        {
            Assignment = assn;
            Condition = cond;
            ChngAssignment = chngAssn;
            FirstStatement = first;
            Head = assn;
            Tail = end;
            this.Coords = coords;
        }

        public override Value Interpreter()
        {
            /*Assignment.Interpreter();
            while (Condition.Interpreter() == Condition.True)
            {
                Block.Interpreter();
                ChngAssignment.Interpreter();
            }*/
            return new Value();
        }
    }
}
