#include<stdio.h>
#include<ctype.h>

void recur(int n,int *x){
    if(n<3){
        return;
    }
    *x = *x + n/3;
    recur(n%3 + n/3,x);
}



int main(){
    int bottle;
    scanf("%d",&bottle);
    int x = bottle;
    recur(bottle, &x);
    printf("%d",x);

    return 0;
}