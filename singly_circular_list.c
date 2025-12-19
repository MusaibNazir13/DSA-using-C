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
            printf("\ninvalid position , hence appending at last");
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
    printf("\n%d deleted at beginning.",temp->data);
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
    printf("\n%d deleted at end",tail->data);
    free(tail);
    tail = temp;
}
void deletePos(int pos){
    if (tail==NULL)
    {
        printf("already empty");
    }
    if(tail->next==tail){
        free(tail);
        tail=NULL;
        return;
    }
    struct Node * temp = tail->next;
    for(int i=0; i < pos-1; i++){
        temp=temp->next;
        if (temp->next==tail)
        {
            printf("\nthe position is invalid.");
            return;
        }
        
    }
    struct Node * temp2 = temp->next;
    temp->next = temp->next->next;
    printf("\n%d deleted at %d",temp->data,pos);
    free(temp);
    free(temp2);
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

void menu(){
    printf("\n1 : for Insert At beginning\n2: for insert at end\n3: for insert at any pos\n4: for delete at beginning\n5: for delete at pos\n6: for delete at end\n7: for displaying the list\n8: for HELP MENU\n9: for Exit");
}
int main(){
        int choice;
        int data;
        int pos;
        menu();
       while(1){
        
        printf("\nEnter your choice: ");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter the data you want to insert at beginning (Integer value): ");
            scanf("%d",&data);
            tail=insertBeg(data);
            break;
        case 2:
            printf("\nEnter the data you want to insert at ending (Integer value): ");
            scanf("%d",&data);
            tail=insertEnd(data);
            break;
        case 3:
            printf("\nEnter the data & pos separated by space respectively (Integer value): ");
            scanf("%d %d",&data,&pos);
            tail=insertAtPos(pos,data);
            break;
        case 4:
            deleteBeg();   
            break;
        case 5:
            printf("\nEnter the position you want to delete: ");
            scanf("%d",&pos);
            deletePos(pos);
            break;
        case 6:
            deleteEnd();
            break;
        case 7:
            printf("Here is the list: ");
            display();
            break; 
        case 8:
            menu();    
            break;
        case 9:
            printf("Good Bye...........");
            exit(1);               
        default:
            printf("\nThe choice entered is invalid");
            break;
        }
    }

}

