#include<stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    // CREATE TOP
    int begin=n;
    int end=n;
    for(int i=1;i<=n-1;i++){
        for(int j=1;j<=2*n-1;j++){
            if(j>=begin&&j<=end){
                printf("*");
            }else{
                printf(" ");
            }
        }
        begin--;
        end++;
        printf("\n");
    }
    // CREATE MID
    for(int i=1;i<=2*n-1;i++){
        printf("*");
    }
    printf("\n");

    // CREATE DOWN
    begin = 2;
    end = 2*n-2;
    for(int i=1;i<=n-1;i++){
        for(int j=1;j<=2*n-1;j++){
            if(j>=begin&&j<=end){
                printf("*");
            }else{
                printf(" ");
            }
        }
        begin++;
        end--;
        printf("\n");
    }
    return 0;
}