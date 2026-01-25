#include<stdio.h>

#define MAX 10 // Range of bucket sort.
void insertion(float arr[], int n){
    for(int i=1;i<n;i++){
        float key=arr[i];
        int j= i-1;
        while(j>=0&&arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}
void bucketSort(float arr[], int n){
    float buckets[MAX][n];
    int count[MAX]={0};
    for(int i=0;i<n;i++){
        int index = arr[i]*MAX;
        buckets[index][count[index]++] = arr[i];
    }
    for(int i=0;i<MAX;i++){
        insertion(buckets[i],count[i]);
    }   
    int k=0;
    for(int i=0;i<MAX;i++){
        for(int j=0;j<count[i];j++){
            arr[k++]= buckets[i][j];
        }
    }
}

void main(){
    float arr[]={0.90,0.98,0.77,0.36,0.45,0.94,0.39,0.18,0.12};
    int n=sizeof(arr)/sizeof(arr[0]);
    printf("--- BEFORE SORTING--- \n");
    for(int k=0;k<n;k++)
        printf("%f",arr[k]);
    bucketSort(arr,n);
    printf("\n--- AFTER SORTING--- \n");
    for(int k=0;k<n;k++)
        printf("%f",arr[k]);
}
