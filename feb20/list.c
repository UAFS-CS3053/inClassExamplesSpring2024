#include <stdio.h>
#include <stdlib.h>

struct node{
    int value;
    struct node *next;
};
typedef struct node Node;

//*** Function Prototypes ***
struct node *createNode(int value);
void push(struct node **head,int value);
int pop(struct node **head);
void showList(struct node *head);

int main(int argc, char *argv[]){
    struct node *head=NULL;
    int index;


    for(index=0;index<5;index++){
        push(&head,(index*10));
    }
    
    showList(head);
    return 0;

}

struct node *createNode(int value){
    struct node *newNode = malloc(sizeof(struct node));
    if(newNode==NULL){
        printf("Memery Allocation Eroor\n");
        exit(1);
    }
    newNode->value=value;
    newNode->next=NULL;
    return newNode;
}

void push(struct node **head,int value){
    struct node *newNode = createNode(value);
    if(*head!=NULL){
        newNode->next = *head;
    }
    *head = newNode;
}

int pop(struct node **head){
    struct node *temp = *head;
    int value = (*head)->value;
    *head = (*head)->next;
    free(temp);
    return value;
}

void showList(struct node *head){
    while(head !=NULL){
        printf("Node Address: %p\n",head);
        printf("Value: %d\n",head->value);
        printf("Next:  %p\n",head->next);
        printf("------------------------\n");
        head = head->next;
    }
}

