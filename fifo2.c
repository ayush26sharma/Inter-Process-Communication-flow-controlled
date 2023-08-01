#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
    char *fifofile = "/tmp/fifo1";
    mkfifo(fifofile, 0666);
    int maxid = -1;
    int fileD;
	
    for (int j = 0; j<10; j++){
        char receiver[1024]="";
        fileD = open(fifofile, O_RDONLY);
        read( fileD , receiver, 1024);
        close(fileD);
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
        fileD = open(fifofile, O_WRONLY);
        write(fileD, snum, strlen(snum)+1);
        close(fileD);
    }

    return 0;
}

/* Part of code is referred from geeksforgeeks for practical usage in this assignment.*/
