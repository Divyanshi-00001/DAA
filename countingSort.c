#include<stdio.h>

void counting(int A[], int n, int k){
    int i, C[k], B[n];
    for(i=0;i<k;i++){
        C[i]=0;
    }
    for(i=0;i<n;i++){
        C[A[i]]+=1;
    }
    for(i=1;i<k;i++){
        C[i]=C[i]+C[i-1];
    }
    for(i=n-1;i>=0;i--){
        B[C[A[i]]-1]=A[i];
        C[A[i]]--;
    }
    for(i=0;i<n;i++){
        A[i]=B[i];
    }
}

void main(){
    int arr[]={9,8,7,6,5,4,3,2,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    printf("--- BEFORE SORTING--- \n");
    for(int k=0;k<n;k++)
        printf("%d",arr[k]);
    counting(arr,n,10);
    printf("\n--- AFTER SORTING--- \n");
    for(int k=0;k<n;k++)
        printf("%d",arr[k]);
}

