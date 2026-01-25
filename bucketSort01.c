#include<stdio.h>
#define N 10

void insertion(float arr[], int n){
    for(int i=1;i<n;i++){
        float key = arr[i];
        int j=i-1;
        while(j>=0&&arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        if(i!=j)
        arr[j+1]=key;
    }
}

void bucketSort(float arr[], int n){
    float bucket[N][n];
    int count[N]={0};
    for(int i=0;i<n;i++){
        int index = arr[i]*10;
        bucket[index][count[index]++]=arr[i];
    }
    for(int i=0;i<N;i++){
        insertion(bucket[i],count[i]);
    }
    int k=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<count[i];j++){
            arr[k++]=bucket[i][j];
        }
    }
}

void main(){
    float arr[]={0.02,0.49,0.47,0.72,0.36};
    int n=sizeof(arr)/sizeof(arr[0]);
    printf("--- BEFORE SORTING ---\n");
    for(int i=0;i<n;i++){
        printf("%f ",arr[i]);
    }
    bucketSort(arr,n);
    printf("\n--- AFTER SORTING ---\n");
    for(int i=0;i<n;i++){
        printf("%f ",arr[i]);
    }
}

