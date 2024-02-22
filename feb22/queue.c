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

void enQueue(struct node **head, struct node **tail, int value);
int deQueue(struct node **head, struct node **tail);


int main(int argc, char *argv[]){
    struct node *head=NULL;
    struct node *tail=NULL;
   
    int index, value;

    showList(head);

    for(index=0;index<5;index++){
        enQueue(&head,&tail,(index*10));
    }

    showList(head);
    
    for(index=0;index<5;index++){
        value = deQueue(&head,&tail);
        printf("DeQueued Value: %d\n",value);
    }
    showList(head);


    return 0;

}

struct node *createNode(int value){
    struct node *newNode = malloc(sizeof(struct node));
    if(newNode==NULL){
        printf("Memory Allocation Error\n");
        exit(1);
    }
    newNode->value=value;
    newNode->next=NULL;
    return newNode;
}

void enQueue(struct node **head, struct node **tail, int value) {
    struct node *newNode = createNode(value);
    if(*tail!=NULL){
        (*tail)->next = newNode;
    }
    *tail = newNode;
    //** If First Node of Queue **
    if(*head == NULL){
        *head = *tail;
    }
}

int deQueue(struct node **head, struct node **tail) {
    int value = pop(head);
    //** If Last Node of Queue **
    if(*head == NULL){
        *tail == *head;
    }
    return value;
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

