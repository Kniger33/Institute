using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Net;
using System.Net.Sockets;
using System.Threading;

namespace TCP_Forms_Client {
    public partial class Form1 : Form {
        IPHostEntry host;
        IPAddress ipAdress;
        IPEndPoint ipEndPoint;
        Socket clientSocket;

        Thread reciever;

        byte[] data = new byte[1024];
        int dataSize;

        public Form1() {
            InitializeComponent();
        }

        private void RecieveMessage() {
            string message;
            while (true) {
                dataSize = clientSocket.Receive(data);
                message = Encoding.UTF8.GetString(data, 0, dataSize);
                
                chatTextBox.Invoke(new Action(() => chatTextBox.Text += (message + "\n")));
            }
        }

        private void button1_Click(object sender, EventArgs e) {
            if (adressText.Text == "" || portText.Text == "" || nameText.Text == "") {
                chatTextBox.Text += "Не все поля заполнены! Подключение невозможно!\n";
                return;
            }
            host = Dns.GetHostEntry(adressText.Text);
            ipAdress = host.AddressList[0];
            ipEndPoint = new IPEndPoint(ipAdress, int.Parse(portText.Text));

            clientSocket = new Socket(ipAdress.AddressFamily, SocketType.Stream, ProtocolType.Tcp);
            try {
                clientSocket.Connect(ipEndPoint);
            }
            catch {
                chatTextBox.Text += "Сервер недоступен! Подключение невозможно!\n";
                return;
            }
            
            clientSocket.Receive(data);
            clientSocket.Send(Encoding.UTF8.GetBytes(nameText.Text));
            statusLabel.Text = "Подключено";
            chatTextBox.Clear();
            chatTextBox.Text = "Здравствуй, " + nameText.Text + "\n";

            reciever = new Thread(RecieveMessage);
            reciever.Start();
        }

        private void sendButton_Click(object sender, EventArgs e) {
            string message = messageTextBox.Text;
            
            if (clientSocket == null || !clientSocket.Connected) {
                chatTextBox.Text += "Нет подключения! Отправка невозможна!\n";
                return;
            }

            clientSocket.Send(Encoding.UTF8.GetBytes(message));
            messageTextBox.Clear();
        }

        private void Form1_FormClosing(object sender, FormClosingEventArgs e) {
            reciever.Abort();
            clientSocket.Close();
        }

        private void disconnectButton_Click(object sender, EventArgs e) {
            if (reciever != null) reciever.Abort();
            if (clientSocket != null) clientSocket.Close();
            chatTextBox.Text += "Отключено!\n";
            statusLabel.Text = "Отключено";
        }

        private void Form1_FormClosed(object sender, FormClosedEventArgs e) {
            if (reciever != null) reciever.Abort();
            if (clientSocket != null) clientSocket.Close();
        }

        private void chatTextBox_TextChanged(object sender, EventArgs e) {
            chatTextBox.SelectionStart = chatTextBox.Text.Length;
            chatTextBox.ScrollToCaret();
        }

    }
}
