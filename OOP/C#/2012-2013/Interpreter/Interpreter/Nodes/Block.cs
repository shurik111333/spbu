using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Interpreter.Nodes
{
    internal class Block : Node
    {
        //public List<Statement> StatementList { get; set;}
        public Statement First;
        public Statement Last;

        public Block()
        {
            First = new Statement();
            Last = First;
            First.Head = First;
            First.Tail = First;
        }

        public Block(Statement first)
        {
            First = first;
            Last = first;
        }

        public Block(Statement first, Statement last)
        {
            //StatementList = new List<Statement>();
            First = first;
            Last = last;
        }

        public override Value Interpreter()
        {
            /*foreach (Statement statement in StatementList)
            {
                statement.Interpreter();
            }*/
            //First.Interpreter();
            return new Value();
        }
    }
}
