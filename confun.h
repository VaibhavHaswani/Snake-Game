#include<windows.h>
#ifndef _CONFUN_H
#define _CONFUN_H
void gotoxy(int x,int y){
	COORD c;
	c.X=x;
	c.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}

void hidecur(){
	HANDLE consoleHandle=GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize=100;
	info.bVisible=FALSE;
	SetConsoleCursorInfo(consoleHandle,&info);
}
void setcolor(int ForgC){
	WORD wColor;
	HANDLE hStdOut=GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if(GetConsoleScreenBufferInfo(hStdOut,&csbi)){
		wColor=(csbi.wAttributes & 0xF0)+(ForgC & 0x0F);
		SetConsoleTextAttribute(hStdOut,wColor);
	}
	}
#endif
