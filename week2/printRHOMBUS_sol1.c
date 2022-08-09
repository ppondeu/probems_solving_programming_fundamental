#include<stdio.h>
#include<math.h>

int main(){
    int n;
    scanf("%d",&n);
    int begin=n;
    int end=n;

    for(int i=1;i<=2*n-1;i++){
        for(int j=1;j<=2*n-1;j++){
            if(j>=begin&&j<=end){
                printf("*");
            }else{
                printf(" ");
            }
            
        }
        if(i<n){
                begin--;
                end++;
            }else{
                begin++;
                end--;
            }
        printf("\n");
    }
    char ch = getchar();
    return 0;
}

