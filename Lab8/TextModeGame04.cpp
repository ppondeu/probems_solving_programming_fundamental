#include <stdio.h>
#include <windows.h>
#include <time.h>
#include<stdlib.h>
#define screen_x 80
#define screen_y 25
#define scount 80
HANDLE wHnd;
HANDLE rHnd;
DWORD fdwMode;
CHAR_INFO consoleBuffer[screen_x * screen_y];
COORD bufferSize = { screen_x,screen_y };
COORD characterPos = { 0,0 };
SMALL_RECT windowSize = { 0,0,screen_x - 1,screen_y - 1 };
COORD star[scount];
int randInt = 7;
int tmpPosX=40;
int tmpPosY=12;
int hp = 10;
bool play = true;
int setConsole(int x, int y)
{
	wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleWindowInfo(wHnd, TRUE, &windowSize);
	SetConsoleScreenBufferSize(wHnd, bufferSize);
	return 0;
}
int setMode()
{
	rHnd = GetStdHandle(STD_INPUT_HANDLE);
	fdwMode = ENABLE_EXTENDED_FLAGS | ENABLE_WINDOW_INPUT |
		ENABLE_MOUSE_INPUT;
	SetConsoleMode(rHnd, fdwMode);
	return 0;
}
void clear_buffer()
{
	for (int y = 0; y < screen_y; ++y) {
		for (int x = 0; x < screen_x; ++x) {
			consoleBuffer[x + screen_x * y].Char.AsciiChar = ' ';
			consoleBuffer[x + screen_x * y].Attributes = 7;
		}
	}
}
void fill_buffer_to_console()
{
	WriteConsoleOutputA(wHnd, consoleBuffer, bufferSize, characterPos,
		&windowSize);
}
void init_star()
{
	for (int i = 0; i < scount; i++) {
		int randPosX = rand() % screen_x;
		int randPosY = rand() % screen_y;
		star[i].X = randPosX;
		star[i].Y = randPosY;
	}
}
void checkCollision() {
	for (int i = 0; i < scount; i++) {
		//if ((star[i].X==tmpPosX||star[i].X==tmpPosX-2||star[i].X==tmpPosX-1|| 
		//	star[i].X==tmpPosX+2||star[i].X==tmpPosX+1)&&star[i].Y==tmpPosY)
		if (star[i].X == tmpPosX - 2 && star[i].Y == tmpPosY) {
			short tmp = rand() % screen_x;
			star[i] = { tmp,1 };
			--hp;
			if (hp <= 0) play = false;
		}
		if (star[i].X == tmpPosX - 1 && star[i].Y == tmpPosY) {
			short tmp = rand() % screen_x;
			star[i] = { tmp,1 };
			--hp;
			if (hp <= 0) play = false;
		}
		if (star[i].X == tmpPosX && star[i].Y == tmpPosY) {
			short tmp = rand() % screen_x;
			star[i] = { tmp,1 };
			--hp;
			if (hp <= 0) play = false;
		}
		if (star[i].X == tmpPosX + 1 && star[i].Y == tmpPosY) {
			short tmp = rand() % screen_x;
			star[i] = { tmp,1 };
			--hp;
			if (hp <= 0) play = false;
		}
		if (star[i].X == tmpPosX + 2 && star[i].Y == tmpPosY) {
			short tmp = rand() % screen_x;
			star[i] = { tmp,1 };
			--hp;
			if (hp <= 0) play = false;
		}

		
	}
}
void star_fall()
{
	int i;
	for (i = 0; i < scount; i++) {
		
		if (star[i].Y >= screen_y - 1) {
			short tmp = rand() % screen_x;
			star[i] = { tmp,1 };
		}
		else {
			star[i] = { star[i].X,short(star[i].Y + 1) };	
		}
	}
}
void fill_star_to_buffer()
{
	for (int i = 0; i < scount; i++) {
		consoleBuffer[star[i].X + screen_x * star[i].Y].Char.AsciiChar = '*';
		consoleBuffer[star[i].X + screen_x * star[i].Y].Attributes = 7;
	}
}
void draw_ship(int posx, int posy) {
	for (int idx=posx-2+posy*screen_x; idx<=posx+2+posy*screen_x;idx++) {
		consoleBuffer[idx].Attributes = randInt;
	}
	consoleBuffer[posx + screen_x * posy - 2].Char.AsciiChar = '<';
	consoleBuffer[posx + screen_x * posy - 1].Char.AsciiChar = '-';
	consoleBuffer[posx + screen_x * posy].Char.AsciiChar = '0';
	consoleBuffer[posx + screen_x * posy + 1].Char.AsciiChar = '-';
	consoleBuffer[posx + screen_x * posy + 2].Char.AsciiChar = '>';	
	
}
int main()
{
	srand(time(NULL));
	DWORD numEvents = 0;
	DWORD numEventsRead = 0;
	setConsole(screen_x, screen_y);
	setMode();
	init_star();
	int cnt = 0;
	while (play)
	{
		GetNumberOfConsoleInputEvents(rHnd, &numEvents);
		if (numEvents != 0) {
			INPUT_RECORD* eventBuffer = new INPUT_RECORD[numEvents];
			ReadConsoleInput(rHnd, eventBuffer, numEvents, &numEventsRead);
			for (DWORD i = 0; i < numEventsRead; ++i) {
				if (eventBuffer[i].EventType == KEY_EVENT &&
					eventBuffer[i].Event.KeyEvent.bKeyDown == true) {
					if (eventBuffer[i].Event.KeyEvent.wVirtualKeyCode==VK_ESCAPE){
						play = false;
					}
					if (eventBuffer[i].Event.KeyEvent.uChar.AsciiChar == 'c') {
						
						randInt = rand() % 256;
						for (int idx=tmpPosX-2+tmpPosY*screen_x;idx<=tmpPosX+2+tmpPosY*screen_x;idx++) {
							consoleBuffer[idx].Attributes = randInt;
						}
					}
				}
				else if (eventBuffer[i].EventType == MOUSE_EVENT) {
					int posx = eventBuffer[i].Event.MouseEvent.dwMousePosition.X;
					tmpPosX = posx;
					int posy = eventBuffer[i].Event.MouseEvent.dwMousePosition.Y;
					tmpPosY = posy;
					if (eventBuffer[i].Event.MouseEvent.dwButtonState &
						FROM_LEFT_1ST_BUTTON_PRESSED ) {
						
						randInt = rand() % 256;
						for (int idx = posx - 2 + posy * screen_x; idx <= posx + 2 + posy * screen_x; idx++) {
							consoleBuffer[idx].Attributes = randInt;
						}
					}
					else if (eventBuffer[i].Event.MouseEvent.dwEventFlags & MOUSE_MOVED) {
						++cnt;
						if(cnt==1)
							draw_ship(tmpPosX, tmpPosY);
					}
				}
			}
			delete[] eventBuffer;
		}
		star_fall();
		clear_buffer();
		fill_star_to_buffer();
		if (cnt > 1)
			draw_ship(tmpPosX, tmpPosY);
		checkCollision();
		fill_buffer_to_console();
		Sleep(100);
	}
	return 0;
}
