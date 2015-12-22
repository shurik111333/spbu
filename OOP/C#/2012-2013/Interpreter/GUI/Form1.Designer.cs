namespace GUI
{
    partial class Form1
    {
        /// <summary>
        /// Требуется переменная конструктора.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Освободить все используемые ресурсы.
        /// </summary>
        /// <param name="disposing">истинно, если управляемый ресурс должен быть удален; иначе ложно.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Код, автоматически созданный конструктором форм Windows

        /// <summary>
        /// Обязательный метод для поддержки конструктора - не изменяйте
        /// содержимое данного метода при помощи редактора кода.
        /// </summary>
        private void InitializeComponent()
        {
            this.menuStrip2 = new System.Windows.Forms.MenuStrip();
            this.toolStripMenuItem1 = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripMenuItem3 = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripMenuItem4 = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripMenuItem5 = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator2 = new System.Windows.Forms.ToolStripSeparator();
            this.toolStripMenuItem7 = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripMenuItem2 = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripMenuItem9 = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripMenuItem10 = new System.Windows.Forms.ToolStripMenuItem();
            this.debugToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripMenuItem11 = new System.Windows.Forms.ToolStripMenuItem();
            this.tabControlOutput = new System.Windows.Forms.TabControl();
            this.tabPage3 = new System.Windows.Forms.TabPage();
            this.richTextBoxOutput = new System.Windows.Forms.RichTextBox();
            this.tabPageErrors = new System.Windows.Forms.TabPage();
            this.richTextBoxErrors = new System.Windows.Forms.RichTextBox();
            this.tabPageWatches = new System.Windows.Forms.TabPage();
            this.richTextBoxWatches = new System.Windows.Forms.RichTextBox();
            this.richTextBoxProgram = new System.Windows.Forms.RichTextBox();
            this.statusStrip1 = new System.Windows.Forms.StatusStrip();
            this.toolStripStatusLabel1 = new System.Windows.Forms.ToolStripStatusLabel();
            this.menuStrip2.SuspendLayout();
            this.tabControlOutput.SuspendLayout();
            this.tabPage3.SuspendLayout();
            this.tabPageErrors.SuspendLayout();
            this.tabPageWatches.SuspendLayout();
            this.statusStrip1.SuspendLayout();
            this.SuspendLayout();
            // 
            // menuStrip2
            // 
            this.menuStrip2.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.toolStripMenuItem1,
            this.toolStripMenuItem2});
            this.menuStrip2.Location = new System.Drawing.Point(0, 0);
            this.menuStrip2.Name = "menuStrip2";
            this.menuStrip2.Size = new System.Drawing.Size(922, 24);
            this.menuStrip2.TabIndex = 0;
            this.menuStrip2.Text = "menuStrip2";
            // 
            // toolStripMenuItem1
            // 
            this.toolStripMenuItem1.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.toolStripMenuItem3,
            this.toolStripMenuItem4,
            this.toolStripMenuItem5,
            this.toolStripSeparator2,
            this.toolStripMenuItem7});
            this.toolStripMenuItem1.Name = "toolStripMenuItem1";
            this.toolStripMenuItem1.Size = new System.Drawing.Size(37, 20);
            this.toolStripMenuItem1.Text = "File";
            this.toolStripMenuItem1.Click += new System.EventHandler(this.toolStripMenuItem1_Click);
            // 
            // toolStripMenuItem3
            // 
            this.toolStripMenuItem3.Name = "toolStripMenuItem3";
            this.toolStripMenuItem3.Size = new System.Drawing.Size(103, 22);
            this.toolStripMenuItem3.Text = "New";
            this.toolStripMenuItem3.Click += new System.EventHandler(this.toolStripMenuItem3_Click);
            // 
            // toolStripMenuItem4
            // 
            this.toolStripMenuItem4.Name = "toolStripMenuItem4";
            this.toolStripMenuItem4.Size = new System.Drawing.Size(103, 22);
            this.toolStripMenuItem4.Text = "Open";
            this.toolStripMenuItem4.Click += new System.EventHandler(this.toolStripMenuItem4_Click);
            // 
            // toolStripMenuItem5
            // 
            this.toolStripMenuItem5.Name = "toolStripMenuItem5";
            this.toolStripMenuItem5.Size = new System.Drawing.Size(103, 22);
            this.toolStripMenuItem5.Text = "Save";
            this.toolStripMenuItem5.Click += new System.EventHandler(this.toolStripMenuItem5_Click);
            // 
            // toolStripSeparator2
            // 
            this.toolStripSeparator2.Name = "toolStripSeparator2";
            this.toolStripSeparator2.Size = new System.Drawing.Size(100, 6);
            // 
            // toolStripMenuItem7
            // 
            this.toolStripMenuItem7.Name = "toolStripMenuItem7";
            this.toolStripMenuItem7.Size = new System.Drawing.Size(103, 22);
            this.toolStripMenuItem7.Text = "Exit";
            this.toolStripMenuItem7.Click += new System.EventHandler(this.toolStripMenuItem7_Click);
            // 
            // toolStripMenuItem2
            // 
            this.toolStripMenuItem2.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.toolStripMenuItem9,
            this.toolStripMenuItem10,
            this.debugToolStripMenuItem,
            this.toolStripMenuItem11});
            this.toolStripMenuItem2.Name = "toolStripMenuItem2";
            this.toolStripMenuItem2.Size = new System.Drawing.Size(56, 20);
            this.toolStripMenuItem2.Text = "Project";
            this.toolStripMenuItem2.Click += new System.EventHandler(this.toolStripMenuItem2_Click);
            // 
            // toolStripMenuItem9
            // 
            this.toolStripMenuItem9.Name = "toolStripMenuItem9";
            this.toolStripMenuItem9.Size = new System.Drawing.Size(152, 22);
            this.toolStripMenuItem9.Text = "Run";
            this.toolStripMenuItem9.Click += new System.EventHandler(this.toolStripMenuItem9_Click);
            // 
            // toolStripMenuItem10
            // 
            this.toolStripMenuItem10.Name = "toolStripMenuItem10";
            this.toolStripMenuItem10.Size = new System.Drawing.Size(152, 22);
            this.toolStripMenuItem10.Text = "Compile";
            this.toolStripMenuItem10.Click += new System.EventHandler(this.toolStripMenuItem10_Click);
            // 
            // debugToolStripMenuItem
            // 
            this.debugToolStripMenuItem.Name = "debugToolStripMenuItem";
            this.debugToolStripMenuItem.Size = new System.Drawing.Size(152, 22);
            this.debugToolStripMenuItem.Text = "Debug";
            this.debugToolStripMenuItem.Click += new System.EventHandler(this.debugToolStripMenuItem_Click);
            // 
            // toolStripMenuItem11
            // 
            this.toolStripMenuItem11.Name = "toolStripMenuItem11";
            this.toolStripMenuItem11.Size = new System.Drawing.Size(152, 22);
            this.toolStripMenuItem11.Text = "Run to cursor";
            this.toolStripMenuItem11.Click += new System.EventHandler(this.toolStripMenuItem11_Click);
            // 
            // tabControlOutput
            // 
            this.tabControlOutput.Controls.Add(this.tabPage3);
            this.tabControlOutput.Controls.Add(this.tabPageErrors);
            this.tabControlOutput.Controls.Add(this.tabPageWatches);
            this.tabControlOutput.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.tabControlOutput.Location = new System.Drawing.Point(0, 365);
            this.tabControlOutput.Name = "tabControlOutput";
            this.tabControlOutput.SelectedIndex = 0;
            this.tabControlOutput.Size = new System.Drawing.Size(922, 178);
            this.tabControlOutput.TabIndex = 1;
            // 
            // tabPage3
            // 
            this.tabPage3.Controls.Add(this.richTextBoxOutput);
            this.tabPage3.Location = new System.Drawing.Point(4, 22);
            this.tabPage3.Name = "tabPage3";
            this.tabPage3.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage3.Size = new System.Drawing.Size(914, 152);
            this.tabPage3.TabIndex = 0;
            this.tabPage3.Text = "Output";
            this.tabPage3.UseVisualStyleBackColor = true;
            // 
            // richTextBoxOutput
            // 
            this.richTextBoxOutput.Dock = System.Windows.Forms.DockStyle.Fill;
            this.richTextBoxOutput.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.richTextBoxOutput.Location = new System.Drawing.Point(3, 3);
            this.richTextBoxOutput.Name = "richTextBoxOutput";
            this.richTextBoxOutput.ReadOnly = true;
            this.richTextBoxOutput.Size = new System.Drawing.Size(908, 146);
            this.richTextBoxOutput.TabIndex = 0;
            this.richTextBoxOutput.Text = "";
            // 
            // tabPageErrors
            // 
            this.tabPageErrors.Controls.Add(this.richTextBoxErrors);
            this.tabPageErrors.Location = new System.Drawing.Point(4, 22);
            this.tabPageErrors.Name = "tabPageErrors";
            this.tabPageErrors.Padding = new System.Windows.Forms.Padding(3);
            this.tabPageErrors.Size = new System.Drawing.Size(914, 152);
            this.tabPageErrors.TabIndex = 1;
            this.tabPageErrors.Text = "Errors";
            this.tabPageErrors.UseVisualStyleBackColor = true;
            // 
            // richTextBoxErrors
            // 
            this.richTextBoxErrors.Dock = System.Windows.Forms.DockStyle.Fill;
            this.richTextBoxErrors.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.richTextBoxErrors.Location = new System.Drawing.Point(3, 3);
            this.richTextBoxErrors.Name = "richTextBoxErrors";
            this.richTextBoxErrors.ReadOnly = true;
            this.richTextBoxErrors.Size = new System.Drawing.Size(908, 146);
            this.richTextBoxErrors.TabIndex = 0;
            this.richTextBoxErrors.Text = "";
            // 
            // tabPageWatches
            // 
            this.tabPageWatches.Controls.Add(this.richTextBoxWatches);
            this.tabPageWatches.Location = new System.Drawing.Point(4, 22);
            this.tabPageWatches.Name = "tabPageWatches";
            this.tabPageWatches.Size = new System.Drawing.Size(914, 152);
            this.tabPageWatches.TabIndex = 2;
            this.tabPageWatches.Text = "Watches";
            this.tabPageWatches.UseVisualStyleBackColor = true;
            // 
            // richTextBoxWatches
            // 
            this.richTextBoxWatches.Dock = System.Windows.Forms.DockStyle.Fill;
            this.richTextBoxWatches.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.richTextBoxWatches.Location = new System.Drawing.Point(0, 0);
            this.richTextBoxWatches.Name = "richTextBoxWatches";
            this.richTextBoxWatches.ReadOnly = true;
            this.richTextBoxWatches.Size = new System.Drawing.Size(914, 152);
            this.richTextBoxWatches.TabIndex = 0;
            this.richTextBoxWatches.Text = "";
            // 
            // richTextBoxProgram
            // 
            this.richTextBoxProgram.Dock = System.Windows.Forms.DockStyle.Fill;
            this.richTextBoxProgram.Font = new System.Drawing.Font("Microsoft Sans Serif", 11.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.richTextBoxProgram.Location = new System.Drawing.Point(0, 24);
            this.richTextBoxProgram.Name = "richTextBoxProgram";
            this.richTextBoxProgram.Size = new System.Drawing.Size(922, 341);
            this.richTextBoxProgram.TabIndex = 2;
            this.richTextBoxProgram.Text = "";
            this.richTextBoxProgram.TextChanged += new System.EventHandler(this.richTextBoxProgram_TextChanged);
            // 
            // statusStrip1
            // 
            this.statusStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.toolStripStatusLabel1});
            this.statusStrip1.Location = new System.Drawing.Point(0, 543);
            this.statusStrip1.Name = "statusStrip1";
            this.statusStrip1.Size = new System.Drawing.Size(922, 22);
            this.statusStrip1.TabIndex = 3;
            this.statusStrip1.Text = "statusStrip1";
            this.statusStrip1.ItemClicked += new System.Windows.Forms.ToolStripItemClickedEventHandler(this.statusStrip1_ItemClicked);
            // 
            // toolStripStatusLabel1
            // 
            this.toolStripStatusLabel1.Name = "toolStripStatusLabel1";
            this.toolStripStatusLabel1.Size = new System.Drawing.Size(0, 17);
            this.toolStripStatusLabel1.Click += new System.EventHandler(this.toolStripStatusLabel1_Click);
            // 
            // Form1
            // 
            this.ClientSize = new System.Drawing.Size(922, 565);
            this.Controls.Add(this.richTextBoxProgram);
            this.Controls.Add(this.tabControlOutput);
            this.Controls.Add(this.menuStrip2);
            this.Controls.Add(this.statusStrip1);
            this.MainMenuStrip = this.menuStrip2;
            this.Name = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.menuStrip2.ResumeLayout(false);
            this.menuStrip2.PerformLayout();
            this.tabControlOutput.ResumeLayout(false);
            this.tabPage3.ResumeLayout(false);
            this.tabPageErrors.ResumeLayout(false);
            this.tabPageWatches.ResumeLayout(false);
            this.statusStrip1.ResumeLayout(false);
            this.statusStrip1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion


        private System.Windows.Forms.MenuStrip menuStrip2;
        private System.Windows.Forms.ToolStripMenuItem toolStripMenuItem1;
        private System.Windows.Forms.ToolStripMenuItem toolStripMenuItem3;
        private System.Windows.Forms.ToolStripMenuItem toolStripMenuItem4;
        private System.Windows.Forms.ToolStripMenuItem toolStripMenuItem5;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator2;
        private System.Windows.Forms.ToolStripMenuItem toolStripMenuItem7;
        private System.Windows.Forms.ToolStripMenuItem toolStripMenuItem2;
        private System.Windows.Forms.ToolStripMenuItem toolStripMenuItem9;
        private System.Windows.Forms.ToolStripMenuItem toolStripMenuItem10;
        private System.Windows.Forms.ToolStripMenuItem debugToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem toolStripMenuItem11;
        private System.Windows.Forms.TabControl tabControlOutput;
        private System.Windows.Forms.TabPage tabPage3;
        private System.Windows.Forms.TabPage tabPageErrors;
        private System.Windows.Forms.RichTextBox richTextBoxProgram;
        private System.Windows.Forms.RichTextBox richTextBoxOutput;
        private System.Windows.Forms.RichTextBox richTextBoxErrors;
        private System.Windows.Forms.TabPage tabPageWatches;
        private System.Windows.Forms.RichTextBox richTextBoxWatches;
        private System.Windows.Forms.StatusStrip statusStrip1;
        private System.Windows.Forms.ToolStripStatusLabel toolStripStatusLabel1;
    }
}

