#include<stdio.h>
#include<string.h>

void putsfile(){
    FILE *f = fopen("file_fputs.txt", "a");
    while(1){
        char input[1001];
        scanf("%[^\n]*c ", input);
        fflush(stdin);
        fputs(input,f);
        fputs("\n",f);
        if(strcmp(input, ".")==0){
            break;
        }
    }
    fclose(f);
}

int main(){
    printf("Input data string:");
    putsfile();
    return 0;
}
