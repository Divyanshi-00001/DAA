#include<stdio.h>

void bubbleSort(int arr[], int n){
    int i, j, temp, swapped=1;
    for(i=0;i<n-1&&swapped;i++){
        swapped=0;
        for(j=0;j<n-1-i;j++){
            if(arr[j]>arr[j+1]){
                swapped=1;
                temp = arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}

void main(){
    int arr[]={9,8,7,6,5,4,3,2,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    printf("--- BEFORE SORTING--- \n");
    for(int k=0;k<n;k++)
        printf("%d",arr[k]);
    bubbleSort(arr,n);
    printf("\n--- AFTER SORTING--- \n");
    for(int k=0;k<n;k++)
        printf("%d",arr[k]);
}