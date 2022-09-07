#include<stdio.h>
#include<string.h>

void putsfile(){
    char data[1001]="";
    FILE *f = fopen("file_fputs.txt", "a");
    while(1){
        char input[1001];
        scanf("%[^\n]*c ", input);
        fflush(stdin);
        strcat(data, input);
        strcat(data, "\n");
        if(strcmp(input, ".")==0){
            break;
        }
    }
    fputs(data,f);
    fclose(f);
}

/*void putsfile2(){
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
}*/

int main(){
    printf("Input data string:");
    putsfile();
    return 0;
}
