#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char *argv[]){
    pid_t child;
    char buffer[1024];
    int fd[2];  //** File Descriptors for Pipe
    int bytes;

    if(pipe(fd)==-1){
        printf("Unable to Create Pipe...\n");
        exit(1);
    }

    child = fork();
    if(child==0){
        //*Childe Process
        close(fd[1]);
        bytes = read(fd[0],buffer,6);
        bytes = write(STDOUT_FILENO,buffer,6);
        bytes = read(fd[0],buffer,8);
        bytes = write(STDOUT_FILENO,buffer,8);
        close(fd[0]);

    }else{
        //* Parent Process
        close(fd[0]);
        bytes = write(fd[1],"Hello\n",6);
         bytes = write(fd[1],"GoodBye\n",8);
        close(fd[1]);
    }
}