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

struct dNode * endInsert(struct dNode * head, int data){
        struct dNode * nNode = newNode(data);    
        if(head==NULL) return (head = nNode);
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
        
        if(pos<1){ printf("Position value must be > = 1\n"); return head; }
        if(pos==1){ head = begInsert(head,data); return head; }
        struct dNode * nNode = newNode(data);
        struct dNode * ptr = head;

       

        while (ptr!=NULL && pos!=2)
        {
            ptr=ptr->next;
            pos--;    
        }
        if(ptr==NULL){head = endInsert(head,data); return head;}
        nNode->next = ptr->next;
        ptr->next->prev = nNode;
        ptr->next = nNode;
        nNode->prev = ptr;

        return head;
}

struct dNode *del_beg(struct dNode *head){
        if(head==NULL) printf("List is already empty");
        struct dNode * temp = head; 
        head=head->next;
        free(temp);
        if (head!=NULL)
        {
            head->prev=NULL;
        }
        
       
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

        printf("The Forward Traversal of DL List using next pointer: ");
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