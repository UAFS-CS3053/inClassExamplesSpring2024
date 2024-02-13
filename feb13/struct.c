#include <stdio.h>
#include <stdlib.h>

struct node{
    int val1;
    int val2;
};

void fun1(struct node node1);
void fun2(struct node *node1);

int main(int argc, char *argv[]){
    struct node node1;

    printf("Size: %ld\n",sizeof(node1));

    node1.val1=10;
    node1.val2=20;

    fun1(node1);
    printf("Node:  %d  - %d\n",node1.val1,node1.val2);
    fun2(&node1);
    printf("Node:  %d  - %d\n",node1.val1,node1.val2);

    return 0;
}

void fun1(struct node node1){
    node1.val1=100;
    node1.val2=200;
    printf("Node:  %d  - %d\n",node1.val1,node1.val2);
}

void fun2(struct node *node1){
    node1->val1=100;
    node1->val2=200;
    printf("Node:  %d  - %d\n",node1->val1,node1->val2);
}