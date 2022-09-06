#include<stdio.h>

int main(){
   int bottle;
   scanf("%d",&bottle);
   int sum = bottle;
   int n = bottle;

   while(n>=3){
        int cnt = (n/3);
        sum += cnt;
        n = n%3;
        n += cnt;
   }

   printf("%d",sum);

   return 0;
}
