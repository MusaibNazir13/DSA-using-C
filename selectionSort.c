#include <stdio.h>
#include <limits.h>

void swap(int arr[],int a , int b){
    int temp = arr[a];
    arr[a]=arr[b];
    arr[b]=temp;
}

void selectionSort(int arr[],int n){

    for(int i = 0 ;i < n-1;i++){
        int min = i;
        for(int j = i + 1 ; j < n; j++){
            //finds the min value
            if(arr[j]<arr[min]){
                min = j;
            }
        }
        //swaps the min value with the crnt pointing value
        swap(arr,min,i);
    }
}


void traverseArray(int arr[],int n){
    for(int i = 0; i < n;i++){
        printf("%d ",arr[i]);
    }
}
int main(){
        int arr[]={45,21,46,212,30};
        int size = sizeof(arr)/sizeof(arr[0]);

        printf("\nBefore the selection sort: ");
        traverseArray(arr,size);
        
        selectionSort(arr,size);

        printf("\nAfter the selection sort: ");
        traverseArray(arr,size);
}