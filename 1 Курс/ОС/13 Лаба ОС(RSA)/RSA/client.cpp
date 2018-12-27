#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <vector>

using namespace std;

long long int myPow(int smb, int e, int n){
    long long int res;
    smb %= n;
    res = smb;
    for(int i = 1; i < e; i++){
        res = (res * smb) % n;
    }
    return res;
}

int main(){
    long long int e, n;
    string msg;
    vector<unsigned long long int> message;

    int sock;
    int cnt = 4;
    int id;
    struct sockaddr_in addr;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock < 0){
        perror("socket");
        exit(1);
    }

    addr.sin_family = AF_INET;
    addr.sin_port = htons(3425);
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    
    if(connect(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0){
        perror("connect");
        exit(2);
    }
	
	cout << "Enter ID: ";
	cin >> id;
	
	write(sock, &id, sizeof(int));
	read(sock, &e, sizeof(long long int));
   	read(sock, &n, sizeof(long long int));
    cout << "Connected..." << endl;
	getchar();

	while (true){
        cout << endl << "Write message: ";
	    //getchar();
        getline(cin, msg);

        cout << "Secret message: ";
        for (int i = 0; i < msg.size(); i++){
            message.push_back(myPow((int)msg[i], e, n));
            cout << message[i];
        }
        cout << endl;

        cnt = message.size();
        write(sock, &cnt, sizeof(int));
        for(int i = 0; i < cnt; i++){
            write(sock, &message[i], sizeof(unsigned long long int));
        }

        message.clear();
    }

    close(sock);
    
    return 0;
}

