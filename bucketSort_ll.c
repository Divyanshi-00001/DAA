#include<stdio.h>
#include<stdlib.h>
#define N 10
struct node{
    float val;
    struct node *next;
};

struct node* merge(struct node *a, struct node *b);
struct node* sort_list(struct node *p){
    if(p==NULL||p->next==NULL){
        return p;
    }
    struct node *slow=p, *fast=p, *prev=NULL;
    while(fast && fast->next){
        prev=slow;
        slow=slow->next;
        fast=fast->next->next;
    }
    prev->next=NULL;
    struct node *left=sort_list(p);
    struct node *right=sort_list(slow);
    return merge(left,right);
}

struct node* merge(struct node *a, struct node *b){
    struct node dummy={0,NULL};
    struct node *temp=&dummy;
    while(a&&b){
        if(a->val<=b->val){
            temp->next=a;
            a=a->next;
        }
        else{
            temp->next=b;
            b=b->next;
        }
        temp=temp->next;
    }
    temp->next = (a) ? a : b;
    return dummy.next;
}

void bucketSort(float arr[], int n){
    struct node *bucket[N]={NULL};
    for(int i=0;i<n;i++){
        int index=arr[i]*N;
        struct node *p=(struct node*)malloc(sizeof(struct node));
        p->val=arr[i];
        p->next=bucket[index];
        bucket[index]=p;
    }
    for(int i=0;i<N;i++){
        bucket[i]=sort_list(bucket[i]);
    }
    /*int i=0;
    while(bucket[i]==NULL)i++;
    struct node *head=bucket[i];
    for(i=0;i<N;i++){
        struct node *temp=bucket[i];
        if(temp){
            while(temp->next!=NULL){
                temp=temp->next;
            }
            int j=i+1;
            while(j < N && bucket[j] == NULL) j++;
            if(j < N) temp->next = bucket[j];
        }
    }
    i=0;
    struct node *temp=head;
    while(temp!=NULL){
        arr[i++]=temp->val;
        temp=temp->next;
    }*/
    int k=0;
    for(int i=0;i<N;i++){
        struct node *temp=bucket[i];
        while(temp){
            arr[k++]=temp->val;
            temp=temp->next;
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