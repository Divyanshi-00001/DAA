#include<stdio.h>
#include<limits.h>

void merge(int arr[], int i, int mid, int n){
    int n1= mid - i + 1;
    int k, n2 = n - mid;
    int l[n1+1],r[n2+1];
    for(k=0;k<n1;k++){
        l[k]=arr[i+k];
    }
    l[k]=INT_MAX;
    for(k=0;k<n2;k++){
        r[k]=arr[mid+1+k];
    }
    r[k]=INT_MAX;
    int p=0;
    int q=0;
    for(int k=i;k<=n;k++){
        if(l[p]<=r[q]){
            arr[k]=l[p++];
        }
        else
            arr[k]=r[q++];
    }
}

void mergeSort(int arr[],int i,int n){
    if(i<n){
        int mid = (i+n)/2;
        mergeSort(arr,i,mid);
        mergeSort(arr,mid+1,n);
        merge(arr,i,mid,n);
    }
}

void main(){
    int arr[100], n;
    printf("Enter the size of the array: ");
    scanf("%d",&n);
    printf("Enter elements of array: \n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    mergeSort(arr,0,n-1);
    printf("Sorted array:\n");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}

