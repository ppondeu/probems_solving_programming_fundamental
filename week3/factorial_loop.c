#include<stdio.h>

// max of input is 20
unsigned long long factorial_loop(unsigned long long n){
    unsigned long long n_fac=1;

    for(int i=2;i<=n;i++){
        n_fac*=i;
    }
    return n_fac;
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
    
    printf("%llu",factorial_loop(n));

    return 0;
}
