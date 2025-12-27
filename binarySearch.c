//to apply this search the ds must be sorted
//the access to any element in the ds should require constant time, because we need the mid value to be compared, reaching mid of the linked list like ds will be ineffecient in this binary search
#include <stdio.h>

int binarySearch(int arr[],int n, int key){
    int low = 0;
    int high = n-1;
    
    while(low<=high){
        int mid = low + (high-low)/2;
        
        if (arr[mid]==key)
        {
            return mid;
        }
        // if the value is greater than mid then leave the left half
        if (arr[mid]<key)
        {
            low = mid+1;
        }
        // if the value is less than mid then leave the right half
        if (arr[mid]>key)
        {
            high = mid - 1;
        } 
    }
    return -1;
}
int main(){
    int arr[]={10,15,21,56,70,89};
    int size = sizeof(arr)/sizeof(arr[0]);
    int search = 98;
    int index = binarySearch(arr,size,search);
    if(index==-1)printf("\n%d was not found in the array.\n",search);
    else printf("%d is found at positon %d",search,index);
}