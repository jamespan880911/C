#include <stdio.h>
#include <string.h>

#define Max(a, b) ((a) > (b)) ? (a) : (b)
#define set_bit(x, n) ((x) |= (1 << (n)))
#define clear_bit(x, n) ((x) &= ~(1 << (n)))
#define toggle_bit(x, n) ((x) ^= (1 << (n)))
#define array_size(arr) (sizeof(arr) / sizeof(arr[0]))


struct Node {
    int data;
    struct Node *next;
};

void swap(int *a, int *b){
    *a = (*a) ^ (*b);
    *b = (*a) ^ (*b);
    *a = (*a) ^ (*b);
}

void print_star(){
    for (int i = 1; i < 5; i++){
            for (int j = 0; j < i; j++){
                printf("*");
            }
        printf("\n");
    }
}

int round_off(float a){
    return (int)(a + 0.5);
}

int judge_pow2(unsigned int x){
    return (x & (-x)) == x;
}

int num_of_1(unsigned int x){
    int c = 0;
    /*while (x != 0){
        x -= x & -x;
        c++;
    }*/
    while (x != 0){
        x = x & (x - 1); //這個寫法比較多人在用（比較直觀）
        c++;
    }
    return c;
}

void MSB(unsigned int x){
    unsigned int n = 0x80000000;
    int count = 31;
    while ((x & n) >> count != 1){
        count--;
        n >>= 1;
    }
    printf("The MSB is : %d \n", count);
}

void LSB(unsigned int x){
    unsigned int n = 0x1;
    int count = 0;
    if (x < 0){
        return;
    }
    while ((x & n) >> count != 1){
        count++;
        n <<= 1;
    }
    printf("The LSB is : %d\n", count);
}

int hex_equal(unsigned int x){
    unsigned int hex[4] = {0};
    hex[0] = (x & 0xF000) >> 12;
    hex[1] = (x & 0x0F00) >> 8;
    hex[2] = (x & 0x00F0) >> 4;
    hex[3] = (x & 0x000F);
    if (hex[0] == hex[1] && hex[1] == hex[2] && hex[2] == hex[3]){
        return 1;
    }
    return 0;
}

void swap_char(char *a, char *b){
    char temp = ' ';
    temp = *a;
    *a = *b;
    *b = temp;
}
char *reverse_string(char *x){
    int n = strlen(x);
    for (int i = 0; i < n / 2; i++){
        swap_char(&x[i], &x[n-i-1]);
    }
    return x;
}

void find_prime(int n){
    for (int i = 2; i < (n + 1); i++){
        int flag = 1;
        for (int j = 2; j < i; j++){
            if (i % j == 0){
                flag = 0;
                break;
            }
        }
        if (flag){
            printf("%d is prime\n", i);
        }
    }
}

void append_node(struct Node **head, int data){
    struct Node *new_node = NULL;
    struct Node *cur = *head;
    new_node = malloc(sizeof(struct Node));
    if (new_node == NULL) //如果沒有heap成功的檢查
        return;
    new_node->next = NULL;
    new_node->data = data;

    if (*head == NULL){
        *head = new_node;
    }
    else{
        while(cur->next){
            cur = cur->next;
        }
        cur->next = new_node;
    }
}

void push_node(struct Node **head, int data){
    struct Node *new_node = NULL;
    new_node = malloc(sizeof(struct Node));
    if (new_node == NULL)
        return;
    new_node->next = NULL;
    new_node->data = data;

    new_node->next = *head;
    *head = new_node;
}

void print_list(struct Node *head){
    struct Node *ptr = head;
    while (ptr != NULL){
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}

void delete_node_value(struct Node **head, int val){
    struct Node *prev = NULL;
    struct Node *cur = *head;

    while (cur && cur->data != val){
        prev = cur;
        cur = cur->next;
    }
    if (cur){
        if (cur == *head){
            *head = cur->next;
            free(cur);
        }
        else {
            prev->next = cur->next;
            free(cur);
        }
    }
    else{
        printf("val is not in the list");
    }
}

void insert_node_pos(struct Node **head, int pos, int val){
    struct Node *new_node = NULL;
    new_node = malloc(sizeof(struct Node));
    if (new_node == NULL)
        return;
    new_node->next = NULL;
    new_node->data = val;

    struct Node *cur = *head;
    
    for (int i = 1;cur && i < pos; i++){
        cur = cur->next;
    }
    if (pos == 0){
        new_node->next = *head;
        *head = new_node;
    }
    else{
        if (cur){
            new_node->next = cur->next;
            cur->next = new_node;
        }
        else{
            free(new_node);
        }
    }
}

int main(){
    int n = 100;
    find_prime(n);
    return 0;
}