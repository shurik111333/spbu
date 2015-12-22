using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Interpreter.Nodes
{
    internal class Print : Statement
    {
        public readonly string OutString;
        public readonly Expression OutExpr;
        public readonly IPrint PrintInterface;

        public Print(string outString, IPrint printer)
        {
            OutString = outString;
            OutExpr = null;
            PrintInterface = printer;
        }

        public Print(Expression outExpr, IPrint printer)
        {
            OutExpr = outExpr;
            OutString = null;
            PrintInterface = printer;
        }

        public override Value Interpreter()
        {
            Value forPrint;
            if (OutExpr == null)
                forPrint = new Value(OutString, Variable.VarType.String);
            //PrintInterface.ConsolePrint(String.Format(OutString));
            else
            {
                forPrint = OutExpr.Interpreter();
                /*if (forPrint.Type == Variable.VarType.String || forPrint.Type == Variable.VarType.ArrayString)
                    PrintInterface.ConsolePrint(forPrint.StringValue);
                else
                    PrintInterface.ConsolePrint(forPrint.FloatValue.ToString());*/
            }

            /*if (this.Next != null)
                this.Next.Interpreter();*/
            return forPrint;
        }
    }
}
