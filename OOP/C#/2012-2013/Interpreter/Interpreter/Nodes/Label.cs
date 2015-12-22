using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Interpreter.Nodes
{
    class Label : Statement
    {
        public readonly string Name;
        public readonly Statement Statement;

        public Label(string name, Statement statement)
        {
            Name = name;
            Statement = statement;
        }

        public override Value Interpreter()
        {
            //Statement.Head.Interpreter();
            this.Next = Statement.Head;
            return new Value();
        }
    }
}
