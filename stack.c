#include <stdio.h>
#define max_size 10

int stck_arr[max_size];
int top = -1; //This -1 indicates the stack as empty as 1 is not valid var 
void push(int data){
    if(top==max_size-1){
        printf("Stack Overflow");
        return;
    }
        top++;
        stck_arr[top]=data;
        printf("\n|%d| is pushed to stack\n",stck_arr[top]);
}
void pop(){
    if (top==-1)
    {
        printf("\nStack Underflow/Stack Empty.\n");
        return;
    }
    printf("\n %d is popped/deleted from stack.",stck_arr[top]); //this just creates an illusion the data is deleted
    top--; //data is still in there just the top is not pointing to it, when the new data is pushed then only it will get replaced by new value
}
int main(){
        int choice;
        int value;

        while (1)
        {
            printf("\nPress 1 to Push, 2 to Pop, 3 to exit: ");
            scanf("%d",&choice);
          switch (choice)
          {
          case 1:
            printf("\nWhat do you want to push to stack: ");
            scanf("%d",&value);
            push(value);
            break;
          case 2:
            pop();
            break;
          case 3:
            return 0;  
          default:
            printf("The option you entered is invalid");
            break;
          }
        }
        

        // push(10);
        // push(12);
        // push(30);
        // pop();
        // push(40);
        // pop();
        // pop();
        // pop();
}