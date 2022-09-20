#include<stdio.h>
#include<string.h>
int cnt[26];
int main(){
    char input[1001];
    scanf("%[^\n]*c",input);
    int l=strlen(input);

    for(int i=0;i<l;i++){
        int convert = (int) input[i];
        
        if(input[i]>='A'&&input[i]<='Z'){
            for(int j='A';j<='Z';j++){
                if(convert == j){
                    cnt[convert-65]++;
                    break;
                }
            }
        }else if(input[i]>='a'&&input[i]<='z'){
            for(int j='a';j<='z';j++){
                if(convert == j){
                    cnt[convert-97]++;
                    break;
                }
            }
        }
    }

    for(int i=0;i<26;i++){
        printf("%c : %d\n",i+65,cnt[i]);
    }
    return 0;
}