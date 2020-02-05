	#include<stdio.h>
#include"confun.h"
#include<stdlib.h>
#include<string.h>



int fx,fy,x=48,enx=96,y=12,eny=26,score=0,nx=48,ny=12;
int n=0,ns=3,del=4000;

void scre(void){
	gotoxy(103,8);
	setcolor(6);
	printf("SCORE :");
	gotoxy(103,10);
	printf("SNAKE :");
	setcolor(12);
	gotoxy(112,8);
	printf("%d",score);
	gotoxy(112,10);
	printf("%d",ns);
}

int rnd(int min,int max){
	int range,x,r;
	r=rand();
	range=max-min;
	x=r%range;
	return (x+min);
}

void clear(){
	int l;
	gotoxy(enx,eny);
	for(l=0;l<=enx;l++)
	printf(" ");
	for(l=0;l<=eny;l++)
	printf(" ");
}
	

  
void levlup(){
	score++;
	ns++;
	del=del-500;
}
void load(void)
{
	system("color 0f");
	int i,j;
	hidecur();
	setcolor(14);
	gotoxy(52,4);
	printf("S N A K E S  (v1.0)");
	setcolor(9);
	gotoxy(48,12);
	printf("L O A D I N G . . .");
	setcolor(10);
 for(i=1;i<=100;i++)
	 {
	 for(j=1;j<=20000000;j++);
	 for(j=1;j<=20000000;j++);
	 gotoxy(10+i,14);
	 printf("%c",177);
	 gotoxy(70,12);
	 printf("(%d%%)",i);
    }
}

void frame()
{
	system("color 0f");
	gotoxy(1,2);
	printf(" ____________________________________________________________________________________________________________________\n");
	gotoxy(1,3);
	printf("|                                                                                                                    |");
	gotoxy(1,4);
	printf("|                                                                                                                    |");
	gotoxy(1,5);
	printf("|____________________________________________________________________________________________________________________|");
	int i,j=6;
	for(i=1;i<20;i++,j++){
		gotoxy(1,j);
		printf("|                                                                                               |                    |");
	}
	gotoxy(1,j);
	printf("|                                                                                               |    DEVELOPED BY-   |");
	gotoxy(1,++j);
	printf("|                                                                                               |   VAIBHAV HASWANI  |");
	gotoxy(1,++j);
	printf("|_______________________________________________________________________________________________|____________________|");
	setcolor(14);
	gotoxy(52,4);
	printf("S N A K E S (v1.0)");
	scre();
}

void reset(void){
	system("cls");
	x=48,enx=96,y=12,eny=26,score=0,nx=48,ny=12;
    n=0,ns=3;
	
}

void gameover(void){
	//char ch;
	system("cls");
	gotoxy(52,12);
	printf("G A M E     O V E R\n");
	gotoxy(52,15);
	printf("PLAY AGAIN?");
	gotoxy(52,16);
	printf("y=YES  n=NO\n");
	fflush(stdin);
    getch(); 
    system("pause");
	if(GetAsyncKeyState('Y')){
	reset();	
	main();
    }
    if(GetAsyncKeyState('N')){
    	exit(1);
	}
	
}

void food(){
  fx=rnd(2,96);
  fy=rnd(7,26);
  gotoxy(fx,fy);
   setcolor(9);
  printf("*");	
}


void delay(){
	int i,j;
	for(i=0;i<del;i++){
	for(j=9;j<del;j++){
		//pass
	}
}
}

void delay1(){
	int i,j;
	for(i=0;i<3000;i++){
	for(j=9;j<3000;j++){
		//pass
	}
}
}

void input(void);
void game(void);
void right();
void left();
void up();
void down();

void right(){
	setcolor(2);
	int l,k;

	//gotoxy(nx,ny);
	//printf(" ");
	for(l=0;l<ns;l++)
	nx=--x;
	delay1();
    for(k=ns;k>=0;k--)
	{
		if(k==0){
		gotoxy(x,y);
		printf("O");
		delay();
		}
		else{	
		gotoxy(x,y);
		printf("o");
	    }
	    
		++x;
	}	
	enx=x;
	eny=y;
	
//  input();
    game();
//	right();
        if(GetAsyncKeyState('W'))
        up();
        else if(GetAsyncKeyState('S'))
        down();
        else if(GetAsyncKeyState('D')){}
        else if(GetAsyncKeyState('A')){}
        frame();
        gotoxy(fx,fy);
        setcolor(9);
        printf("*");
        right();
}
    
    
   
   
      
void left(){
	setcolor(2);
	int l,k;
	//gotoxy(nx,ny);
	//printf(" ");
	for(k=n;k<ns;k++)
	nx=++x;
	delay1();
	for(l=n;l<=ns;l++)
	{
		
		gotoxy(x,y);
		if(l==ns){	
		printf("O");
		delay();
		}
		else{	
		printf("o");
	    }
		x--;
	}	
	enx=x;
	eny=y;
//	input();
	game();
//	left();
    if(GetAsyncKeyState('W'))
        up();
        else if(GetAsyncKeyState('S'))
        down();
        else if(GetAsyncKeyState('D')){}
        else if(GetAsyncKeyState('A')){}
        frame();
        gotoxy(fx,fy);
        setcolor(9);
        printf("*");
        left();

}



    
void up(){
	setcolor(2);
    int l,k;
	
    //gotoxy(nx,ny);
	//printf(" ");
	for(l=0;l<ns;l++)
 	ny=++y;
 	delay1();
	for(k=n;k<=ns;k++)
	{
		if(k==ns){	
		gotoxy(x,y);	
		printf("O");
		delay();
	    }
		else
		{	
 		gotoxy(x,y);
		printf("o");
	    }
	    y--;
	}	
	enx=x;
    eny=y;
//	input();
	game();
//	up();
        if(GetAsyncKeyState('D'))
            right();
        else if(GetAsyncKeyState('A'))
            left();
        else if(GetAsyncKeyState('W')){}
        else if(GetAsyncKeyState('S')){}
        frame();
        gotoxy(fx,fy);
        setcolor(9);
        printf("*");
        up();
}

void down(){
	setcolor(2);
	int l,k;
 	//gotoxy(nx,ny);
 	//printf(" ");
 	for(l=0;l<ns;l++)
 	ny=--y;
 	delay1();
	for(k=n;k<=ns;k++)
	{
		if(k==ns){	
		gotoxy(x,y);	
		printf("O");
		delay();
	    }
		else
		{	
		gotoxy(x,y);
		printf("o");
	    }
	    ++y;
	}
	enx=x;
	eny=y;
	
//	input();
	game();
//	down();
if(GetAsyncKeyState('D'))
            right();
        else if(GetAsyncKeyState('A'))
            left();
        else if(GetAsyncKeyState('W')){}
        else if(GetAsyncKeyState('S')){}
        frame();
        gotoxy(fx,fy);
        setcolor(9);
        printf("*");
        down();
}



void game(void){
	if(x==fx && y==fy)
	{
	food();
	levlup();
    }
    else if(x>=95 || x<=1 || y>=28 || y<=5)
    {
    	gameover();
	}
	else;
}

void input(){
	if(kbhit()){
		switch(getch()){
			case 'w':
				up();
				break;
			case 'a':
			    left();
			    break;
			case 's':
			     down();
			     break;
		    case 'd':
			    right();
			    break;	 	 	
		}
	}
}

int main(){
	hidecur();
	load();
	frame();
	food();
	right();
	}



