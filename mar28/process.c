#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>


int main(int argc, char *argv[]){
    pid_t child;

    child=fork();
    if(child==0){
        //** Child **
        printf("Child: %d -> %d\n",getpid(),getppid());
        sleep(60);

    }else{
        //** Parent **
        printf("Parent: %d -> %d\n",getpid(),getppid());
        sleep(60);
    }

    return 0;
}