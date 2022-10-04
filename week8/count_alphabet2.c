#include<stdio.h>
#include<ctype.h>
#include<string.h>
int cnt[26];
int main(){
    char input[101];
    scanf("%[^\n]*c", input);
    for(int i=0;i<strlen(input);i++){
        cnt[toupper(input[i])-'A']++;
    }
    for(int i=0;i<26;i++){
        printf("%c : %d\n", i+'A', cnt[i]);
    }
    return 0;
}
