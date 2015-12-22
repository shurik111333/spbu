using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Interpreter.Nodes
{
    abstract class Node
    {
        public abstract Value Interpreter();

        public struct Value
        {
            public readonly float FloatValue;
            public readonly string StringValue;
            public readonly Variable.VarType Type;

            public Value(float value, Variable.VarType type)
            {
                FloatValue = value;
                Type = type;
                StringValue = string.Empty;
            }

            public Value(string value, Variable.VarType type)
            {
                FloatValue = float.NaN;
                Type = type;
                StringValue = value;
            }
        }

        public struct Coords
        {
            public readonly int X;
            public readonly int Y;

            public Coords(int x, int y)
            {
                X = x;
                Y = y;
            }
        }
    }
}
