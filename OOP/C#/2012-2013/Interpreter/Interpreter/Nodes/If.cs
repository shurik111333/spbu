using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Interpreter.Nodes
{
    internal class If : Statement
    {
        public readonly Condition Condition;
        public readonly Statement IfBlock, ElseBlock;

        public If(Condition condition, Statement ifBlock, Statement elseBlock, End end, Node.Coords coords)
        {
            Condition = condition;
            IfBlock = ifBlock;
            ElseBlock = elseBlock;
            Head = condition;
            Tail = end;
            this.Coords = coords;
        }

        public override Value Interpreter()
        {
            /*if (Condition.Interpreter() == Condition.True)
            {
                return IfBlock.Interpreter();
            }
            else
            {
                if (ElseBlock != null)
                {
                    return ElseBlock.Interpreter();
                }
            }*/
            return new Value();
        }
    }
}
