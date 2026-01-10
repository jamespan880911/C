#include <stdio.h>

int happy(int a){
    int result = 0;
    while (result != 1){
        result = 0;
        while (a != 0){
            result += (a % 10) * (a % 10);
            a /= 10; 
        }
        a = result;
        if (result == 1){
            break;
        }
        continue;
    }
    return 1;
}

int main(){

}