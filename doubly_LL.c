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
        return nNode;
    }
    nNode->next = head;
    head->prev = nNode;
    return nNode; 
}

struct dNode * endInsert(struct dNode * head, int data){
    struct dNode * nNode = newNode(data);    
    if(head==NULL) return nNode;
    struct dNode * ptr = head;
    while (ptr->next!=NULL)   
    {
        ptr=ptr->next;
    }
    ptr->next = nNode;
    nNode->prev = ptr;
    return head;
}

struct dNode * inAt_pos(struct dNode *head,int pos,int data){
    if(pos<1){ printf("Position value must be >= 1\n"); return head; }
    if(pos==1){ return begInsert(head,data); }
    struct dNode * nNode = newNode(data);
    struct dNode * ptr = head;
    int count=1;
    while (ptr!=NULL && count < pos-1)
    {
        ptr=ptr->next;
        count++;    
    }
    if(ptr==NULL){
        printf("Position is greater than the length of the list. Inserting at end.\n");
        return endInsert(head,data);
    }
    nNode->next = ptr->next;
    nNode->prev = ptr;
    if(ptr->next!=NULL){
        ptr->next->prev = nNode;
    }
    ptr->next = nNode;
    return head;
}

struct dNode *del_beg(struct dNode *head){
    if(head==NULL) {printf("List is already empty\n"); return head;}
    struct dNode * temp = head; 
    head=head->next;
    free(temp);
    if (head!=NULL)
    {
        head->prev=NULL;
    }
    return head;
}

struct dNode *del_end(struct dNode *head){
    if(head==NULL) {printf("List is already empty\n"); return head;}
    if(head->next == NULL){
        free(head);
        return NULL;
    }
    struct dNode * ptr = head;
    while (ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    ptr->prev->next=NULL;
    free(ptr);
    return head;
} 

struct dNode * delAt_pos(struct dNode * head,int pos){
    if(head==NULL) {printf("List is already empty\n"); return head;}
    if(pos < 1) {printf("Position value must be >= 1\n"); return head;}
    struct dNode * ptr = head;
    int count = 1;
    while(ptr!=NULL && count < pos){
        ptr=ptr->next;
        count++;  
    }
    if(ptr==NULL){
        printf("Position is out of bounds. No deletion performed.\n");
        return head;
    }
    if(ptr->next == NULL){
        return del_end(head);
    }
    if(ptr==head){
        return del_beg(head);
    }
    struct dNode *temp = ptr;
    ptr->prev->next = ptr->next;
    ptr->next->prev = ptr->prev;
    free(temp);
    return head;
}

int main(){
    struct dNode * head = NULL;
    head = begInsert(head,45);
    head = begInsert(head,20);
    head = begInsert(head,10);
    head = begInsert(head,5);
    head = begInsert(head,1);

    head = endInsert(head,50);

    head = inAt_pos(head,3,80);

    head = del_beg(head);

    head = del_end(head);
    head = del_end(head);

    head = delAt_pos(head,4);

    printf("The Forward Traversal of DL List using next pointer: ");
    struct dNode * ptr = head;
    struct dNode * ptr2 = NULL;
    while (ptr!=NULL)
    {  
        printf("<-> %d ",ptr->data);
        ptr2=ptr;
        ptr=ptr->next;
    }

    printf("\nThe reverse traversal of DL List Using prev pointer: ");
    while (ptr2!=NULL)
    {
        printf("<-> %d ",ptr2->data);
        ptr2=ptr2->prev;
    }
}