#include<stdio.h>
#include<stdlib.h>

struct heap{
    int *array;
    int capacity;
    int count;
    int type;
};

struct heap* create(int capacity, int type){
    struct heap *h=(struct heap*)malloc(sizeof(struct heap));
    if(!h){
        printf("ERROR");
        return NULL;
    }
    h->capacity=capacity;
    h->count=0;
    h->type=type;
    h->array=(int*)malloc(sizeof(int)*capacity);
    if(!h->array){
        printf("ERROR");
        return NULL;
    }
    return h;
}

int parent(struct heap *h, int i){
    if(i<=0||i>=h->count){
        return -1;
    }
    return (i-1)/2;
}

int left(struct heap *h, int i){
    int left = 2*i+1;
    if(left>=h->count){
        return -1;
    }
    return left;
}

int right(struct heap *h, int i){
    int right = 2*i+2;
    if(right>=h->count){
        return -1;
    }
    return right;
}

int get_maximum_element(struct heap *h){
    if(h->count==0){
        return -1;
    }
    return h->array[0];
}

void purculate_down(struct heap *h, int i){
    int l=left(h,i);
    int r=right(h,i);
    int max=i;
    if(l != -1 && h->array[l] > h->array[max])
    max = l;
    if(r != -1 && h->array[r] > h->array[max])
    max = r;
    if(max!=i){
        int t=h->array[max];
        h->array[max]=h->array[i];
        h->array[i]=t;
        purculate_down(h,max);
    }
}

int deleteMax(struct heap *h){
    int data;
    if(h->count==0){
        return -1;
    }
    data=h->array[0];
    h->array[0]=h->array[h->count-1];
    h->count--;
    purculate_down(h,0);
    return data;
}

void resizeHeap(struct heap *h){
    int *old_array=h->array;
    h->array=(int*)malloc(sizeof(int)*h->capacity*2);
    if(!h->array){
        printf("ERROR");
        return;
    }
    h->capacity*=2;
    for(int i=0;i<h->count;i++){
        h->array[i] = old_array[i];
    }
    free(old_array);
}

int insert_Element_Parculate_up(struct heap *h, int data){
    if(h->count==h->capacity)
        resizeHeap(h);
    h->count++;
    int i = h->count -1;
    while(i>0&&data>h->array[(i-1)/2]){
        h->array[i]=h->array[(i-1)/2];
        i=(i-1)/2;
    }
    h->array[i]=data;
}

void destroyHeap(struct heap *h){
    if(!h)return;
    free(h->array);
    h->array=NULL;
    free(h);
    h=NULL;
}

void Heapify(struct heap *h, int a[], int n){
    if(h==NULL){
        return;
    }
    if(h->capacity<n){
        resizeHeap(h);
    }
    for(int i=0;i<n;i++){
        h->array[i]=a[i];
    }
    h->count=n;
    for(int i=(n-1)/2;i>=0;i--){
        purculate_down(h,i);
    }
}

int* sortHeap(int a[], int n){
    struct heap *h = create(n,1);
    if(!h){
        printf("ERROR");
        return NULL;
    }
    Heapify(h,a,n);
    int old_size = n;
    for(int i=n-1;i>0;i--){
        int temp = h->array[0];
        h->array[0]=h->array[h->count-1];
        h->array[h->count-1]=temp;
        h->count--;
        purculate_down(h,0);
    }
    h->count=old_size;
    return h->array;
}

void main(){
    int arr[]={9,8,7,6,5,4,3,2,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    printf("--- BEFORE SORTING--- \n");
    for(int k=0;k<n;k++)
        printf("%d",arr[k]);
    int *array = sortHeap(arr,n);
    printf("\n--- AFTER SORTING--- \n");
    for(int k=0;k<n;k++)
        printf("%d",array[k]);
}