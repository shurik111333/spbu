﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Interpreter.Nodes
{
    class StringVar : Variable
    {
        public StringVar(string name)
        {
            Name = name;
        }

        public override Value Interpreter()
        {
            try
            {
                return Memory.Vars[Name];
            }
            catch (Exception)
            {
                throw new InterpretorException(InterpretorException.UnknownVariable, this.Coords);
            }
        }
    }
}
