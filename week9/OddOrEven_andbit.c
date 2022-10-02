#include<stdio.h>
#include<stdbool.h>
bool isEven(int num){
    return !(num&1);    
}
int main(){
    int num;
    scanf("%d", &num);
    isEven(num) == true ? printf("%d is Even Number.", num) : printf("%d is Odd Number.", num);
    return 0;
}
