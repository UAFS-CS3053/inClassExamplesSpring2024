#include <stdio.h>


void changeValue(int *val, int newval);

int main(int argc, char*argv[]){
    int value=5;
    int *ptr;
    int **dptr;
    

    printf("val[%p]: %d\n", &value, value);
    printf("ptr[%p]:  %p -> %d\n",&ptr,ptr,*ptr);
    printf("dptr[%p]:  %p -> %p -> %d\n",&dptr,dptr,*dptr,**dptr);

    changeValue(&value,10);
    printf("val[%p]: %d\n", &value, value);
    return 0;
}


void changeValue(int *val, int newval){
    *val = newval;
}