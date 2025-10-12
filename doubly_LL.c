#include <stdio.h>
#include <stdlib.h>

struct dNode{
    struct dNode * prev;
    int data;
    struct dNode * next;
};

struct dNode * newNode(int data){
        struct dNode * node = (struct dNode *)malloc(sizeof(struct dNode));
        node->data = data;
        node->next = NULL;
        node->prev = NULL;

        return node;
}

struct dNode * begInsert(struct dNode * head,int data){
    struct dNode *nNode = newNode(data);
    if (head==NULL){
        head=nNode;
        return nNode;
    }
    nNode->next = head;
    head->prev = nNode;
   return nNode; 
}

int main(){
        struct dNode * head = NULL;
        head = begInsert(head,45);
        head = begInsert(head,20);
        head = begInsert(head,10);
        head = begInsert(head,5);
        head = begInsert(head,1);

        printf("The Doubly Linked List is: ");
    struct dNode * ptr = head;
    while (ptr!=NULL)
    {  
        printf("<-> %d ",ptr->data);
        if(ptr->next == NULL) break;
        ptr=ptr->next;
    }

    printf("\nThe reverse traversal of DL List Using prev pointer: ");
    while (ptr!=NULL)
    {
        printf("<-> %d ",ptr->data);
        ptr=ptr->prev;
    }
    
    
}