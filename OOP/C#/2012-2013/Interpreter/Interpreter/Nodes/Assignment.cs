using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Interpreter.Nodes
{
    internal class Assignment : Statement
    {
        public readonly Expression Value;
        public readonly Variable Var;
        public readonly ElementOfArray Array;

        public Assignment(Variable var, Nodes.Expression expr, Node.Coords coords)
        {
            Var = var;
            Value = expr;
            Array = null;
            this.Coords = coords;
        }

        public Assignment(ElementOfArray array, Nodes.Expression expr, Node.Coords coords)
        {
            Var = null;
            Value = expr;
            Array = array;
            this.Coords = coords;
        }

        public override Value Interpreter()
        {
            if (Var != null)
                try
                {
                    Memory.Vars[Var.Name] = Value.Interpreter();
                }
                catch (KeyNotFoundException)
                {
                    Memory.Vars.Add(Var.Name, Value.Interpreter());
                    if (Memory.Arrays.ContainsKey(Var.Name))
                        Memory.Arrays.Remove(Var.Name);
                }
            else
            {
                if (ElementOfArray.UncorrectIndex(Array.Index.Interpreter()))
                    throw new InterpretorException(InterpretorException.IncorrectIndex, this.Coords);
                float index = Array.Index.Interpreter().FloatValue;
                try
                {
                    Memory.Arrays[Array.Name][(int)index] = Value.Interpreter();
                }
                catch (KeyNotFoundException)
                {
                    try
                    {
                        Memory.Arrays[Array.Name].Add((int)index, Value.Interpreter());
                    }
                    catch (KeyNotFoundException)
                    {
                        Memory.Arrays.Add(Array.Name, new Dictionary<int,Value>());
                        Memory.Arrays[Array.Name].Add((int)index, Value.Interpreter());
                        if (Memory.Vars.ContainsKey(Array.Name))
                            Memory.Vars.Remove(Array.Name);
                    }
                }
            }
            /*if (this.Next != null)
                this.Next.Interpreter();*/
            return new Value();
        }
    }
}
