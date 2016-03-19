using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Det
{
    class Lexer
    {
        private string s;
        int i;

        public struct Token
        {
            public Type t;
            public int value;

            public Token(Type t, int v = 0)
            {
                this.t = t;
                value = v;
            }
        }

        public enum Type
        {
            x,
            y,
            a,
            power,
            EOF,
            plus = '+',
            minus = '-'
        }

        public Lexer(string s)
        {
            this.s = s;
            i = 0;
        }

        private void SkipSpaces()
        {
            while (i < s.Length && s[i] == ' ')
                i++;
        }

        private int GetNumber()
        {
            int res = 0;
            while (i < s.Length && s[i] >= '0' && s[i] <= '9')
            {
                res = res * 10 + s[i] - '0';
                i++;
            }
            return res;
        }

        public Token Next()
        {
            SkipSpaces();
            if (i == s.Length)
                return new Token(Type.EOF);
            switch (s[i])
            {
                case '+':
                    i++;
                    return new Token(Type.plus);
                case '-':
                    i++;
                    return new Token(Type.minus);
                case 'x':
                    i++;
                    return new Token(Type.x);
                case 'y':
                    i++;
                    return new Token(Type.y);
                case '^':
                    i++;
                    return new Token(Type.power, GetNumber());
                default:
                    return new Token(Type.a, GetNumber());
            }
        }
    }
}
