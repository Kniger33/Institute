namespace TCP_Forms_Client {
    partial class Form1 {
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
            this.label2 = new System.Windows.Forms.Label();
            this.adressText = new System.Windows.Forms.MaskedTextBox();
            this.messageTextBox = new System.Windows.Forms.RichTextBox();
            this.connectButton = new System.Windows.Forms.Button();
            this.sendButton = new System.Windows.Forms.Button();
            this.disconnectButton = new System.Windows.Forms.Button();
            this.label3 = new System.Windows.Forms.Label();
            this.statusLabel = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.nameText = new System.Windows.Forms.TextBox();
            this.portText = new System.Windows.Forms.TextBox();
            this.chatTextBox = new System.Windows.Forms.RichTextBox();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label1.Location = new System.Drawing.Point(16, 11);
            this.label1.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(64, 17);
            this.label1.TabIndex = 0;
            this.label1.Text = "IP Адрес";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label2.Location = new System.Drawing.Point(16, 42);
            this.label2.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(41, 17);
            this.label2.TabIndex = 2;
            this.label2.Text = "Порт";
            // 
            // adressText
            // 
            this.adressText.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.adressText.Location = new System.Drawing.Point(105, 10);
            this.adressText.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.adressText.Mask = "000/000/000/000";
            this.adressText.Name = "adressText";
            this.adressText.Size = new System.Drawing.Size(115, 23);
            this.adressText.TabIndex = 3;
            this.adressText.Text = "127000000001";
            // 
            // messageTextBox
            // 
            this.messageTextBox.Location = new System.Drawing.Point(16, 218);
            this.messageTextBox.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.messageTextBox.Name = "messageTextBox";
            this.messageTextBox.Size = new System.Drawing.Size(413, 66);
            this.messageTextBox.TabIndex = 5;
            this.messageTextBox.Text = "";
            // 
            // connectButton
            // 
            this.connectButton.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.connectButton.Location = new System.Drawing.Point(272, 7);
            this.connectButton.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.connectButton.Name = "connectButton";
            this.connectButton.Size = new System.Drawing.Size(147, 28);
            this.connectButton.TabIndex = 6;
            this.connectButton.Text = "Подключиться";
            this.connectButton.UseVisualStyleBackColor = true;
            this.connectButton.Click += new System.EventHandler(this.button1_Click);
            // 
            // sendButton
            // 
            this.sendButton.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.sendButton.Location = new System.Drawing.Point(331, 292);
            this.sendButton.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.sendButton.Name = "sendButton";
            this.sendButton.Size = new System.Drawing.Size(100, 28);
            this.sendButton.TabIndex = 7;
            this.sendButton.Text = "Отправить";
            this.sendButton.UseVisualStyleBackColor = true;
            this.sendButton.Click += new System.EventHandler(this.sendButton_Click);
            // 
            // disconnectButton
            // 
            this.disconnectButton.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.disconnectButton.Location = new System.Drawing.Point(272, 71);
            this.disconnectButton.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.disconnectButton.Name = "disconnectButton";
            this.disconnectButton.Size = new System.Drawing.Size(147, 28);
            this.disconnectButton.TabIndex = 8;
            this.disconnectButton.Text = "Отключиться";
            this.disconnectButton.UseVisualStyleBackColor = true;
            this.disconnectButton.Click += new System.EventHandler(this.disconnectButton_Click);
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label3.Location = new System.Drawing.Point(268, 46);
            this.label3.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(57, 17);
            this.label3.TabIndex = 9;
            this.label3.Text = "Статус:";
            // 
            // statusLabel
            // 
            this.statusLabel.AutoSize = true;
            this.statusLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.statusLabel.Location = new System.Drawing.Point(327, 46);
            this.statusLabel.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.statusLabel.Name = "statusLabel";
            this.statusLabel.Size = new System.Drawing.Size(75, 17);
            this.statusLabel.TabIndex = 10;
            this.statusLabel.Text = "Отключен";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label5.Location = new System.Drawing.Point(16, 78);
            this.label5.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(73, 17);
            this.label5.TabIndex = 11;
            this.label5.Text = "Ваше имя";
            // 
            // nameText
            // 
            this.nameText.Location = new System.Drawing.Point(105, 74);
            this.nameText.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.nameText.Name = "nameText";
            this.nameText.Size = new System.Drawing.Size(115, 22);
            this.nameText.TabIndex = 12;
            // 
            // portText
            // 
            this.portText.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.portText.Location = new System.Drawing.Point(105, 42);
            this.portText.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.portText.Name = "portText";
            this.portText.Size = new System.Drawing.Size(115, 23);
            this.portText.TabIndex = 13;
            this.portText.Text = "7777";
            // 
            // chatTextBox
            // 
            this.chatTextBox.Location = new System.Drawing.Point(16, 106);
            this.chatTextBox.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.chatTextBox.Name = "chatTextBox";
            this.chatTextBox.ReadOnly = true;
            this.chatTextBox.Size = new System.Drawing.Size(413, 104);
            this.chatTextBox.TabIndex = 14;
            this.chatTextBox.Text = "";
            this.chatTextBox.TextChanged += new System.EventHandler(this.chatTextBox_TextChanged);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(444, 334);
            this.Controls.Add(this.chatTextBox);
            this.Controls.Add(this.portText);
            this.Controls.Add(this.nameText);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.statusLabel);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.disconnectButton);
            this.Controls.Add(this.sendButton);
            this.Controls.Add(this.connectButton);
            this.Controls.Add(this.messageTextBox);
            this.Controls.Add(this.adressText);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog;
            this.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.Name = "Form1";
            this.Text = "Form1";
            this.FormClosed += new System.Windows.Forms.FormClosedEventHandler(this.Form1_FormClosed);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.MaskedTextBox adressText;
        private System.Windows.Forms.RichTextBox messageTextBox;
        private System.Windows.Forms.Button connectButton;
        private System.Windows.Forms.Button sendButton;
        private System.Windows.Forms.Button disconnectButton;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label statusLabel;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.TextBox nameText;
        private System.Windows.Forms.TextBox portText;
        private System.Windows.Forms.RichTextBox chatTextBox;
    }
}

