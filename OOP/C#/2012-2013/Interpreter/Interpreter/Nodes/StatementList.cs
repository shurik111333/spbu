using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Interpreter.Nodes
{
    internal class StatementList : Node
    {
        public readonly List<Statement> Statements;

        public StatementList()
        {
            Statements = new List<Statement>();
        }

        public override Value Interpreter()
        {
            foreach (Statement statement in Statements)
            {
                statement.Interpreter();
            }
            return new Value();
        }
    }
}
