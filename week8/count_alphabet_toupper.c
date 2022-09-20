#include<stdio.h>
#include<string.h>
#include<ctype.h>
int cnt[26];
int main(){
    char input[1001];
    scanf("%[^\n]*c",input);
    int l=strlen(input);

    for(int i=0;i<l;i++){
        int convert = (int) toupper(input[i]);
        for(int j='A';j<='Z';j++){
            if(convert==j){
                cnt[convert-65]++;
                break;
            }
        }
    }

    for(int i=0;i<26;i++){
        printf("%c : %d\n",i+65,cnt[i]);
    }
    return 0;
}
