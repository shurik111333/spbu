using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Interpreter.Nodes
{
    class GoTo : Statement
    {
        public readonly string Label;

        public GoTo(string label)
        {
            Label = label;
        }

        public override Value Interpreter()
        {
            try
            {
                //Memory.Labels[Label].Head.Interpreter();
                this.Next = Memory.Labels[Label].Head;
            }
            catch (Exception)
            {
                throw new InterpretorException(InterpretorException.UnknownLabel, this.Coords);
            }
            return new Value();
        }
    }
}
