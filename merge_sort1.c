#include<stdio.h>
#include<limits.h>

void merge(int arr[], int i, int mid, int j){
    int n1= mid-i+1;
    int n2= j-mid;
    int l[n1+1], r[n2+1];
    int m, n;
    for(m=0;m<n1;m++){
        l[m]=arr[i+m];
    }
    l[m]=INT_MAX;
    for(n=0;n<n2;n++){
        r[n]=arr[mid+1+n];
    }
    r[n]=INT_MAX;
    m=0,n=0;
    for(int k=i;k<=j;k++){
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
    int i=0, j=sizeof(arr)/sizeof(arr[0]);
    printf("--- BEFORE SORTING--- \n");
    for(int k=0;k<j;k++)
        printf("%d",arr[k]);
    mergeSort(arr,i,j-1);
    printf("\n--- AFTER SORTING--- \n");
    for(int k=0;k<j;k++)
        printf("%d",arr[k]);
}