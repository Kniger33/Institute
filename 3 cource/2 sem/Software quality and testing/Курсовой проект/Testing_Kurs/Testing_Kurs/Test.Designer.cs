namespace Testing_Kurs
{
    partial class Test
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.labelTheme = new System.Windows.Forms.Label();
            this.buttonExitToMain = new System.Windows.Forms.Button();
            this.groupBoxQuestion = new System.Windows.Forms.GroupBox();
            this.radioButtonAnswer4 = new System.Windows.Forms.RadioButton();
            this.radioButtonAnswer3 = new System.Windows.Forms.RadioButton();
            this.radioAnswer2 = new System.Windows.Forms.RadioButton();
            this.radioAnswer1 = new System.Windows.Forms.RadioButton();
            this.buttonNextQuestion = new System.Windows.Forms.Button();
            this.groupBoxQuestion.SuspendLayout();
            this.SuspendLayout();
            // 
            // labelTheme
            // 
            this.labelTheme.AutoSize = true;
            this.labelTheme.Font = new System.Drawing.Font("Microsoft Sans Serif", 16F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.labelTheme.Location = new System.Drawing.Point(329, 30);
            this.labelTheme.Name = "labelTheme";
            this.labelTheme.Size = new System.Drawing.Size(80, 31);
            this.labelTheme.TabIndex = 0;
            this.labelTheme.Text = "Тема";
            // 
            // buttonExitToMain
            // 
            this.buttonExitToMain.Font = new System.Drawing.Font("Microsoft Sans Serif", 14F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.buttonExitToMain.Location = new System.Drawing.Point(658, 374);
            this.buttonExitToMain.Name = "buttonExitToMain";
            this.buttonExitToMain.Size = new System.Drawing.Size(130, 64);
            this.buttonExitToMain.TabIndex = 1;
            this.buttonExitToMain.Text = "В меню";
            this.buttonExitToMain.UseVisualStyleBackColor = true;
            this.buttonExitToMain.Click += new System.EventHandler(this.buttonExitToMain_Click);
            // 
            // groupBoxQuestion
            // 
            this.groupBoxQuestion.Controls.Add(this.radioButtonAnswer4);
            this.groupBoxQuestion.Controls.Add(this.radioButtonAnswer3);
            this.groupBoxQuestion.Controls.Add(this.radioAnswer2);
            this.groupBoxQuestion.Controls.Add(this.radioAnswer1);
            this.groupBoxQuestion.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.groupBoxQuestion.Location = new System.Drawing.Point(59, 102);
            this.groupBoxQuestion.Name = "groupBoxQuestion";
            this.groupBoxQuestion.Size = new System.Drawing.Size(676, 253);
            this.groupBoxQuestion.TabIndex = 2;
            this.groupBoxQuestion.TabStop = false;
            this.groupBoxQuestion.Text = "Вопрос";
            // 
            // radioButtonAnswer4
            // 
            this.radioButtonAnswer4.AutoSize = true;
            this.radioButtonAnswer4.Location = new System.Drawing.Point(6, 188);
            this.radioButtonAnswer4.Name = "radioButtonAnswer4";
            this.radioButtonAnswer4.Size = new System.Drawing.Size(109, 29);
            this.radioButtonAnswer4.TabIndex = 3;
            this.radioButtonAnswer4.TabStop = true;
            this.radioButtonAnswer4.Text = "Ответ 4";
            this.radioButtonAnswer4.UseVisualStyleBackColor = true;
            // 
            // radioButtonAnswer3
            // 
            this.radioButtonAnswer3.AutoSize = true;
            this.radioButtonAnswer3.Location = new System.Drawing.Point(6, 144);
            this.radioButtonAnswer3.Name = "radioButtonAnswer3";
            this.radioButtonAnswer3.Size = new System.Drawing.Size(109, 29);
            this.radioButtonAnswer3.TabIndex = 2;
            this.radioButtonAnswer3.TabStop = true;
            this.radioButtonAnswer3.Text = "Ответ 3";
            this.radioButtonAnswer3.UseVisualStyleBackColor = true;
            // 
            // radioAnswer2
            // 
            this.radioAnswer2.AutoSize = true;
            this.radioAnswer2.Location = new System.Drawing.Point(6, 99);
            this.radioAnswer2.Name = "radioAnswer2";
            this.radioAnswer2.Size = new System.Drawing.Size(109, 29);
            this.radioAnswer2.TabIndex = 1;
            this.radioAnswer2.TabStop = true;
            this.radioAnswer2.Text = "Ответ 2";
            this.radioAnswer2.UseVisualStyleBackColor = true;
            // 
            // radioAnswer1
            // 
            this.radioAnswer1.AutoSize = true;
            this.radioAnswer1.Location = new System.Drawing.Point(6, 53);
            this.radioAnswer1.Name = "radioAnswer1";
            this.radioAnswer1.Size = new System.Drawing.Size(109, 29);
            this.radioAnswer1.TabIndex = 0;
            this.radioAnswer1.TabStop = true;
            this.radioAnswer1.Text = "Ответ 1";
            this.radioAnswer1.UseVisualStyleBackColor = true;
            // 
            // buttonNextQuestion
            // 
            this.buttonNextQuestion.Font = new System.Drawing.Font("Microsoft Sans Serif", 16F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.buttonNextQuestion.Location = new System.Drawing.Point(262, 361);
            this.buttonNextQuestion.Name = "buttonNextQuestion";
            this.buttonNextQuestion.Size = new System.Drawing.Size(276, 77);
            this.buttonNextQuestion.TabIndex = 3;
            this.buttonNextQuestion.Text = "Следующий вопрос";
            this.buttonNextQuestion.UseVisualStyleBackColor = true;
            this.buttonNextQuestion.Click += new System.EventHandler(this.buttonNextQuestion_Click);
            // 
            // Test
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.buttonNextQuestion);
            this.Controls.Add(this.groupBoxQuestion);
            this.Controls.Add(this.buttonExitToMain);
            this.Controls.Add(this.labelTheme);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog;
            this.MaximizeBox = false;
            this.Name = "Test";
            this.Text = "Test";
            this.groupBoxQuestion.ResumeLayout(false);
            this.groupBoxQuestion.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label labelTheme;
        private System.Windows.Forms.Button buttonExitToMain;
        private System.Windows.Forms.GroupBox groupBoxQuestion;
        private System.Windows.Forms.Button buttonNextQuestion;
        private System.Windows.Forms.RadioButton radioButtonAnswer4;
        private System.Windows.Forms.RadioButton radioButtonAnswer3;
        private System.Windows.Forms.RadioButton radioAnswer2;
        private System.Windows.Forms.RadioButton radioAnswer1;
    }
}