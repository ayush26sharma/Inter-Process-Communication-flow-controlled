#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#define PORT 5656


int main(int argc, char const *argv[]){

    
    for(int i = 0; i<50; i++){
	int sock = 0, valread;
	struct sockaddr_in serv_addr;
	
	char buffer[1024] = {0};
	if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		printf("\n Socket creation error \n");
		return -1;
	}

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(PORT);
	
	if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0)
	{
		printf("\nInvalid address/ Address not supported \n");
		return -1;
	}

	if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0){
		// printf("\nConnection Failed \n");
		return -1;
	}
    int maxid = -1;
	
    for (int j = 0; j<10; j++){
        char receiver[1024]="";
        
        read( sock , receiver, 1024);
        for(int i = 0; i<strlen(receiver); i++){
            char a = receiver[i];
            if(a>='a' && a<='z'){
                printf("%c", a);
            }
            else if(a>='0' && a<='9'){
                if (receiver[i-1]>='a' && receiver[i-1]<='z'){
                    printf(" ");
                }
                printf("%c", a);
            }
            else{
                printf("\n");
            }
        }
        //printf("%s", receiver);
        maxid+=5;
        char snum[5];
        sprintf(snum,"%d",maxid);
        send(sock, snum, strlen(snum)+1, 0);
    }
	
	return 0;
    }
}

/* Part of code is referred from geeksforgeeks for practical usage in this assignment.*/

