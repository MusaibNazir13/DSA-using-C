#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct sNode{
    int data;
    struct sNode* next;
};

struct sNode * newNode(int data){
        struct sNode * nNode=malloc(sizeof(struct sNode));
        nNode->data=data;
        nNode->next=NULL;
        return nNode;
}     

struct sNode * insertAtBeg(struct sNode * head, int data){
       struct sNode * node = newNode(data);
       node->next=head;

       return node;
}

struct sNode *insertAtEnd(struct sNode *head,int data){
        struct sNode *lNode = newNode(data);
        
        if (head==NULL)
        {
               return lNode;
        }
        struct sNode *crnt = head;
                while (crnt->next!=NULL)
                {
                        crnt=crnt->next;
                }
                crnt->next=lNode;
                
     
      return head;  
}


struct sNode* insertAtPos(struct sNode *head,int pos , int data){
        struct sNode *npNode = newNode(data);
        
        if(pos<1){
            printf("The position entered in not valid.Make sure you enter > or = 1 position \n");
            return head;
        }
        
        if(head==NULL || pos == 1){
                head=insertAtBeg(head,data);
                return head;
        }
        
        struct sNode *crnt = head;
        
        while(crnt != NULL && pos-1!=1){
                
                crnt=crnt->next;
                pos--;
        }
        
        if(crnt==NULL){
            printf("Position you entered is greater than the present nodes.\nHence appending your data/node at end \n\n");
            head= insertAtEnd(head,data);
            return head;
            
        }
                npNode->next= crnt->next;
                crnt->next = npNode;
        
        
        
        return head;
}

struct sNode *del_1st(struct sNode *head){
    if(head==NULL){
        printf("\nList is already Empty ");
        return head;
    }
    struct sNode *temp = head;
    head= head->next;
    free(temp);
    temp=NULL;

    return head;
}

struct sNode * del_last(struct sNode *head){
    if(head==NULL){
        printf("\nList is already Empty ");
        return head;
    }
    // // Handling the single-node case
    if(head->next == NULL){
        free(head);
        head = NULL;
        return head;
    }
    struct sNode * tempCrnt=head;
    struct sNode * tempCrnt2=head;
    
    while(tempCrnt->next!=NULL){
        tempCrnt2=tempCrnt;
        tempCrnt=tempCrnt->next;
    }
    tempCrnt2->next = NULL;
    free(tempCrnt);
    tempCrnt = NULL;
  
    return head;
}

struct sNode * del_at_pos(struct sNode * head, int pos){
    if(head==NULL){
        printf("\nList is already empty. ");
        return head;
    }
    if(pos <= 0){
        printf("The postion entered is not valid in this case. \nTry to provide postion starting from 1. \n");
        return head;
    }
    
    if(pos == 1){
        head = del_1st(head);
        return head;
    }
    struct sNode * crnt = head;
    
    while (crnt!= NULL && pos-1!=1)
    {
        pos--;
        crnt=crnt->next;
    }
    if(pos>1){
        head = del_last(head);
        printf("\nThe postion u entered is greater than the present count of nodes.\nHence deleting last node.");
        return head;
    }
    
    crnt->next = crnt->next->next;

    return head;
}

struct sNode * reverse_list(struct sNode * head){
        if (head==NULL)
        {
            printf("\nThere is nothing to reverse.\n");
            return head;
        }
        
        //This is the 1st un refined version that reverses the data by using insertBeg
        // struct sNode * crntPtr = head;
        // while (crntPtr!=NULL)
        // {
        //     head = insertAtBeg(head,crntPtr->data);
        //     crntPtr=crntPtr->next;
        // }
        // printf("\nHere is the reversed list: ");
        struct sNode *crnt = head;
        struct sNode * prev = NULL;
        struct sNode * next = NULL;

        while(crnt!=NULL){
            next = crnt->next;
            crnt->next = prev;
            prev = crnt;
            crnt = next;
        }

        head = prev;

        return head;
}
struct sNode * merge_list(struct sNode * head1, struct sNode *head2){
    if (head1->next == NULL) return head2;
    if (head2->next == NULL) return head1;

    if (head1->data<=head2->data) 
    {
        head1->next = merge_list(head1->next,head2); 
        return head1;    
    }else{
        head2->next = merge_list(head2->next,head1);
        return head2;
    }
    //In this function I tried using recursive fn to merge the two sorted lists.
}
//Assignment Q2: Find the middle element of LL in a single pass
int findMiddleElement(struct sNode *head){
    struct sNode *steady = head;
    struct sNode *fast = head;
    // this logic follows the hare and tortoise logic : when fast one reaches the end the steady one will be in middle because the fast one is taking twice the step of steady
    while (fast!=NULL && fast->next!=NULL)
    {
        steady=steady->next;
        fast=fast->next->next;
    }
    return steady->data;    
}
//Assignment Q1: detect the cycle in the L-List
bool detectCycle(struct sNode *head){
    struct sNode *steady = head;
    struct sNode *fast = head;
    // this logic follows the hare and tortoise logic : when fast one reaches the end the steady one will be in middle because the fast one is taking twice the step of steady
    while (fast!=NULL && fast->next!=NULL)
    {
        steady=steady->next;
        fast=fast->next->next;
        if(fast==steady){return true;}
    }

    return false;    
}
int main(){
        struct sNode * head = NULL;
        head = insertAtBeg(head, 20);
        head = insertAtBeg(head, 25);
        head = insertAtBeg(head, 69);
        head = insertAtEnd(head,10);
                insertAtEnd(head,5);
                insertAtEnd(head,5);
                // insertAtEnd(head,5);
        // head = insertAtPos(head,1, 100);
        // head = insertAtPos(head,3, 200);
        // head = insertAtPos(head,10, 300);
        // head = insertAtPos(head,7, 400);

        // head = del_1st(head);
        // head = del_1st(head);
        // head = del_1st(head);
        // head =del_1st(head);
        // head =del_last(head);
        

        //  head = del_at_pos(head,10);
         
        //  head = del_at_pos(head,1);
        //  head = del_at_pos(head,6);

        int middle;
        //middle element in the even elemented list will be the 1 before the middle element 
        middle = findMiddleElement(head);
        printf("\nMiddle Element found in the L-List using a single pass: %d\n",middle);

        head = reverse_list(head);

        struct sNode * ptr = head;
        printf("(1st is Reversed Version)\nThe 1st Linked List: ");
        while(ptr!=NULL)
        {
                printf("-> %d ",ptr->data);
                ptr=ptr->next;
        }


        struct sNode * head2 = NULL;
        head2 = insertAtBeg(head2, 70);
        head2 = insertAtBeg(head2, 68);
        head2 = insertAtBeg(head2, 65);
        head2 = insertAtEnd(head2,80);
        // head2 = insertAtPos(head2,1, 20);
        // head2 = insertAtPos(head2,3, 200);
        // head2 = insertAtPos(head2,10, 300);
        // head2 = insertAtPos(head2,7, 400);

        

        printf("\nThe 2nd Linked List: ");
        struct sNode * ptr1 = head2;
        while(ptr1!=NULL)
        {
                printf("-> %d ",ptr1->data);
                ptr1=ptr1->next;
        }
            /*Note: below lines are just for rough understanding
                head=(struct sNode*)malloc(sizeof(struct sNode));
                head->data=45;
                head->next=NULL;
                printf("%d",head->data);
            */
        head = merge_list(head,head2);
        struct sNode * ptr2 = head;
        printf("\nThe merged list is: ");
        while(ptr2!=NULL)
        {
                printf("-> %d ",ptr2->data);
                ptr2=ptr2->next;
        }

        
        printf("\nBefore Creating cycle: %s\n",detectCycle(head)?"Cycle found.":"Cycle not found");
        //i am manually creating a cycle in this linked list for testing purpose
        ptr =  head;
        struct sNode * target = head->next;
        while (ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=target;
        
        printf("After manually creating cycle in the L-List : %s\n\n",detectCycle(head)?"Cycle found.":"Cycle not found");
       
        return 0;
}