#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <thread>
#include <mutex>
#define nBullet 5
void gotoxy(int x, int y);
void update_score(int* score);
void erase(int x, int y);
void draw_ship(int x, int y);
void setcursor(bool visible);
void setcolor(int fg, int bg);
void draw_bullet(int x, int y);
char cursor(int x, int y);
void draw_star();
void clear_bullet(int x, int y);

int main()
{

	srand(time(NULL));
	for (int i = 1; i <= 20; i++) {
		draw_star();
	}
	setcursor(0);
	setcolor(2, 4);
	int x = 38, y = 20;
	draw_ship(x, y);
	char ch = ' ';
	char mode = ' ';
	bool bulletState[nBullet] = { false, false, false, false, false };
	int idxBullet = -1;
	int posbulletX[nBullet] = {}, posbulletY[nBullet] = {};
	int score = -10;
	update_score(&score);
	while (ch != 'x')
	{
		setcursor(0);
		if (_kbhit())
		{
			ch = _getch();
			if (ch == 'd')
				mode = 'd';
			if (ch == 'a')
				mode = 'a';
			if (ch == 's')
				mode = 's';
			if (ch == ' ')
			{
				++idxBullet;
				if (idxBullet < 5)
				{

					std::thread q(Beep, 700, 100);
					q.detach();
					bulletState[idxBullet] = true;
					posbulletX[idxBullet] = x + 2;
					posbulletY[idxBullet] = y - 1;
				}
			}
			fflush(stdin);
		}
		if (mode == 'd')
		{
			if (x < 75)
			{
				erase(x, y);
				draw_ship(++x, y);
			}
		}
		if (mode == 'a')
		{
			if (x > 0)
			{
				erase(x, y);
				draw_ship(--x, y);
			}
		}
		if (mode == 's')
		{
			if (y < 25)
			{
				erase(x, y);
				draw_ship(x, y);
			}
		}
		for (int i = 0; i < nBullet; i++)
		{
			if (bulletState[i])
			{
				clear_bullet(posbulletX[i], posbulletY[i]);
				if (posbulletY[i] == 0)
				{
					bulletState[i] = false;
					if (i == 4) idxBullet = -1;
				}
				else {
					if (cursor(posbulletX[i], --posbulletY[i]) == '*') {
						std::thread q(Beep, 150, 500);
						q.detach();
						update_score(&score);
						draw_star();
						clear_bullet(posbulletX[i], posbulletY[i]);
						bulletState[i] = false;
						if (i == 4) idxBullet = -1;
					}
					else {
						draw_bullet(posbulletX[i], posbulletY[i]);
					}
				}

			}
		}
		Sleep(70);
	}
	setcolor(7, 0);
	return 0;
}
void setcursor(bool visible)
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO lpCursor;
	lpCursor.bVisible = visible;
	lpCursor.dwSize = 20;
	SetConsoleCursorInfo(console, &lpCursor);
}
void gotoxy(int x, int y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void erase(int x, int y)
{
	gotoxy(x, y);
	setcolor(7, 0);
	printf("     ");
}
void draw_bullet(int x, int y)
{
	gotoxy(x, y);
	setcolor(2, 0);
	printf("X");
}
void draw_ship(int x, int y)
{
	gotoxy(x, y);
	setcolor(2, 4);
	printf("<-0->");
}
void setcolor(int fg, int bg)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, bg * 16 + fg);
}
char cursor(int x, int y) {
	HANDLE hStd = GetStdHandle(STD_OUTPUT_HANDLE);
	char buf[2]; COORD c = { x,y }; DWORD num_read;
	if (
		!ReadConsoleOutputCharacter(hStd, (LPTSTR)buf, 1, c, (LPDWORD)&num_read))

		return '\0';
	else
		return buf[0];

}
void draw_star() {
	int randX = (rand() % 61) + 10;
	int randY = (rand() % 4) + 2;
	while (cursor(randX, randY) == '*') {
		randX = (rand() % 61) + 10;
		randY = (rand() % 4) + 2;
	}
	gotoxy(randX, randY);
	printf("*");

}
void clear_bullet(int x, int y) {
	gotoxy(x, y);
	setcolor(7, 0);
	printf(" ");
}
void update_score(int* score) {
	*score = *score + 10;
	gotoxy(69, 0);
	setcolor(7, 0);
	printf("score : %d", *score);
}
