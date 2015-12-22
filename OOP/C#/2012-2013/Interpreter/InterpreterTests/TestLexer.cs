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
    class TestLexer
    {
        private static bool EqualLexems(Parser.Lexer.Lexem lexem1, Parser.Lexer.Lexem lexem2)
        {
            return (lexem1.LexType == lexem2.LexType && lexem1.Value == lexem2.Value && lexem2.VarName == lexem1.VarName);
        }

        [Test]
        public void Number()
        {
            Parser.Lexer newLexer = new Parser.Lexer("1234  5678\n345\t\t   1,22E-1  22,E 1E+2 1,3");
            Assert.True(EqualLexems(Parser.Lexer.NextLexem(), new Parser.Lexer.Lexem(1234)));
            Assert.True(EqualLexems(Parser.Lexer.NextLexem(), new Parser.Lexer.Lexem(5678)));
            Assert.True(EqualLexems(Parser.Lexer.NextLexem(), new Parser.Lexer.Lexem(345)));
            float result;
            float.TryParse("0,122", out result);
            Assert.AreEqual(Parser.Lexer.NextLexem().Value, result);
            result = 22;
            Assert.AreEqual(Parser.Lexer.NextLexem().Value, result);
            result = 100;
            Assert.AreEqual(Parser.Lexer.NextLexem().Value, result);
            float.TryParse("1,3", out result);
            Assert.AreEqual(Parser.Lexer.NextLexem().Value, result);
        }

        [Test]
        public void Operations()
        {
            Parser.Lexer newLexer = new Parser.Lexer("++\n\t*  / - ** =");
            Assert.AreEqual(Parser.Lexer.NextLexem().LexType, new Parser.Lexer.Lexem(Parser.Lexer.LexType.Add).LexType);
            Assert.True(EqualLexems(Parser.Lexer.NextLexem(), new Parser.Lexer.Lexem(Parser.Lexer.LexType.Add)));
            Assert.True(EqualLexems(Parser.Lexer.NextLexem(), new Parser.Lexer.Lexem(Parser.Lexer.LexType.Multiply)));
            Assert.True(EqualLexems(Parser.Lexer.NextLexem(), new Parser.Lexer.Lexem(Parser.Lexer.LexType.Divide)));
            Assert.True(EqualLexems(Parser.Lexer.NextLexem(), new Parser.Lexer.Lexem(Parser.Lexer.LexType.Minus)));
            Assert.True(EqualLexems(Parser.Lexer.NextLexem(), new Parser.Lexer.Lexem(Parser.Lexer.LexType.Degree)));
            Assert.True(EqualLexems(Parser.Lexer.NextLexem(), new Parser.Lexer.Lexem(Parser.Lexer.LexType.EqualSign)));
        }

        [Test]
        public void Conditions()
        {
            Parser.Lexer newLexer = new Parser.Lexer("<<= == > >= !=");
            Assert.True(EqualLexems(Parser.Lexer.NextLexem(), new Parser.Lexer.Lexem(Parser.Lexer.LexType.Lower)));
            Assert.True(EqualLexems(Parser.Lexer.NextLexem(), new Parser.Lexer.Lexem(Parser.Lexer.LexType.LowEqual)));
            Assert.True(EqualLexems(Parser.Lexer.NextLexem(), new Parser.Lexer.Lexem(Parser.Lexer.LexType.Equal)));
            Assert.True(EqualLexems(Parser.Lexer.NextLexem(), new Parser.Lexer.Lexem(Parser.Lexer.LexType.Higher)));
            Assert.True(EqualLexems(Parser.Lexer.NextLexem(), new Parser.Lexer.Lexem(Parser.Lexer.LexType.HighEqual)));
            Assert.True(EqualLexems(Parser.Lexer.NextLexem(), new Parser.Lexer.Lexem(Parser.Lexer.LexType.NotEqual)));
        }

        [Test]
        public void Brackets()
        {
            Parser.Lexer newLexer = new Parser.Lexer("((  }){");
            Assert.True(EqualLexems(Parser.Lexer.NextLexem(), new Parser.Lexer.Lexem(Parser.Lexer.LexType.OpenBreaket)));
            Assert.True(EqualLexems(Parser.Lexer.NextLexem(), new Parser.Lexer.Lexem(Parser.Lexer.LexType.OpenBreaket)));
            Assert.True(EqualLexems(Parser.Lexer.NextLexem(), new Parser.Lexer.Lexem(Parser.Lexer.LexType.CloseBlockBracket)));
            Assert.True(EqualLexems(Parser.Lexer.NextLexem(), new Parser.Lexer.Lexem(Parser.Lexer.LexType.CloseBracket)));
            Assert.True(EqualLexems(Parser.Lexer.NextLexem(), new Parser.Lexer.Lexem(Parser.Lexer.LexType.OpenBlockBracket)));
        }

        [Test]
        public void Commands()
        {
            Parser.Lexer newLexer = new Parser.Lexer("for else if print");
            Assert.True(EqualLexems(Parser.Lexer.NextLexem(), new Parser.Lexer.Lexem(Parser.Lexer.LexType.For)));
            Assert.True(EqualLexems(Parser.Lexer.NextLexem(), new Parser.Lexer.Lexem(Parser.Lexer.LexType.Else)));
            Assert.True(EqualLexems(Parser.Lexer.NextLexem(), new Parser.Lexer.Lexem(Parser.Lexer.LexType.If)));
            Assert.True(EqualLexems(Parser.Lexer.NextLexem(), new Parser.Lexer.Lexem(Parser.Lexer.LexType.Print)));
        }

        [Test]
        [ExpectedException(typeof(ArgumentNullException))]
        public void NullProgram()
        {
            Parser.Lexer newLexer = new Parser.Lexer(null);
        }
    }
}
