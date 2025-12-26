#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct Node{
    int data;
    struct Node * left;
    struct Node * right;
}tNode;

tNode * newNode(int data){
    tNode * nNode = (tNode *)malloc(sizeof(tNode));
    if (!nNode)
    {
        printf("Memo allocation failed");
        exit(1);
    }
    
    nNode->data = data;
    nNode->left = NULL;
    nNode->right = NULL;

    return nNode;
}
//recursive method of inserting nodes in bst, it is easy logic but not effecient in terms of memory usage it can cause stack overflow as uses stack to keep track of the recursive calls
//iterative method is used when it comes to practical usage in real world problems, and doesn't use much memory, no stack overflow, uses a bit more lines of code but is slighlty faster than recursive method
tNode * insertNode(tNode* root,int data){
    
    if (root==NULL){   return newNode(data);    }

    if(data<root->data){
        root->left = insertNode(root->left,data);
    }else{
        root->right = insertNode(root->right,data);
    }
    return root;
}

void inOrderTraverse(tNode *root){
    if (root==NULL)
    {
       return;
    }
    
    inOrderTraverse(root->left);
    printf("%d ",root->data);
    inOrderTraverse(root->right);
}



//this is Qn: 5 from the assignment: Inorder traversal without the recursion
#define MAX 100
tNode * stack[MAX];
int top = -1;
void push(tNode * cNode){
    //will increment the top 1st pointing to new index and then will just push the address onto the index top of the stack 
    stack[++top] = cNode;
}
tNode *pop(){
    //will return the address of the node at the index top and then decrement the top
    return stack[top--];
}

void inOrderNoRec(tNode * root){
    tNode * crnt = root;   
    
    while (crnt!=NULL || top!=-1)        
    {
        while (crnt!=NULL)
        {
            push(crnt);
            crnt=crnt->left;
        }
        
        crnt = pop();
        printf("%d ",crnt->data);
        crnt=crnt->right;
    }
    
}

void preOrder(tNode *root){
    if (root==NULL)
    {
       return;
    }
    printf("%d ",root->data);
    inOrderTraverse(root->left);
    
    inOrderTraverse(root->right);
}
void postOrder(tNode *root){
    if (root==NULL)
    {
       return;
    }
    
    inOrderTraverse(root->left);
    
    inOrderTraverse(root->right);
    printf("%d ",root->data);
}
tNode *buildBst(tNode * root,int arr[],int size){
    
    for (int i = 0; i < size; i++)
    {
        root = insertNode(root,arr[i]);
    }
       return root;
}

bool searhBst(tNode * root,int key){
    if (root == NULL){  return false;  }
    if (root->data==key)
    {
        return true;
    }else if (root->data > key)
    {
        return searhBst(root->left,key);
    }else{
        return searhBst(root->right,key);
    }
}

//InorderSucc: the leftmost node in the right sub-tree : used in this version
//Also we can replace the root with the Inorder-Predecessor: The rightmost node in the left subtree
tNode * getInOrderSuccessor(tNode * currRt){
        currRt = currRt->right;
        while(currRt!=NULL && currRt->left!=NULL){
            currRt = currRt->left;
        }
        return currRt;
}

tNode * delNode(tNode * root,int data){
    //this is the base case that handles the below recursive algo , helps when the the recursive algo is going deep down , as soon as it strikes the NULL value it returns back to previous call stack
    if (root==NULL)    return root;
    //these below two lines is what gives this tree a name Binary Search Tree , it replicates the behaviour of binary search, it halves the search space every time it compares the root with it , hence Time Complexity O(log n)
    if(root->data > data) root->left = delNode(root->left,data);
    else if(root->data < data) root->right = delNode(root->right,data);
    else{
        //handles the deletion of the node where node has 0 or 1 child
        if(root->left==NULL) {
            tNode * temp = root->right; 
            free(root);
            return temp;
        }    
        if(root->right == NULL){
            tNode * temp = root->left;
            free(root);
            return temp;
        }
        //below code handles when the node has two children
        tNode * succ = getInOrderSuccessor(root);
        root->data = succ->data;
        root->right = delNode(root->right,succ->data);        
    }
    return root;
}
int main(){
    tNode * root = NULL;
    int arr[]={45,20,65,10,30,55,70,25};
    int size = sizeof(arr)/sizeof(arr[0]);
    root=buildBst(root,arr,size);

    int findElement = 55;
    printf("\nThe element %d %s\n",findElement,searhBst(root,findElement)?" found":" not found");

    printf("This is inorder without recursion: ");
    inOrderNoRec(root);
    printf("\nThis is In Order with recursive fn: ");
    inOrderTraverse(root);
    printf("\nThis is Pre Order traversal using recursion: ");
    preOrder(root);
    printf("\nThis is Post Order traversal using recursion: ");
    postOrder(root);  

    int delElement = 70;
    delNode(root,delElement);
    printf("\n%d deleted\n",delElement);
    inOrderTraverse(root);  
}