#include <stdio.h>

#define SIZE 10
#define TRUE 1
#define FALSE 0

/*** Function Prototypes ***/
void loadArray(int array[],int size);
void showArray(int array[],int size);

int main(int argc, char *argv[]){
    int numbers[SIZE];
    char ch[]={'A','B','C'};
    char str[]="Hello";
 
    loadArray(numbers,SIZE);
    showArray(numbers,SIZE);
    printf("%s\n",ch);

    return 0;
}

void loadArray(int array[],int size){
   int index;

    for(index=0;index<SIZE;index++){
        array[index] = 10 + index;
    }
}


void showArray(int array[],int size){
   int index;

    for(index=0;index<SIZE;index++){
        printf("%d\n",array[index]);
    }
}
