#include<stdio.h>

int partition(int arr[], int i, int j){
    int pivot = arr[i];
    int p= i+1;
    int q = j;
    int temp;
    while(p<=q){
        while(p<=j&&arr[p]<=pivot)
            p++;
        while(arr[q]>pivot)
            q--;
        if(p<q){
            temp=arr[p];
            arr[p]=arr[q];
            arr[q]=temp;
        }
    }
    arr[i]=arr[q];
    arr[q]=pivot;
    return q;
}

void quickSort(int arr[], int i, int j){
    if(i<j){
        int p=partition(arr,i,j);
        quickSort(arr,i,p-1);
        quickSort(arr,p+1,j);
    }
}

void main(){
    int arr[]={9,8,7,6,5,4,3,2,2,1};
    int i=0;
    int j=sizeof(arr)/sizeof(arr[0]);
    printf("--- BEFORE SORTING ---\n");
    for(int k=0;k<j;k++)
        printf("%d",arr[k]);
    quickSort(arr,i,j-1);
    printf("\n--- AFTER SORTING ---\n");
    for(int k=0;k<j;k++)
        printf("%d",arr[k]);
}