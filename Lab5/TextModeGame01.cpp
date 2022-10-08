#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <conio.h> 
#include<windows.h>

void gotoxy(int x, int y) {
	COORD c = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void erase(int x, int y) {
	gotoxy(x, y);
	printf("     ");
}
void draw_ship(int x, int y) {
	gotoxy(x, y);
	printf("<-0->");
}
int main(){
	int x = 38, y = 20;
	draw_ship(x, y);
	char ch = ' ';
	while (ch!='x') {
		if (_kbhit()) {
			ch = _getch();
			if (ch == 'd') {
				if (x < 75) {
					erase(x, y);
					draw_ship(++x, y);
				}
			}
			if (ch == 'a') {
				if (x > 0) {
					erase(x, y);
					draw_ship(--x, y);
				}
			}
			if (ch == 'w') {
				if (y > 0) {
					erase(x, y);
					draw_ship(x, --y);
				}
			}
			if (ch == 's') {
				if (y < 25) {
					erase(x, y);
					draw_ship(x, ++y);
				}
			}
			fflush(stdin);
		}
		Sleep(100);
	}
	return 0;
}
