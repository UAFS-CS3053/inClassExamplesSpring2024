#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv()){
    char *str;

    str = malloc(sizeof(char) * 10);
    if(str==NULL){
        exit(1);
    }
   strcpy(str,"Hello");
   printf("%s\n",str);

   free(str);

    return 0;
}