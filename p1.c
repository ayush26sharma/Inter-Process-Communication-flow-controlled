#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define PORT 5656



int main(int argc, char const *argv[]){

    

    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    // char *hello = malloc(sizeOf(char*));
    // *hello = *randstring(5);
    
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0){
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
    
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))){
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons( PORT );
    

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0){
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 3) < 0){
        perror("listen");
        exit(EXIT_FAILURE);
    }
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0){
        perror("accept");
        exit(EXIT_FAILURE);
    }

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
        send(new_socket, tempo, strlen(tempo)+1, 0);
        strcpy(newstrings[j], tempo);
        char id[10];
        read( new_socket , id , 3);
        printf("%s\n", id);

    }
    
    return 0;
    
}

/* Part of code is referred from geeksforgeeks for practical usage in this assignment.*/

