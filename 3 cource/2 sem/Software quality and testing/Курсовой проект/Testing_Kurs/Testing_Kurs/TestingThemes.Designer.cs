namespace Testing_Kurs
{
    partial class TestingThemes
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
            this.label1 = new System.Windows.Forms.Label();
            this.buttonMarvel = new System.Windows.Forms.Button();
            this.buttonDC = new System.Windows.Forms.Button();
            this.buttonSchool = new System.Windows.Forms.Button();
            this.buttonBack = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label1.Location = new System.Drawing.Point(140, 50);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(489, 48);
            this.label1.TabIndex = 0;
            this.label1.Text = "Выберите нужную тему:";
            // 
            // buttonMarvel
            // 
            this.buttonMarvel.Font = new System.Drawing.Font("Microsoft Sans Serif", 16F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.buttonMarvel.Location = new System.Drawing.Point(298, 133);
            this.buttonMarvel.Name = "buttonMarvel";
            this.buttonMarvel.Size = new System.Drawing.Size(175, 46);
            this.buttonMarvel.TabIndex = 1;
            this.buttonMarvel.Text = "Marvel";
            this.buttonMarvel.UseVisualStyleBackColor = true;
            this.buttonMarvel.Click += new System.EventHandler(this.buttonMarvel_Click);
            // 
            // buttonDC
            // 
            this.buttonDC.Font = new System.Drawing.Font("Microsoft Sans Serif", 16F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.buttonDC.Location = new System.Drawing.Point(298, 207);
            this.buttonDC.Name = "buttonDC";
            this.buttonDC.Size = new System.Drawing.Size(175, 45);
            this.buttonDC.TabIndex = 3;
            this.buttonDC.Text = "DC";
            this.buttonDC.UseVisualStyleBackColor = true;
            this.buttonDC.Click += new System.EventHandler(this.buttonDC_Click);
            // 
            // buttonSchool
            // 
            this.buttonSchool.Font = new System.Drawing.Font("Microsoft Sans Serif", 16F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.buttonSchool.Location = new System.Drawing.Point(189, 286);
            this.buttonSchool.Name = "buttonSchool";
            this.buttonSchool.Size = new System.Drawing.Size(408, 45);
            this.buttonSchool.TabIndex = 5;
            this.buttonSchool.Text = "Школьная программа";
            this.buttonSchool.UseVisualStyleBackColor = true;
            this.buttonSchool.Click += new System.EventHandler(this.buttonSchool_Click);
            // 
            // buttonBack
            // 
            this.buttonBack.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.buttonBack.Location = new System.Drawing.Point(679, 384);
            this.buttonBack.Name = "buttonBack";
            this.buttonBack.Size = new System.Drawing.Size(109, 54);
            this.buttonBack.TabIndex = 6;
            this.buttonBack.Text = "Назад";
            this.buttonBack.UseVisualStyleBackColor = true;
            this.buttonBack.Click += new System.EventHandler(this.buttonBack_Click);
            // 
            // TestingThemes
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.buttonBack);
            this.Controls.Add(this.buttonSchool);
            this.Controls.Add(this.buttonDC);
            this.Controls.Add(this.buttonMarvel);
            this.Controls.Add(this.label1);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog;
            this.MaximizeBox = false;
            this.Name = "TestingThemes";
            this.Text = "TestingThemes";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button buttonMarvel;
        private System.Windows.Forms.Button buttonDC;
        private System.Windows.Forms.Button buttonSchool;
        private System.Windows.Forms.Button buttonBack;
    }
}