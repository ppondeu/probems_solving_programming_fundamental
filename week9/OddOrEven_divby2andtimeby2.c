#include<stdio.h>
#include<stdbool.h>
bool isEven(int num){
    int check = num/2;
    if(check*2 == num) return true;
    else return false;
}
int main(){
    int num;
    scanf("%d", &num);
    isEven(num) == true ? printf("%d is Even Number.", num) : printf("%d is Odd Number.", num);
    return 0;
}