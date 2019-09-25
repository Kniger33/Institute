namespace TSP_GUI {
    public partial class Form1 {
        /// <summary>
        /// Обязательная переменная конструктора.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Освободить все используемые ресурсы.
        /// </summary>
        /// <param name="disposing">истинно, если управляемый ресурс должен быть удален; иначе ложно.</param>
        protected override void Dispose(bool disposing) {
            if (disposing && (components != null)) {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Код, автоматически созданный конструктором форм Windows

        /// <summary>
        /// Требуемый метод для поддержки конструктора — не изменяйте 
        /// содержимое этого метода с помощью редактора кода.
        /// </summary>
        private void InitializeComponent() {
            this.label1 = new System.Windows.Forms.Label();
            this.TownCountSelector = new System.Windows.Forms.NumericUpDown();
            this.WayLengthTable = new System.Windows.Forms.DataGridView();
            this.Column1 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.Column2 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.CountOKButton = new System.Windows.Forms.Button();
            this.label2 = new System.Windows.Forms.Label();
            this.PathTextBox = new System.Windows.Forms.TextBox();
            this.FindWayButton = new System.Windows.Forms.Button();
            this.GraphPanel = new System.Windows.Forms.Panel();
            this.label3 = new System.Windows.Forms.Label();
            this.LengthTextBox = new System.Windows.Forms.TextBox();
            this.RestartButton = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.TownCountSelector)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.WayLengthTable)).BeginInit();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(12, 9);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(88, 13);
            this.label1.TabIndex = 0;
            this.label1.Text = "Кол-во городов:";
            // 
            // TownCountSelector
            // 
            this.TownCountSelector.Location = new System.Drawing.Point(106, 7);
            this.TownCountSelector.Maximum = new decimal(new int[] {
            12,
            0,
            0,
            0});
            this.TownCountSelector.Minimum = new decimal(new int[] {
            3,
            0,
            0,
            0});
            this.TownCountSelector.Name = "TownCountSelector";
            this.TownCountSelector.Size = new System.Drawing.Size(68, 20);
            this.TownCountSelector.TabIndex = 1;
            this.TownCountSelector.Value = new decimal(new int[] {
            3,
            0,
            0,
            0});
            // 
            // WayLengthTable
            // 
            this.WayLengthTable.AllowUserToAddRows = false;
            this.WayLengthTable.AllowUserToDeleteRows = false;
            this.WayLengthTable.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.WayLengthTable.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.Column1,
            this.Column2});
            this.WayLengthTable.Location = new System.Drawing.Point(12, 33);
            this.WayLengthTable.Name = "WayLengthTable";
            this.WayLengthTable.Size = new System.Drawing.Size(244, 345);
            this.WayLengthTable.TabIndex = 3;
            // 
            // Column1
            // 
            this.Column1.HeaderText = "Путь";
            this.Column1.Name = "Column1";
            // 
            // Column2
            // 
            this.Column2.HeaderText = "Длина";
            this.Column2.Name = "Column2";
            // 
            // CountOKButton
            // 
            this.CountOKButton.Location = new System.Drawing.Point(181, 7);
            this.CountOKButton.Name = "CountOKButton";
            this.CountOKButton.Size = new System.Drawing.Size(75, 20);
            this.CountOKButton.TabIndex = 4;
            this.CountOKButton.Text = "OK";
            this.CountOKButton.UseVisualStyleBackColor = true;
            this.CountOKButton.MouseClick += new System.Windows.Forms.MouseEventHandler(this.CountOKButton_MouseClick);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(12, 419);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(96, 13);
            this.label2.TabIndex = 5;
            this.label2.Text = "Кратчайший путь:";
            // 
            // PathTextBox
            // 
            this.PathTextBox.Location = new System.Drawing.Point(114, 416);
            this.PathTextBox.Name = "PathTextBox";
            this.PathTextBox.Size = new System.Drawing.Size(142, 20);
            this.PathTextBox.TabIndex = 6;
            // 
            // FindWayButton
            // 
            this.FindWayButton.Location = new System.Drawing.Point(12, 384);
            this.FindWayButton.Name = "FindWayButton";
            this.FindWayButton.Size = new System.Drawing.Size(244, 23);
            this.FindWayButton.TabIndex = 7;
            this.FindWayButton.Text = "Найти решение";
            this.FindWayButton.UseVisualStyleBackColor = true;
            this.FindWayButton.MouseClick += new System.Windows.Forms.MouseEventHandler(this.FindWayButton_MouseClick);
            // 
            // GraphPanel
            // 
            this.GraphPanel.Location = new System.Drawing.Point(271, 9);
            this.GraphPanel.Name = "GraphPanel";
            this.GraphPanel.Size = new System.Drawing.Size(400, 400);
            this.GraphPanel.TabIndex = 8;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(268, 419);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(68, 13);
            this.label3.TabIndex = 9;
            this.label3.Text = "Длина пути:";
            // 
            // LengthTextBox
            // 
            this.LengthTextBox.Location = new System.Drawing.Point(342, 416);
            this.LengthTextBox.Name = "LengthTextBox";
            this.LengthTextBox.Size = new System.Drawing.Size(142, 20);
            this.LengthTextBox.TabIndex = 10;
            // 
            // RestartButton
            // 
            this.RestartButton.Location = new System.Drawing.Point(596, 416);
            this.RestartButton.Name = "RestartButton";
            this.RestartButton.Size = new System.Drawing.Size(75, 20);
            this.RestartButton.TabIndex = 11;
            this.RestartButton.Text = "Заново";
            this.RestartButton.UseVisualStyleBackColor = true;
            this.RestartButton.Click += new System.EventHandler(this.RestartButton_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(684, 451);
            this.Controls.Add(this.RestartButton);
            this.Controls.Add(this.LengthTextBox);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.GraphPanel);
            this.Controls.Add(this.FindWayButton);
            this.Controls.Add(this.PathTextBox);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.CountOKButton);
            this.Controls.Add(this.WayLengthTable);
            this.Controls.Add(this.TownCountSelector);
            this.Controls.Add(this.label1);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.Name = "Form1";
            this.Text = "Form1";
            ((System.ComponentModel.ISupportInitialize)(this.TownCountSelector)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.WayLengthTable)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        public System.Windows.Forms.Label label1;
        public System.Windows.Forms.NumericUpDown TownCountSelector;
        public System.Windows.Forms.DataGridView WayLengthTable;
        public System.Windows.Forms.DataGridViewTextBoxColumn Column1;
        public System.Windows.Forms.DataGridViewTextBoxColumn Column2;
        public System.Windows.Forms.Button CountOKButton;
        public System.Windows.Forms.Label label2;
        public System.Windows.Forms.TextBox PathTextBox;
        public System.Windows.Forms.Button FindWayButton;
        public System.Windows.Forms.Panel GraphPanel;
        public System.Windows.Forms.Label label3;
        public System.Windows.Forms.TextBox LengthTextBox;
        public System.Windows.Forms.Button RestartButton;
    }
}

