using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;

namespace GUI
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void richTextBoxProgram_TextChanged(object sender, EventArgs e)
        {
            toolStripStatusLabel1.Text = string.Empty;
        }

        private void toolStripMenuItem9_Click(object sender, EventArgs e)
        {
            richTextBoxOutput.Clear();
            richTextBoxWatches.Clear();
            richTextBoxErrors.Clear();
            List<string> errors = new List<string>();
            List<string> watches = new List<string>();
            List<string> output = new List<string>();
                output = Interpreter.Interpreter.Run(richTextBoxProgram.Text, ref errors, ref watches);
            if (errors.Count == 0)
            {
                foreach (string outputString in output)
                {
                    richTextBoxOutput.AppendText(outputString + "\n");
                }
                foreach (string variable in watches)
                {
                    richTextBoxWatches.AppendText(variable + "\n");
                }
                toolStripStatusLabel1.Text = "Done";
            }
            else
            {
                WriteErrors(errors);
                toolStripStatusLabel1.Text = "Errors in project";
            }
            
        }

        private void toolStripMenuItem1_Click(object sender, EventArgs e)
        {

        }

        private void toolStripMenuItem3_Click(object sender, EventArgs e)
        {
            MessageBoxButtons buttons = MessageBoxButtons.YesNoCancel;
            MessageBoxIcon icon = MessageBoxIcon.Question;
            string textBox = "Do you want to save changes?";
            string caption = "Save changes";
            DialogResult exitDialog = MessageBox.Show(textBox, caption, buttons, icon);

            switch (exitDialog)
            {
                case System.Windows.Forms.DialogResult.Yes:
                    SaveFileDialog saveDialog = new SaveFileDialog();
                    saveDialog.FileName = "Project";
                    saveDialog.DefaultExt = ".txt";
                    saveDialog.Filter = "Text Files |*.txt";

                    if (saveDialog.ShowDialog() == System.Windows.Forms.DialogResult.OK)
                    {
                        string filename = saveDialog.FileName;
                        File.WriteAllText(filename, richTextBoxProgram.Text);
                    }
                    else
                        break;
                    richTextBoxProgram.Clear();
                    break;
                case System.Windows.Forms.DialogResult.No:
                    richTextBoxProgram.Clear();
                    break;
            }
        }

        private void toolStripMenuItem4_Click(object sender, EventArgs e)
        {
            OpenFileDialog dialog = new OpenFileDialog();
            dialog.DefaultExt = ".txt";
            dialog.Filter = "Text Files |*.txt";
            if (dialog.ShowDialog() == System.Windows.Forms.DialogResult.OK)
            {
                string filename = dialog.FileName;
                richTextBoxProgram.Text = File.ReadAllText(filename);
            }
        }

        private void toolStripMenuItem5_Click(object sender, EventArgs e)
        {
            SaveFileDialog dialog = new SaveFileDialog();
            dialog.FileName = "Project";
            dialog.DefaultExt = ".txt";
            dialog.Filter = "Text Files |*.txt";
            if (dialog.ShowDialog() == System.Windows.Forms.DialogResult.OK)
            {
                string filename = dialog.FileName;
                File.WriteAllText(filename, richTextBoxProgram.Text);
            }
        }

        private void Exit()
        {
            MessageBoxButtons buttons = MessageBoxButtons.YesNoCancel;
            MessageBoxIcon icon = MessageBoxIcon.Question;
            string textBox = "Do you want to save changes?";
            string caption = "Save changes";
            DialogResult exitDialog = MessageBox.Show(textBox, caption, buttons, icon);

            switch (exitDialog)
            {
                case System.Windows.Forms.DialogResult.Yes:
                    SaveFileDialog saveDialog = new SaveFileDialog();
                    saveDialog.FileName = "Project";
                    saveDialog.DefaultExt = ".txt";
                    saveDialog.Filter = "Text Files |*.txt";

                    if (saveDialog.ShowDialog() == System.Windows.Forms.DialogResult.OK)
                    {
                        string filename = saveDialog.FileName;
                        File.WriteAllText(filename, richTextBoxProgram.Text);
                    }
                    else
                        break;
                    Application.Exit();
                    break;
                case System.Windows.Forms.DialogResult.No:
                    Application.Exit();
                    break;
            }
        }

        private void toolStripMenuItem7_Click(object sender, EventArgs e)
        {
            Exit();
        }

        private void WriteErrors(List<string> errors)
        {
            foreach (string error in errors)
            {
                richTextBoxErrors.AppendText(error + "\n");
            }
        }

        private void toolStripMenuItem10_Click(object sender, EventArgs e)
        {
            List<string> errors = new List<string>();
            Interpreter.Interpreter.Compile(richTextBoxProgram.Text, ref errors);
            if (errors.Count == 0)
                toolStripStatusLabel1.Text = "Done";
            else
            {
                toolStripStatusLabel1.Text = "Compile-time errors occurred";
                WriteErrors(errors);
            }

        }

        
        private void debugToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (flag == 0)
            {
                string result;
                result = Interpreter.Interpreter.Debug(richTextBoxProgram.Text, ref errors, ref watches, ref flag);
                if (flag == 1)
                {
                    errors = new List<string>();
                    watches = new List<string>();
                    flag = 0;
                }
                else
                {
                    if (result != null)
                        richTextBoxOutput.AppendText(result + "\n");
                    richTextBoxWatches.Clear();
                    WriteErrors(watches);
                }
            }
        }

        private static int flag = 0;
        private static List<string> errors = new List<string>();
        private static List<string> watches = new List<string>();

        private void toolStripMenuItem11_Click(object sender, EventArgs e)
        {
            
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void statusStrip1_ItemClicked(object sender, ToolStripItemClickedEventArgs e)
        {

        }

        private void toolStripStatusLabel1_Click(object sender, EventArgs e)
        {

        }

        private void toolStripMenuItem2_Click(object sender, EventArgs e)
        {

        }
    }
}
