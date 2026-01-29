#include <stdio.h>
//#include <stdlib.h>

int partition(int arr[], int i, int j) {
    int pivot=arr[i];
    int p=i+1;
    int q=j;
    while(p<=q) {
        while(pivot>=arr[p]&&p<=j) {
            p++;
        }
        while(pivot<arr[q]) {
            q--;
        }
        if(p<q) {
            int temp = arr[p];
            arr[p] = arr[q];
            arr[q] = temp;
        }
    }
    if(p>q) {
        int temp = arr[i];
        arr[i] = arr[q];
        arr[q] = temp;
    }
    return q;
}

void QuickSort(int arr[], int i, int j) {
    if(i<j) {
        int col=partition(arr,i,j);
        QuickSort(arr,i,col-1);
        QuickSort(arr,col+1,j);
    }
}

void main() {
    int arr[]={9,8,7,6,5,4,3,2,2,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    printf("Array Before Sorting: ");
    for(int i=0;i<n;i++)
        printf("%d ", arr[i]);
    QuickSort(arr,0,n-1);
    printf("\nArray After Sorting: ");
    for(int i=0;i<n;i++)
        printf("%d ", arr[i]);
}