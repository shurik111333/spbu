using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Interpreter.Nodes
{
    internal class BinaryOperation : Expression
    {
        internal enum TypeOfOperations
        {
            Add,
            Minus,
            Multiply,
            Division,
            Degree
        }

        public readonly TypeOfOperations Operation;
        public readonly Expression Left, Right;

        public BinaryOperation(TypeOfOperations operation, Expression left, Expression right)
        {
            if (left == null)
            {
                throw new ArgumentNullException("left");
            }
            if (right == null)
            {
                throw new ArgumentNullException("right");
            }
            Left = left;
            Right = right;
            Operation = operation;
        }

        public override Value Interpreter()
        {
            Value left = Left.Interpreter(), right = Right.Interpreter();
            if (left.Type == Variable.VarType.Float && right.Type == Variable.VarType.Float)
            {
                switch (Operation)
                {
                    case TypeOfOperations.Add:
                        return new Value(left.FloatValue + right.FloatValue, Variable.VarType.Float);
                    case TypeOfOperations.Minus:
                        return new Value(left.FloatValue - right.FloatValue, Variable.VarType.Float);
                    case TypeOfOperations.Division:
                        if (right.FloatValue == 0)
                        {
                            throw new InterpretorException(InterpretorException.DivByZero, this.Coords);
                        }
                        return new Value(left.FloatValue / right.FloatValue, Variable.VarType.Float);
                    case TypeOfOperations.Multiply:
                        return new Value(left.FloatValue * right.FloatValue, Variable.VarType.Float);
                    case TypeOfOperations.Degree:
                        return new Value((float)Math.Pow(left.FloatValue, right.FloatValue), Variable.VarType.Float);
                    default:
                        throw new InterpretorException(InterpretorException.UnknownBinOper, this.Coords);
                }
            }
            else
                if (left.Type == Variable.VarType.String && right.Type == Variable.VarType.String)
                {
                    switch (Operation)
                    {
                        case TypeOfOperations.Add:
                            return new Value(left.StringValue + right.StringValue, Variable.VarType.String);
                        default:
                            throw new InterpretorException(InterpretorException.IncorrectBinOper, this.Coords);
                    }
                }
                else
                    throw new InterpretorException(InterpretorException.DiffTypesInExpression, this.Coords);
        }
    }
}
