#include <stdio.h>

//** Function Protoypes **
int Strlen(char *str);

int main(int argc, char *argv[]){
    char str[]="Hello";

    printf("%s:%d\n",str,Strlen(str));

    return 0;
}

int Strlen(char *str){
    int len=0;

    while(*str!='\0'){
        len++;
        str++;
    }
    return len;
}