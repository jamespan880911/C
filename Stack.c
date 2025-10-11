#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct ListNode{
    struct ListNode *next;
    uint32_t data;
}ListNode;

typedef struct Stack{
    struct ListNode *top;
    void (*spush)(uint32_t);
    void (*spop)();
}Stack;

Stack *stack = NULL;

void spush(uint32_t val){
    ListNode *tmp = malloc(sizeof(ListNode));
    tmp->data = val;
    tmp->next = NULL;
    tmp->next = stack->top;
    stack->top = tmp;
    return;
}

void spop(){
    ListNode *tmp = NULL;
    if (stack->top == NULL){
        return;
    }
    else{
        tmp = stack->top;
        stack->top = stack->top->next;
        free(tmp);
    }
    return;
}

void print_stack(Stack *s){
    ListNode *tmp = s->top;
    while (tmp != NULL){
        printf("%u -> ", tmp->data);
        tmp = tmp->next;
    }
    printf("\n");
    return;
}

void init_stack(Stack **s){
    *s = malloc(sizeof(Stack));
    (*s)->top = NULL;
    (*s)->spush = spush;
    (*s)->spop = spop;
}

int main(){
    init_stack(&stack);
    stack->spush(10);
    stack->spush(20);
    print_stack(stack);
    stack->spush(30);
    print_stack(stack);
    stack->spop();
    print_stack(stack);
    return 0;
}