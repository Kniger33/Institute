using System.Net.Sockets;

namespace Server {
    public class Client {
        private Socket client;
        private string _clientName;

        public Client(Socket client) {
            this.client = client;
        }

        public void SetClientName(string clientName) {
            _clientName = clientName;
        }

        public Socket GetClientSocket() {
            return client;
        }

        public string GetClientName() {
            return _clientName;
        }
    }
}