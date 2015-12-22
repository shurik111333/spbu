using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Interpreter.Nodes
{
    class ElementOfArray : Variable
    {
        public readonly Expression Index;

        public ElementOfArray(string name, Expression index)
        {
            Name = name;
            Index = index;
        }

        public static bool UncorrectIndex(Value index)
        {
            return (index.Type == VarType.String || index.Type == VarType.Float && index.FloatValue != (int)index.FloatValue);
        }

        public override Value Interpreter()
        {
            Value index = Index.Interpreter();
            if (UncorrectIndex(index))
                throw new InterpretorException(InterpretorException.IncorrectIndex, this.Coords);

            if (Memory.Vars.ContainsKey(Name))
            {
                if (Memory.Vars[Name].Type == VarType.String)
                {
                    if (index.FloatValue < 0 || index.FloatValue > Memory.Vars[Name].StringValue.Length - 1)
                        throw new InterpretorException(InterpretorException.IncorrectIndex);
                    return new Value(Memory.Vars[Name].StringValue[(int)index.FloatValue].ToString(), VarType.String);
                }
                else
                    throw new InterpretorException(InterpretorException.FloatHaventIndex, this.Coords);
            }
            else
                if (Memory.Arrays.ContainsKey(Name))
                {
                    if (Memory.Arrays[Name].ContainsKey((int)index.FloatValue))
                    {
                        return Memory.Arrays[Name][(int)index.FloatValue];
                    }
                    else
                        throw new InterpretorException(InterpretorException.IncorrectIndex, this.Coords);
                }
                else
                    throw new InterpretorException(InterpretorException.UnknownVariable, this.Coords);
            /*try
            {
                return new Value(Memory.Arrays[Name][(int)index.FloatValue].FloatValue, VarType.ArrayFloat);
            }
            catch (KeyNotFoundException)
            {
                if (!Memory.Arrays.ContainsKey(Name))
                    throw new InterpretorException(InterpretorException.UnknownVariable);
                else
                    throw new InterpretorException(InterpretorException.IncorrectIndex);
            }*/
        }
    }
}
