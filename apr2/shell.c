#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <wait.h>


#define BUFSIZE 1024
#define TRUE 1

//extern char **environ;

int main(int argc, char *argv[], char **environ){
    char buffer[BUFSIZE];
    pid_t child;
    int status;

    while(TRUE){
        printf("shell> ");
        fgets(buffer,BUFSIZE-1,stdin);
        buffer[(strlen(buffer)-1)]='\0';

        //** Internal Commands ***
        if(strcmp(buffer,"exit")==0){
            break;
        }else{
            child=fork();
            if(child==0){
                execvp(buffer,argv);
            }else{
                waitpid(-1,&status,0);
            }
        }

    }

    return 0;

}