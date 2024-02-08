#include <stdio.h>

#define SIZE 5

int main(int argc, char *argv[]){
    int numbers[]={10,20,30,40,50};
    int index;
    int *ptr;

    ptr=numbers;

    for(index=0;index<SIZE;index++){
        printf("[%d]: %d - %d\n",index,numbers[index],*ptr);
        ptr++;
    }


    return 0;
}