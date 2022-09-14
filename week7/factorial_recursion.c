#include<stdio.h>
// max of input is 20
unsigned long long table[21];

unsigned long long factorial_recursive(unsigned long long n){
    if(n==0||n==1){
        return 1;
    }
    if(table[n]>0){
        return table[n];
    }else{
        unsigned long long result = n*factorial_recursive(n-1);
        return result;
    }
}

int main(){
    unsigned long long n;
    scanf("%llu",&n);
    if(n<0){
        printf("PLEASE ENTER POSITIVE NUMBER");
        return 0;
    }else if(n>20){
        printf("TOO MORE OF FACTORIAL OF THIS NUMBER");
        return 0;
    }
    printf("%llu! = %llu",n,factorial_recursive(n));
    return 0;
}