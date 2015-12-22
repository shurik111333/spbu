using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Interpreter
{
    class Memory
    {
        public static Dictionary<string, Nodes.Node.Value> Vars { get; set; }
        public static Dictionary<string, Dictionary<int, Nodes.Node.Value>> Arrays { get; set; }
        //public static Dictionary<string, string> Strings { get; set; }
        public static Dictionary<string, Nodes.Statement> Labels { get; set; }
    }

}
