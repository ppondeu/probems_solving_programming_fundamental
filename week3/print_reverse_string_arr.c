#include<stdio.h>
#include<string.h>
int main(){
    char str_input[1001];
    scanf("%[^\n]*c",str_input);
    int l=strlen(str_input)-1;
    for(int i=l;i>=0;i--){
        printf("%c",str_input[i]);
    }
    return 0;
}