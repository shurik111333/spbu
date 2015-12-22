using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Interpreter.Nodes
{
    internal class Block : Node
    {
        public List<Statement> StatementList { get; set;}

        public Block()
        {
            StatementList = new List<Statement>();
        }

        public override Value Interpreter()
        {
            foreach (Statement statement in StatementList)
            {
                statement.Interpreter();
            }
            return new Value();
        }
    }
}
