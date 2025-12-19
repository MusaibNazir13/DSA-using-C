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
struct Node * insertEnd(int data){
    struct Node * nNode = createNode(data);
    if(tail == NULL){
        nNode->next = nNode;
        return nNode;
    }
    nNode->next = tail->next;
    tail->next = nNode;
    return nNode;
}
struct Node * insertAtPos(int pos,int data){
    struct Node * nNode = createNode(data);
    if(tail==NULL){
        nNode->next = nNode;
        printf("\nBecause the the list is empty this node is inserted as head/tail");
        return nNode;
    }
    struct Node * temp = tail->next;
    
    if (pos==1)
    {
        return insertBeg(data);
    }
    

    while (pos!=2)
    {
        temp = temp->next;
        if (temp==tail->next)
        {
            return insertEnd(data);
        }
         pos--;
    }
    nNode->next=temp->next;
    temp->next = nNode;

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
        tail = insertEnd(41); 
        tail = insertAtPos(4,20);
        display();

}