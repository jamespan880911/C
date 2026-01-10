/**
* -----------------------------------------------------------------
 * Name: 242. valid_anagram
-----------------------------------------------------------------
 * * 💡 解題思路 (Approach):
 * 1. 開固定大小array去比較次數。
 * 2. 用count[s[i] - 'a']就不用去記a的ASCII（用差距是聰明的作法）。
 * * -----------------------------------------------------------------
*/

#include <string.h>
#include <stdbool.h>
#include <stdio.h>

bool isAnagram(char* s, char* t) {


    int count[26] = {0};
    int len_s = strlen(s);
    int len_t = strlen(t);

    if (len_s != len_t) {
        return false;
    }

    for (int i = 0; i < len_s; i++){
        count[s[i] - 'a']++;
        count[t[i] - 'a']--;
    }

    for (int i = 0; i < 26; i++){
        if (count[i] != 0){
            return false;
        }
    }

    return true;
}

int main(){
    char s1[] = "anagram";
    char t1[] = "nagaram";

    char s2[] = "rat";
    char t2[] = "car";

    printf("Test1 = %d\n", isAnagram(s1, t1));
    printf("Test2 = %d\n", isAnagram(s2, t2));

    return 0;
}