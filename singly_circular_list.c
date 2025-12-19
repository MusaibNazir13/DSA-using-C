#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node * tail = NULL;

struct Node * createNode(int data){
    struct Node * newNode = (struct Node *)malloc(sizeof(struct Node)); 
    if(!newNode){
        printf("memo allocation failed");
        exit(1);
    }
    newNode->data=data;
    newNode->next=NULL;

    return newNode;
}
struct Node * insertBeg(int data){
    struct Node * nNode = createNode(data);
    if (tail==NULL)
    {
        nNode->next = nNode;
        return nNode;
    }
    nNode->next = tail->next;
    tail->next = nNode;
    return tail;    
}

void display(){
    if (tail==NULL)
    {
        printf("Empty List, there is nothing to print");
        return;
    }
    
    struct Node * temp = tail->next;
    do{
        printf("%d -> ",temp->data);
        temp=temp->next;
    }while(temp!=tail->next);

}
int main(){
        tail=insertBeg(45);
        insertBeg(10);
        insertBeg(60);
        display();
}