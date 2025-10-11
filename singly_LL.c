#include <stdio.h>
#include <stdlib.h>

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
       struct sNode * node= newNode(data);
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
            printf("Position you entered is greater than the present nodes hence appending your data/node at end \n");
            head= insertAtEnd(head,data);
            return head;
            
        }
                npNode->next= crnt->next;
                crnt->next = npNode;
        
        
        
        return head;
}

struct sNode *del_1st(struct sNode *head){
    if(head==NULL){
        printf("List is already Empty ");
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
        printf("List is already Empty ");
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

int main(){
        struct sNode * head = NULL;
        head = insertAtBeg(head, 19);
        head = insertAtBeg(head, 12);
        head = insertAtBeg(head, 46);
        head = insertAtEnd(head,78);
        head = insertAtPos(head,1, 100);

        // head= del_1st(head);
        // head= del_1st(head);
        // head= del_1st(head);
        // head=del_1st(head);
        // head=del_last(head);
        


        struct sNode * ptr = head;
        while (ptr!=NULL)
        {
                printf("-> %d ",ptr->data);
                ptr=ptr->next;
        }
            /*Note: below lines are just for rough understanding
                head=(struct sNode*)malloc(sizeof(struct sNode));
                head->data=45;
                head->next=NULL;
                printf("%d",head->data);
            */


        return 0;
}