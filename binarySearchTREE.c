#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    tNode * left;
    tNode * right;
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
//iterative method is used when it comes to practical usage in real world problems, and doesn't use much memory no stack overflow, uses a bit more lines of code but is slighlty faster than recursive method
tNode * insertNode(tNode* root,int data){
    
    if (root==NULL){   return newNode(data);    }

    if(data<root->data){
        root->left = insertNode(root->left,data);
    }else{
        root->right = insertNode(root->right,data);
    }
    return root;
}

tNode *buildBst(int arr[],int size){
    tNode * root = NULL;
    for (int i = 0; i < size; i++)
    {
        root = insertNode(root,arr[i]);
    }
    
}
int main(){
    int arr[]={50,30,70,20};
    int size = sizeof(arr)/sizeof(arr[0]);
    buildBst(arr,size);     
}