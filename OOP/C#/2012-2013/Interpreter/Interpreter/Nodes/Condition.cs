using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Interpreter.Nodes
{
    internal sealed class Condition : Statement
    {
        public readonly CompareSign Compare;
        public readonly Expression Left, Right;

        public const float True = 1, False = 0;

        public Statement NextTrue, NextFalse;

        public enum CompareSign
        {
            Equal,
            Higher,
            Lower,
            LowEqual,
            HighEqual,
            NotEqual,
            Error
        }

        public Condition(Expression left, CompareSign compare, Expression right)
        {
            Compare = compare;
            Left = left;
            Right = right;
            NextTrue = null; 
            NextFalse = null;
        }

        public override Value Interpreter()
        {
            float result;
            switch (Compare)
            {
                case CompareSign.Equal:
                    if (Left.Interpreter().FloatValue == Right.Interpreter().FloatValue)
                        result = True;
                    else
                        result = False;
                    break;
                case CompareSign.HighEqual:
                    if (Left.Interpreter().FloatValue >= Right.Interpreter().FloatValue)
                        result = True;
                    else
                        result = False;
                    break;
                case CompareSign.Higher:
                    if (Left.Interpreter().FloatValue > Right.Interpreter().FloatValue)
                        result = True;
                    else
                        result = False;
                    break;
                case CompareSign.LowEqual:
                    if (Left.Interpreter().FloatValue <= Right.Interpreter().FloatValue)
                        result = True;
                    else
                        result = False;
                    break;
                case CompareSign.Lower:
                    if (Left.Interpreter().FloatValue < Right.Interpreter().FloatValue)
                        result = True;
                    else
                        result = False;
                    break;
                case CompareSign.NotEqual:
                    if (Left.Interpreter().FloatValue != Right.Interpreter().FloatValue)
                        result = True;
                    else
                        result = False;
                    break;
                default:
                    throw new InterpretorException(InterpretorException.UnknownCond, this.Coords);
            }

            if (result == True)
                this.Next = NextTrue;
            else
                this.Next = NextFalse;
            return new Value();
        }
    }
}
