using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Interpreter
{
    public class Interpreter
    {
        private static Nodes.Statement currStatement = null;

        public static List<string> Run(string program, ref List<string> errors, ref List<string> watches)
        {
            Nodes.Program Program = Parser.Program(program);
            Program.Interpreter();
            if (Parser.ErrorList.Count == 0)
            {
                try
                {
                    List<string> output = RunProgram(Program.FirstStatement);
                    GetWatches(ref watches);
                    return output;
                }
                catch (InterpretorException interException)
                {
                    errors.Add(string.Format("{0}({1}:{2})", interException.Exception, interException.Coords.Y, interException.Coords.X));
                    return null;
                }
            }
            else
            {
                GetErrors(ref errors);
                watches = null;
                return null;
            }
        }

        public static void
            Compile(string program, ref List<string> errors)
        {
            Parser.Program(program);
            GetErrors(ref errors);
        }

        private static void GetErrors(ref List<string> errors)
        {
            foreach (Parser.Error error in Parser.ErrorList)
            {
                errors.Add(string.Format("{0}({1}:{2})", error.Description, error.Y, error.X));
            }
        }

        private static void GetWatches(ref List<string> watches)
        {
            foreach (string variable in Memory.Vars.Keys)
            {
                if (Memory.Vars[variable].Type == Nodes.Variable.VarType.Float)
                    watches.Add(variable + " = " + Memory.Vars[variable].FloatValue.ToString());
                else
                    watches.Add(variable + " = " + Memory.Vars[variable].StringValue);
            }

            foreach (string variable in Memory.Arrays.Keys)
            {
                foreach (int index in Memory.Arrays[variable].Keys)
                {
                    if (Memory.Arrays[variable][index].Type == Nodes.Variable.VarType.String)
                        watches.Add(string.Format("{0}[{1}] = {2}", variable, index, Memory.Arrays[variable][index].StringValue));
                    else
                        watches.Add(string.Format("{0}[{1}] = {2}", variable, index, Memory.Arrays[variable][index].FloatValue.ToString()));
                }
            }
        }

        private static List<string> RunProgram(Nodes.Statement firstStatement)
        {
            List<string> result = new List<string>();
            while (firstStatement != null)
            {
                if (firstStatement is Nodes.Assignment || firstStatement is Nodes.End || firstStatement is Nodes.GoTo ||
                    firstStatement is Nodes.Condition)
                    firstStatement.Interpreter();
                if (firstStatement is Nodes.Print)
                {
                    Nodes.Variable.Value forPrint = firstStatement.Interpreter();
                    if (forPrint.Type == Nodes.Variable.VarType.String)
                        result.Add(forPrint.StringValue);
                    else
                        result.Add(forPrint.FloatValue.ToString());
                }
                firstStatement = firstStatement.Next;
            }
            return result;
        }

        public static string Debug(string program, ref List<string> errors, ref List<string> watches, ref int flag)
        {
            if (currStatement == null)
            {
                Nodes.Program firstStatement = Parser.Program(program);
                firstStatement.Interpreter();
                currStatement = firstStatement.FirstStatement;
            }
            string result = OneStep(currStatement);
            watches.Clear();
            GetWatches(ref watches);
            if (currStatement == null)
                flag = 1;
            return result;
        }

        internal static string OneStep(Nodes.Statement currStatement)
        {
            string result = null;
            if (currStatement is Nodes.Print)
            {
                result = currStatement.Interpreter().StringValue;

            }
            else
                currStatement.Interpreter();
            currStatement = currStatement.Next;
            return result;
        }
    }
}
