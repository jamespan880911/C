#include<stdio.h>

void str_cpy(char *dest, const char *src){
    if (dest == NULL || src == NULL){
        return;
    }
    while (*src != '\0'){
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
}

int str_len(const char *src){
    int len = 0;
    while (*src != '\0'){
        len++;
        src++;
    }
    return len;
}

int str_cmp(const char *a, const char *b){
    while (*a && (*a == *b)){
        a++;
        b++;
    }
    return (unsigned char)*a - (unsigned char)*b; //怕ASC|| > 127會錯
}

void str_cat(char *dest, const char *src){
    while (*dest != '\0'){
        dest++;
    }
    while(*src != '\0'){
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
}

int main(){
    //s1 和 s2 是指向read-only的區段（.rodata），小心不要去改到
    //通通都宣告成陣列就都可以改(進stack區段)
    char *s1 = "TestCode"; 
    char *s2 = "for me";
    
    char v[50];
    
    printf("s1 的長度為：%d\n", str_len(s1));
    printf("s2 的長度為：%d\n", str_len(s2));

    printf("s1 和 s2 的比較：%d\n", str_cmp(s1,s2));

    str_cpy(v, s1);
    printf("測試把s1複製到v : %s\n", v);

    str_cat(v, s2);
    printf("測試把s2接進v後面(前面已包涵s1) : %s\n", v);
    return 0;
}