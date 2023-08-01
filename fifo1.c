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
    int fileD;

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
        //printf("%s \n", tempo);
        fileD = open(fifofile, O_WRONLY);
        write(fileD, tempo, strlen(tempo)+1);
        close(fileD);
        strcpy(newstrings[j], tempo);
        char id[10];
        fileD = open(fifofile, O_RDONLY);
        read( fileD , id , 3);
        close(fileD);
        printf("%s\n", id);

    }

    return 0;
}

/* Part of code is referred from geeksforgeeks for practical usage in this assignment.*/
