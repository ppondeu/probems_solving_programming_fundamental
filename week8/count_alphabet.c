#include <math.h>
#include <stdio.h>
#include<string.h>
#include<ctype.h>
void insertionSort(char arr[], int n){
	int i, tmp, j;
	for (i = 1; i < n; i++) {
		tmp = (int)arr[i];
		j = i - 1;
		while (j >= 0 && (int)arr[j] > tmp) {
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = tmp;
	}
}
int main(){
	char input[101];
    scanf("%[^\n]*c", input);
    for(int i=0;i<strlen(input);i++){
        input[i] = toupper(input[i]);
    }
	insertionSort(input, strlen(input));
    int currentAlpha = 'A';
    int tmpAlpha = input[0];
    int idx=0;
    int cnt=0;
    while(currentAlpha <= 'Z'){
       if(currentAlpha == tmpAlpha){
         while(currentAlpha==tmpAlpha){
            tmpAlpha = input[++idx];
            ++cnt;
        }
                printf("%c : %d\n", currentAlpha++, cnt);
            cnt=0;
       }
       else{
             printf("%c : %d\n", currentAlpha++, 0);
       }
    }
	return 0;
}
