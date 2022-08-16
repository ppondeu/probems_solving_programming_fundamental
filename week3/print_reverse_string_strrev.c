#include<stdio.h>
#include<string.h>
int main(){
    char str_input[1001];
    scanf("%[^\n]*c",str_input);
    printf("%s",strrev(str_input));
    return 0;
}