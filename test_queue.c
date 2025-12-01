#include<stdio.h>
#include<stdlib.h>

struct ListNode{
    struct ListNode *next;
    int data;
};

struct Queue{
    struct ListNode *head;
    struct ListNode *tail;
};

void qpush(struct Queue *q, int data){
    struct ListNode *node = malloc(sizeof(struct ListNode));
    node->data = data;
    node->next = NULL;

    if (q->head == NULL){
        q->head = node;
        q->tail = node;
        return;
    }

    q->tail->next = node;
    q->tail = q->tail->next;
}

int qpop(struct Queue *q){
    int ans;
    if (q->head == NULL){
        return -1;
    }
    struct ListNode *tmp = q->head;
    q->head = q->head->next;
    ans = tmp->data;
    free(tmp);
    if (q->head == NULL){
        q->tail = NULL;
        return ans;
    }
    return ans;
}

void init_queue(struct Queue *q){
    q->head = NULL;
    q->tail = NULL;
}

int qsearch(struct Queue *q, int data){
    
}

int main(){
    struct Queue *queue = malloc(sizeof(struct Queue));
    init_queue(queue);

}