#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <string.h>
#include <thread>

using namespace std;

char buf[256];
char del[] = "";

int sock;
int sendID, curSockID;
struct sockaddr_in addr;

void ListenThread(){
	while(1){
		if (recvfrom(sock, buf, 256, 0, NULL, NULL) > 0){
			cout << endl << endl << "Input message: ";
			printf("%s", buf);
			cout << endl;
		}
	}
}

void SendThread(){
	while(1){
		cout << endl << "Write id to send and message: ";			
		cin >> sendID;

		send(sock, &sendID, sizeof(int), 0);
		getchar();
		fgets(buf, 256, stdin);

		for(int i = 0; i < strlen(buf); i++){
			buf[i] ^= i % strlen(buf);
		}
		
		send(sock, buf, (strlen(buf)+1)*sizeof(char), 0);
		buf[strlen(buf)] = '\0';
	}	
}

int main(){
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
	
	read(sock, &curSockID, sizeof(int));
	cout << "Your ID: " << curSockID << endl;
	
	thread ListThr(ListenThread);
    ListThr.detach();
    
    thread SendThr(SendThread);
    SendThr.join();

	cout << "End" << endl;
		 
    close(sock);

    return 0;
}
