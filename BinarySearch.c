#include<stdio.h>

int BS(int arr[], int i, int j, int key){
    if(i>j){
        return -1;
    }
    int mid = (i+j)/2;
    if(arr[mid]==key)
        return mid;
    else if(arr[mid]<key)
        return BS(arr,mid+1,j,key);
    else
        return BS(arr,i,mid-1,key);
}

void main(){
    int arr[]={1,2,3,4,158,6,7,8,9};
    int i=0;
    int j=sizeof(arr)/sizeof(arr[0]);
    int key;
    printf("--- ENTER KEY ---\n");
    scanf("%d",&key);
    int ch=BS(arr,i,j-1,key);
    if(ch==-1)
        printf("NOT FOUND!...");
    else
        printf("Key found at position: %d",ch+1);
}