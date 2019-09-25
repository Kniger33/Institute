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

using namespace std;

int main()
{
    int sock, listener;
    struct sockaddr_in addr;
    
	vector <struct sockaddr_in> sockets;
	
	struct sockaddr_in tempAddr;
	socklen_t tempAddr_size = sizeof(tempAddr);
	
	
    char buf[256];
	char del[] = "";
	int sendID, curSockID = 0;

    int bytes_read;

    listener = socket(AF_INET, SOCK_STREAM, 0);
    if(listener < 0)
    {
        perror("socket");
        exit(1);
    }
    
    addr.sin_family = AF_INET;
    addr.sin_port = htons(3425);
    addr.sin_addr.s_addr = INADDR_ANY;
    if(bind(listener, (struct sockaddr *)&addr, sizeof(addr)) < 0)
    {
        perror("bind");
        exit(2);
    }

    listen(listener, 1);
    
    while(1)
    {
        sock = accept(listener, (struct sockaddr *) &tempAddr, &tempAddr_size);
        sockets.push_back(tempAddr);
        
        if(sock < 0)
        {
            perror("accept");
            exit(3);
        }
        
        switch(fork())
        {
        case -1:
            perror("fork");
            break;
            
        case 0:
            close(listener);
            
            write(sock, &curSockID, sizeof(int));
            curSockID++;
            cout << "Cur: " << curSockID << endl;
            
            while(1)
            {
				
				//sendto(sock, buf, strlen(buf) * sizeof(char), 0, (struct sockaddr *)&sockets[0], sizeof(sockets[0]));
				strcmp(buf, del);
				read(sock, &sendID, sizeof(int));
				if (sendID < sockets.size()){
					cout << "SEND ID: " << sendID << endl;
				}
				else {
					cout << "ID " << sendID << " incorrect!" << endl;
					sendID = 0;	
				}
				
				if (recv(sock, buf, 256, 0) > 0){
					cout << "Message: ";
					printf(buf);
					cout << endl << endl;
					sendto(sock, buf, strlen(buf) * sizeof(char), 0, (struct sockaddr *)&sockets[sendID], sizeof(sockets[sendID]));
				}
                //bytes_read = recv(sock, buf, 1024, 0);
                //if(bytes_read <= 0) break;
                //send(sock, buf, bytes_read, 0);
            }

            close(sock);
            _exit(0);
            
        default:
            close(sock);
        }
    }
    
    close(listener);

    return 0;
}
