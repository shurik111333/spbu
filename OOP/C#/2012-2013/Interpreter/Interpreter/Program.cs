using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
//using System.Threading.Tasks;
using System.IO;

namespace Interpreter
{
    class Program
    {
        static void Main(string[] args)
        {
            string forRead = "";
            StreamReader streamReader = new StreamReader(@"input.txt");
            forRead = streamReader.ReadToEnd();
            List<string> errors = new List<string>();
            List<string> watches = new List<string>();
            List<string> output = Interpreter.Run(forRead,ref errors,ref watches);
            foreach (string outp in output)
            {
                Console.WriteLine(outp);
            }
            /*Nodes.Node result = Parser.Program(forRead);
            if (Parser.ErrorList.Count == 0)
            {
                result.Interpreter();
                Console.WriteLine();
                if (Memory.Vars.Count > 0)
                {
                    Console.WriteLine("Список переменных:");
                    foreach (string variable in Memory.Vars.Keys)
                    {
                        Console.WriteLine("{0} = {1}; {2}", variable, Memory.Vars[variable].FloatValue.ToString(), Memory.Vars[variable].StringValue);
                    }
                }
                else
                    Console.WriteLine("Переменных нет");
                Console.WriteLine();
                if (Memory.Arrays.Count > 0)
                {
                    Console.WriteLine("Массивы:");
                    foreach (string name in Memory.Arrays.Keys)
                    {
                        foreach (int index in Memory.Arrays[name].Keys)
                        {
                            Console.WriteLine("{0}[{1}] = {2}", name, index, Memory.Arrays[name][index]);
                        }
                    }
                }
                else
                    Console.WriteLine("Массивов нет");
            }
            else
            {
                foreach (Parser.Error error in Parser.ErrorList)
                {
                    Console.WriteLine("{0}, line {1}, column {2}", error.Description, error.Y, error.X);
                }
            }*/
            //Parser.Lexer lexer = new Parser.Lexer("1,22E-1");
            //Console.WriteLine(Parser.Lexer.NextLexem().Value);
            /*Console.WriteLine(Parser.Lexer.NextLexem().Value);
            Console.WriteLine(Parser.Lexer.NextLexem().Value);
            Console.WriteLine(Parser.Lexer.NextLexem().Value);*/

            //Console.WriteLine();
            Console.ReadKey();
        }
    }
}
