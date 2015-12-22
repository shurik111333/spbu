using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using NUnit.Framework;
using Interpreter;

namespace InterpreterTests
{
    [TestFixture]
    class TestInterpreter
    {
        [Test]
        public void TestAssignment()
        {
            string input = "a = 5**2*3 - (4/2 + 1)";
            Interpreter.Nodes.Node result = Interpreter.Parser.Program(input);
            result.Interpreter();
            Assert.AreEqual(Interpreter.Memory.Vars["a"], 72);
        }

        [Test]
        public void TestIf()
        {
            string input = "if (2**2 < 3) {a = 0;} else a = 1;";
            Interpreter.Nodes.Node result = Interpreter.Parser.Program(input);
            result.Interpreter();
            Assert.AreEqual(Interpreter.Memory.Vars["a"], 1);
            input = "if (2**2 <= 3) {a = 0;} else a = 1;";
            result = Interpreter.Parser.Program(input);
            result.Interpreter();
            Assert.AreEqual(Interpreter.Memory.Vars["a"], 1);
            input = "if (2**2 > 3) {a = 0;} else a = 1;";
            result = Interpreter.Parser.Program(input);
            result.Interpreter();
            Assert.AreEqual(Interpreter.Memory.Vars["a"], 0);
            input = "if (2**2 >= 3) {a = 0;} else a = 1;";
            result = Interpreter.Parser.Program(input);
            result.Interpreter();
            Assert.AreEqual(Interpreter.Memory.Vars["a"], 0);
            input = "if (2**2 == 3) {a = 0;} else a = 1;";
            result = Interpreter.Parser.Program(input);
            result.Interpreter();
            Assert.AreEqual(Interpreter.Memory.Vars["a"], 1);
            input = "if (2**2 != 3) {a = 0;} else a = 1;";
            result = Interpreter.Parser.Program(input);
            result.Interpreter();
            Assert.AreEqual(Interpreter.Memory.Vars["a"], 0);
        }

        [Test]
        public void TestFor()
        {
            string input = "a = 1; for (i = 1; i < 7; i = i+1) {a = a*2;}";
            Interpreter.Nodes.Node result = Interpreter.Parser.Program(input);
            result.Interpreter();
            Assert.AreEqual(Interpreter.Memory.Vars["a"], 64);
        }

        [Test]
        public void TestPrint()
        {
            string input = "print(\"Hello, World!\");";
            Interpreter.Nodes.Node result = Interpreter.Parser.Program(input);
            result.Interpreter();
        }

        [Test]
        [ExpectedException(typeof(Interpreter.InterpretorException))]
        public void DivideByZero()
        {
            string input = "a = 2**5 - 12-20; b = 100/a;";
            Interpreter.Nodes.Node result = Interpreter.Parser.Program(input);
            result.Interpreter();
            Console.WriteLine(Interpreter.Memory.Vars["a"]);
            Console.WriteLine(Interpreter.Memory.Vars["b"]);
        }
    }
}
