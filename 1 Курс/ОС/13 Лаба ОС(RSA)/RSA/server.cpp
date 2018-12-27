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

long long int NOD(unsigned long int n1, long long int n2){
  long long int div;
  if (n1 == n2)
    return n1;
  long long int d = n1 - n2;
  if (d < 0){
    d = -d;
    div = NOD(n1, d);
  }
  else{
    div = NOD(n2, d);
  }
  return div;
}

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
	srand(time(NULL));
    int simpleNumbers[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 73, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199};
    int p = simpleNumbers[rand() % (45 + 1)];
    int q = simpleNumbers[rand() % (45 + 1)];
    long long int n;
	long long int e = 0;
	long long int d;
    long long int pqminus;
    unsigned long long int ed;
    unsigned long long int tmp;

    vector<unsigned long long int> message;

    int maximum = 1000000;
    int minimum = 1;

    d = minimum + rand() % ((maximum + 1) - minimum);
    n = p*q;
    pqminus = (q - 1)*(p - 1);

    while (NOD(d, pqminus) != 1){
        d++;
    }
    
    e = minimum + rand() % ((maximum+ 1) - minimum);
    ed = e * d;

    while ((ed) % pqminus != 1){
        e++;
        ed = e * d;
    }

    int sock, listener;
    struct sockaddr_in addr;
	int cnt;
	int id;
	
    listener = socket(AF_INET, SOCK_STREAM, 0);
    if(listener < 0){
        perror("socket");
        exit(1);
    }

    addr.sin_family = AF_INET;
    addr.sin_port = htons(3425);
    addr.sin_addr.s_addr = INADDR_ANY;
    
    if(bind(listener, (struct sockaddr *)&addr, sizeof(addr)) < 0){
        perror("bind");
        exit(2);
    }

    listen(listener, 1);

    while(1){
        sock = accept(listener, NULL, NULL);
        if(sock < 0){
            perror("accept");
            exit(3);
        }

        switch(fork()){
        	case -1:
            	perror("fork");
            	break;

       		case 0:
            	close(listener);

	    		read(sock, &id, sizeof(int));
	    		cout << "User's ID: " << id << " ----> Connected" << endl << endl;
	    		write(sock, &e, sizeof(long long int));
        		write(sock, &n, sizeof(long long int));

          		while(1){
               		read(sock, &cnt, sizeof(int));
               		
					if (cnt > 0){
                		for(int i = 0; i < cnt; i++){
                    	read(sock, &tmp, sizeof(unsigned long long int));
                    	message.push_back(tmp);
                		}
                
                		cout << "User's ID: " << id << endl;
                		cout << "Secret message: ";
                		for (int i = 0; i < cnt; i++){
                    		cout << message[i];
                		}
               			cout << endl;

                		cout << "OutputMessage: ";
                		for (int i = 0; i < cnt; i++){
		                	cout << (char)myPow(message[i], d, n);
		            	}
		            	cout << endl << endl;

		            	message.clear();
						cnt = 0;
					}
					else {
						close(sock);
			 			cout << "User's ID: " << id << " ----> Disconnected" << endl << endl;
            			_exit(0);
					}
				}
			
        	default:
            	close(sock);
        }
    }

    close(listener);

    return 0;
}
