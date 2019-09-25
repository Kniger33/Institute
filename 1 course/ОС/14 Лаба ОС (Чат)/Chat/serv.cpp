#include <sys/types.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <netinet/in.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <algorithm>
#include <set>
#include <vector>
#include <string.h>
#include <iostream>

using namespace std;

int main(){
    int listener;
    struct sockaddr_in addr;
    char buf[256];
    int bytes_read;

	vector <bool> flags;

	char del[] = "";
	int sendID, curSockID = 0;

    listener = socket(AF_INET, SOCK_STREAM, 0);
    if(listener < 0){
        perror("socket");
        exit(1);
    }
    
    fcntl(listener, F_SETFL, O_NONBLOCK);
    
    addr.sin_family = AF_INET;
    addr.sin_port = htons(3425);
    addr.sin_addr.s_addr = INADDR_ANY;
    if(bind(listener, (struct sockaddr *)&addr, sizeof(addr)) < 0){
        perror("bind");
        exit(2);
    }

    listen(listener, 5);
    
    set<int> clients;
    clients.clear();

    while(1){
        fd_set readset;
        FD_ZERO(&readset);
        FD_SET(listener, &readset);

        for(set<int>::iterator it = clients.begin(); it != clients.end(); it++){
            FD_SET(*it, &readset);
        }

        timeval timeout;
        timeout.tv_sec = 300;
        timeout.tv_usec = 0;

        int mx = max(listener, *max_element(clients.begin(), clients.end()));
       
        if(select(mx+1, &readset, NULL, NULL, &timeout) <= 0){
            perror("select");
            exit(3);
        }

        if(FD_ISSET(listener, &readset)){
            int sock = accept(listener, NULL, NULL);
            if(sock < 0){
                perror("accept");
                exit(3);
            }
            
            write(sock, &curSockID, sizeof(int));
            cout << "Client " << curSockID << " ----> Connected" << endl << endl;
            curSockID++;

			flags.push_back(true);
            clients.insert(sock);
        }
        
        int i;
        set<int>::iterator it;

        for(i = 0, it = clients.begin(); it != clients.end(); it++, i++){
            if(FD_ISSET(*it, &readset)){
            	if(flags[i] == true){
		        	strcpy(buf, del);
					bytes_read = recv(*it, &sendID, sizeof(int), 0);
				
					if(bytes_read <= 0){
		                flags[i] = false;
						cout << "Client " << i << " ----> Disconnected" << endl << endl;
		                continue;
		            }

					if (sendID < flags.size()){
						cout << "SEND ID: " << sendID << endl;
						if (recv(*it, buf, 256, 0) > 0){
							cout << "Message: ";
							for(int i = 0; i < strlen(buf); i++){
								buf[i] ^= i % strlen(buf);
							}
							buf[strlen(buf)] = '\0';
							printf("%s", buf);
							cout << endl;
					
							set<int>::iterator sendIt;
							sendIt = clients.begin();
							advance(sendIt, sendID);
					
							send(*sendIt, buf, (strlen(buf)+1)*sizeof(char), 0);
						}
					}
					else {
						cout << "ID " << sendID << " incorrect!" << endl << endl;
					}
				}
        	}
        }
    }
    
	return 0;
}
