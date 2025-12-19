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

int main(){

}