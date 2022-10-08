#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#define nBullet 5
void gotoxy(int x, int y);
void erase(int x, int y);
void draw_ship(int x, int y);
void setcursor(bool visible);
void setcolor(int fg, int bg);
void draw_bullet(int x, int y);
int main()
{
	setcursor(0);
	setcolor(2, 4);
	int x = 38, y = 20;
	draw_ship(x, y);
	char ch = ' ';
	char mode = ' ';
	bool bulletState[nBullet] = { false, false, false, false, false };
	int idxBullet = -1;
	int posbulletX[nBullet] = {}, posbulletY[nBullet] = {};
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
				if (posbulletY[i] > 0)
				{
					erase(posbulletX[i], posbulletY[i]);
					draw_bullet(posbulletX[i], --posbulletY[i]);
				}
				else
				{
					erase(posbulletX[i], posbulletY[i]);
					bulletState[i] = false;

					if (i == 4)
					{

						idxBullet = -1;
					}
				}
			}
		}
		Sleep(50);
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
