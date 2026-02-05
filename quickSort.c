#include <stdio.h>

void swap(int arr[],int i , int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int partition(int arr[],int start, int end){
    int i = start-1,pivot = end;
    for(int j = start;j < end;j++){
        if(arr[j]>=arr[pivot]){
            i++;
            swap(arr,i,j);
        }
    }
    i++;
    swap(arr,i,end);
    return i;
}
void quickSort(int arr[],int start, int end){
    if (start >= end) return;
        int pivot = partition(arr,start,end);
        quickSort(arr,start,pivot-1);
        quickSort(arr,pivot+1,end);
}
void traverseArray(int arr[],int size){
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
}
int main(){
    int arr[]= {5,4,3,6,4,2,1,45,21,54,21,12};
    int size = sizeof(arr)/sizeof(arr[0]);

    quickSort(arr,0,size-1);
    traverseArray(arr,size);

}