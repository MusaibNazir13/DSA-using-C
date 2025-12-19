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
        free(nNode);
        return insertBeg(data);
    }
    
    
    for(int i = 1; i < pos-1;i++)
    {
        temp = temp->next;
        if (temp->next==tail->next)
        {
            free(nNode);
            tail = insertEnd(data); //if the position is not valid appending it to last pos instead
            return tail;
        }
         printf("\n%d\n",i);
    }
   
    nNode->next=temp->next;
    temp->next = nNode;

    return tail;
}
void deleteBeg(){
    if (tail==NULL)
    {
        printf("\nAlready Empty");
        return;
    }
    if(tail->next==tail){
       free(tail);
       tail = NULL;
       return;
    }
    struct Node * temp = tail->next;
    tail->next = tail->next->next;
    free(temp);
}
void deleteEnd(){
    if(tail==NULL){
        printf("\nAlready empty.");
        return;
    }
    if(tail->next==tail){
       free(tail);
       tail = NULL;
       return;
    }
    struct Node * temp = tail->next;

    while(temp->next!=tail){
        temp=temp->next;
    }
    
    temp->next=tail->next;
    free(tail);
    tail = temp;
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
        tail = insertAtPos(3,20);
        deleteBeg();
        deleteBeg();
        // deleteBeg();
        // deleteBeg();
        // deleteBeg();
        // deleteBeg();
        deleteEnd();
        deleteEnd();
        deleteEnd();
        display();

}