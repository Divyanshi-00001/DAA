#include<stdio.h>
#include<stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* merge(struct ListNode *first, struct ListNode *second);
struct ListNode* sortList(struct ListNode* head) {
    struct ListNode *slow=head, *fast=head, *prev=NULL;
    if(head==NULL||head->next==NULL){
        return head;
    }
    while(fast&&fast->next){
        prev = slow;
        slow=slow->next;
        fast=fast->next->next;
    }
    prev->next=NULL;
    struct ListNode *left=sortList(head);
    struct ListNode *right=sortList(slow);
    return merge(left,right);
}

struct ListNode* merge(struct ListNode *a, struct ListNode *b){
    struct ListNode dummy={0,NULL};
    struct ListNode *tail=&dummy;
    while(a&&b){
        if(a->val<=b->val){
            tail->next=a;
            a=a->next;
        }
        else{
            tail->next=b;
            b=b->next;
        }
        tail=tail->next;
    }
    tail->next=(a?a:b);
    return dummy.next;
}

