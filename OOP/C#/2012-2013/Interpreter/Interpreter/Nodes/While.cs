using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Interpreter.Nodes
{
    class While : Statement
    {
        public readonly Nodes.Condition Condition;
        public readonly Nodes.Statement FirstStatement;

        public While(Condition condition, Statement first, End end)
        {
            Condition = condition;
            FirstStatement = first;
            Head = condition;
            Tail = end;
        }

        public override Value Interpreter()
        {
            return new Value();
        }
    }
}
