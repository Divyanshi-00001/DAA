#include<stdio.h>

void insertion(int arr[], int n){
    int i,j;
    for(j=1;j<n;j++){
        int key=arr[j];
        i=j-1;
        while(i>=0){
            if(arr[i]>key){
                arr[i+1]=arr[i];
                i--;
            }
        }
        arr[i+1]=key;
    }
}

void main(){
    int arr[]={9,8,7,6,5,4,3,2,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    printf("--- BEFORE SORTING--- \n");
    for(int k=0;k<n;k++)
        printf("%d",arr[k]);
    insertion(arr,n);
    printf("\n--- AFTER SORTING--- \n");
    for(int k=0;k<n;k++)
        printf("%d",arr[k]);
}