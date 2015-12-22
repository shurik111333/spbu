using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Interpreter.Nodes
{
    internal class Program : Node
    {
        public readonly Statement FirstStatement;

        public List<Statement> Statements { get; set; }

        public Program(Statement Statement)
        {
            if (Statement == null)
            {
                throw new ArgumentNullException("listOfStatements");
            }
            FirstStatement = Statement;
        }

        public override Value Interpreter()
        {
            Memory.Vars = new Dictionary<string, Value>();
            Memory.Arrays = new Dictionary<string, Dictionary<int, Value>>();
            //Memory.Strings = new Dictionary<string, string>();
            //FirstStatement.Interpreter();
            return new Value();
        }
    }
}
