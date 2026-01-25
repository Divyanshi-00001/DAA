#include<stdio.h>
#include<limits.h>

void merge(int arr[], int i, int mid, int j){
    int n1 = mid-i+1;
    int n2 = j-mid;
    int k;
    int l[n1+1], r[n2+1];
    for(k=0;k<n1;k++){
        l[k] = arr[i+k];
    }
    l[k]=INT_MAX;
    for(k=0;k<n2;k++){
        r[k]=arr[mid+1+k];
    }
    r[k]=INT_MAX;
    int m=0, n=0;
    for(k=i;k<=j;k++){
        if(l[m]<=r[n]){
            arr[k]=l[m++];
        }
        else    
            arr[k]=r[n++];
    }
}

void mergeSort(int arr[], int i, int j){
    if(i<j){
        int mid=(i+j)/2;
        mergeSort(arr,i,mid);
        mergeSort(arr,mid+1,j);
        merge(arr,i,mid,j);
    }
}

void main(){
    int arr[]={9,8,7,6,5,4,3,2,1};
    int i=0;
    int j= sizeof(arr)/sizeof(arr[0]);
    printf("--- BEFORE SORTING ---\n");
    for(int k=0;k<j;k++)
        printf("%d",arr[k]);
    mergeSort(arr,i,j-1);
    printf("\n--- AFTER SORTING ---\n");
    for(int k=0;k<j;k++)
        printf("%d",arr[k]);
}