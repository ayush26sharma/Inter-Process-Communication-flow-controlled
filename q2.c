#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct str_info{
    long id;
    char msg_str[50];
};



int main(){

    key_t msg_key2;
    int msg_id2;
    msg_key2 = ftok("file2", 99);
    msg_id2 = msgget(msg_key2,0666 | IPC_CREAT);

    int maxid = -1;
    int fileD;
	struct str_info structure;
    for (int j = 0; j<10; j++){
        char receiver[1024]="";
        msgrcv(msg_id2, &structure, sizeof(structure), 1,0);

        // fileD = open(fifofile, O_RDONLY);
        // read( fileD , receiver, 1024);
        // close(fileD);

        for(int i = 0; i<36; i++){
            char a = structure.msg_str[i];
            if(a>='a' && a<='z'){
                printf("%c", a);
            }
            else if(a>='0' && a<='9'){
                if (structure.msg_str[i-1]>='a' && structure.msg_str[i-1]<='z'){
                    printf(" ");
                }
                printf("%c", a);
            }
            else{
                printf("\n");
            }
        }
        struct str_info maxID;
        
        //printf("%s", receiver);
        maxid+=5;
        char snum[5];
        sprintf(snum,"%d",maxid);
        strcpy(maxID.msg_str,snum);
        maxID.id = 99;
        msgsnd(msg_id2, &maxID, sizeof(maxID), 0);
        printf("MAX-ID sent: %d\n", maxid);
        
        
    }

    return 0;
}


/* Part of code is referred from geeksforgeeks for practical usage in this assignment.*/
