#include<stdio.h>
#include<string.h>

void append(){
    FILE *f = fopen("file_fprintf.txt", "a");
    while(1){
        char input[1001];
        scanf("%[^\n]*c ", input);
        fflush(stdin);
        fprintf(f,"%s\n",input);
        if(strcmp(input, ".")==0){
            break;
        }
    }
    fclose(f);
}


int main(){
    printf("Input data string:");
    append();
    return 0;
}
