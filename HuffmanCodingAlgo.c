#include<stdio.h>
#include<stdlib.h>

struct binary_tree{
    int data;
    struct binary_tree *left;
    struct binary_tree *right; 
};

struct heap{
    int capacity;
    int count;
    struct binary_tree **array;
};

int leftChild(struct heap *h, int i){
    int left = 2*i+1;
    if(left>=h->count){
        return -1;
    }
    return left;
}

int rightChild(struct heap *h, int i){
    int right = 2*i+2;
    if(right>=h->count){
        return -1;
    }
    return right;
}

void puculateDown(struct heap *h, int i){
    int left = leftChild(h,i);
    int right = rightChild(h,i);
    int min = i;
    if(left!=-1 && h->array[left]->data < h->array[i]->data){
        min = left;
    }
    if(right!=-1 && h->array[right]->data < h->array[min]->data){
        min = right;
    }
    if(min!=i){
        struct binary_tree *temp = h->array[min];
        h->array[min] = h->array[i];
        h->array[i] = temp;
        puculateDown(h,min);
    }
}

struct heap* createHeap(int a[], int n){
    struct heap *h = (struct heap*)malloc(sizeof(struct heap));
    if(!h){
        printf("Error occured");
        return NULL;
    }
    h->capacity = h->count = n;
    h->array = (struct binary_tree**)malloc(n * sizeof(struct binary_tree*));
    for(int i=0;i<n;i++){
        h->array[i]=(struct binary_tree*)malloc(sizeof(struct binary_tree));
        h->array[i]->data= a[i];
        h->array[i]->left = h->array[i]->right = NULL;
    }
    for(int i=(n-1)/2;i>=0;i--){
        puculateDown(h,i);
    }
    return h;
}

void increaseSize(struct heap *h){
    struct binary_tree **temp = h->array;
    h->array = (struct binary_tree**)malloc(h->capacity*2*sizeof(struct binary_tree*));
    h->capacity*=2;
    for(int i=0;i<h->count;i++){
        h->array[i] = temp[i];
    }
    free(temp);
}

void insert_heap(struct heap *h, struct binary_tree *p){
    if(h->capacity == h->count){
        increaseSize(h);
    }
    h->count++;
    int i = h->count-1;
    while(i>0&&p->data<h->array[(i-1)/2]->data){
        h->array[i] = h->array[(i-1)/2];
        i=(i-1)/2;
    }
    h->array[i]=p;
}

struct binary_tree* extractMin(struct heap *h){
    if(h->count==0){
        return NULL;
    }
    struct binary_tree *temp = h->array[0];
    h->array[0]=h->array[h->count-1];
    h->count--;
    puculateDown(h,0);
    return temp;
}

struct heap* Huffman(int a[], int n){
    struct heap *h = createHeap(a,n);
    for(int i=1;i<n;i++){
        struct binary_tree *temp = (struct binary_tree*)malloc(sizeof(struct binary_tree));
        temp->left = extractMin(h);
        temp->right = extractMin(h);
        temp->data=temp->left->data+temp->right->data;
        insert_heap(h,temp);
    }
    return h;
}

void inorder(struct binary_tree *p){
    if(p){
        inorder(p->left);
        printf("%d ",p->data);
        inorder(p->right);
    }
}

void main(){
    //int arr[]={9,8,7,6,5,4,3,2,1};
    int arr[]={4,3,2,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    printf("--- BEFORE SORTING--- \n");
    for(int k=0;k<n;k++)
        printf("%d",arr[k]);
    struct heap *h = Huffman(arr,n);
    printf("\n--- AFTER SORTING--- \n");
    //for(int k=0;k<n;k++)
    //    printf("%d",arr[k]);
    inorder(h->array[0]);
}