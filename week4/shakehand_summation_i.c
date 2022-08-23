#include<stdio.h>

int summation_i(int n){
    int sum=0;
    for(int i=1;i<n;i++){
        sum+=i;
    }
    return sum;
}
int main(){
    int n;
    scanf("%d",&n);
    printf("%d",summation_i(n));
    return 0;
}
