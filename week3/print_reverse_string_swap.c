#include<stdio.h>
#include<string.h>

int main(){
    char str_input[1001];
    scanf("%[^\n]*c",str_input);
    int l = strlen(str_input);
    for(int i=0;i<l/2;i++){
        char temp = str_input[i];
        str_input[i] = str_input[l-i-1];
        str_input[l-i-1] = temp;
    }
    for(int i=0;i<l;i++){
        printf("%c", str_input[i]);
    }
    return 0;
}
