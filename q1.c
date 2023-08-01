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
    

    char *characters[100] ={"q","w","e","r","t","y","u","i","o","p","a","s","d","f","g","h","j","k","l","z","x","c","v","b","n","m"};
    char *allstring[50];
    char temp[100] = "";
    for (int j = 0; j<50; j++){
        allstring[j] =(char*) malloc(50*sizeof(char));
        for (int i = 0; i<5; i++){
            
            int random = rand() % 26;
            strncat(temp,characters[random],1);
        }

        //printf("%s \n", temp);
        strcpy(allstring[j], temp);
        strcpy(temp, "");

        //printf("%s1 \n", allstring[j]);
    }

    char *newstrings[10];
    int l = 0;
    //int id = 0;
    key_t msg_key1, msg_key2;
    int msg_id1, msg_id2;
    msg_key1 = ftok("file1", 99);
    // 

    msg_id1 = msgget(msg_key1,0666 | IPC_CREAT);
    // 

    for (int j = 0; j<10; j++){
        newstrings[j] =(char*) malloc(50*sizeof(char));
        char tempo[100] = "";
        char space[100] = " ";
        for (int i = 0; i<5; i++){
            char snum[5];
            sprintf(snum, "%d", l);
           // printf("%s\n", snum);
            strncat(allstring[l], snum, strlen(snum));
            strncat(tempo, allstring[l], 7);
            strncat(tempo, space, 10);
            l++;
        }
        struct str_info structure;
        structure.id = 1;
        strcpy(structure.msg_str, tempo);
        
        msgsnd(msg_id1, &structure, sizeof(structure), 0);
        // printf("Index sent: %d", l);

        struct str_info maxID;
        msgrcv(msg_id1, &maxID, sizeof(maxID), 99, 0);
        printf("MAX-ID Received: %s\n", maxID.msg_str);
        memset(structure.msg_str,0, strlen(structure.msg_str));
    }

    return 0;
}

/* Part of code is referred from geeksforgeeks for practical usage in this assignment.*/
