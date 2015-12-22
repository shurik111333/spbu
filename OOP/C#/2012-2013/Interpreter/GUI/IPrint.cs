using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GUI
{
    public interface IPrint
    {
        void FormOutput(string tPrint);
    }

    public class Print : IPrint
    {
        public void FormOutput(string tPrint)
        {
            
        }
    }
}
