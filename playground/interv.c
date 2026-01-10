#include <stdio.h>


void print_step();

int main(){
    print_step();
    int *p = (int*) 0x8264;
    *p = 0x2645;
    return 0;
}

void print_step()
{
    for (int i = 1; i <= 4; i++) {
        for (int j = 0; j < i; j++) {
            printf("*");
        }
        printf("\n");
    }
}

#define SET_BIT(p,n) ((p) |= (1 << (n)))
#define CLEAR_BIT(p,n) ((p) &= ~(1 << (n)))
#define CHANG_BIT(p,n) ((p) ^= (1 << (n)))
#define CHECK_BIT(p,n) ((p) & (1 << (n)))
typedef unsigned int unit;

int add(int a, int b){
    return a + b;
}

int (*fp)(int* ,int*);
int (*fp)(int*, int*) = swap;
typedef int (*fp)(int, int);
fp op = add;
int result = op(x,y);
printf("%d\n", result);

int x = 10;

int *p = &x;
*p = 20;


void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
int x = 10, y = 20;
swap(&x, &y);

int *ptr = (int *)0x8647;
*ptr = 0x24E3;

#define clear(x, n) ((x) &= ~(1 << n))
#define toggel(x, n) ((x) ^= (1 << n))
#define set(x, n) ((x) |= (1 << n))
#define check(x, n) ((x) & (1 << n))
#define size(x) (sizeof(x) / sizeof(x[0]))
#define max(a,b) ((a) > (b)) ? (a) : (b)


void swap_char(char *a, char *b){
    char temp = ' ';
    temp = *a;
    *a = *b;
    *b = temp;
}
char *reverse_string(char *c){
    int n = strlen(c);
    for (int i = 0; i < n; i++){
        swap_char(&c[i], &c[n-1]);
        n--;
    }
    return c;
}

struct Node {
    int data;
    struct Node *next;
};

struct Node *return_midNode(struct Node *head){
    struct Node *fast = head;
    struct Node *slow = head;
    while (fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

struct Node *reverse_List(struct Node *head){
    struct Node *prev = NULL;
    struct Node *cur = head;
    struct listNode *next = NULL;

    while (cur != NULL){
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}

