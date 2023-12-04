#include <iostream>
#include <conio.h>
#include <windows.h>


#define BLUE 1
#define GREEN 2
#define CYAN 3
#define RED 4
#define PURPLE 5
#define DARKYELLOW 6
#define WHITE 7
#define GREY 8
#define LIGHTBLUE 9
#define LIGHTGREEN 10
#define LIGHTCYAN 11
#define LIGHTRED 12
#define PINK 13
#define YELLOW 14
#define LIGHTWHITE 15

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_SPACE 32

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;

using namespace std;
int maxy= 26, maxx=90, midy=maxy/2, midx=maxx/2;

int plposy = midy;
int plposx = 1; 

int enemyposy[4], enemyposx[4];
bool enemyflag[4];//<--- kemungkinan error

int posbully[2];
int posbullx[2];

bool bullflag[2];

char player[2] = {'\xdb', '\xfe'};

int score=0;
int lifes=3;

void gotoxy( short x, short y )
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE) ;
    COORD position = { x, y } ;

    SetConsoleCursorPosition( hStdout, position ) ;
}

void textcolor(int colorCode) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, colorCode);
}

void setcursor(bool visible, DWORD size)
{
	if (size == 0)
		size = 20;
	CONSOLE_CURSOR_INFO lpCursor;
	lpCursor.bVisible = visible;
	lpCursor.dwSize = size;
	SetConsoleCursorInfo(console, &lpCursor);
}

void menu(){
	gotoxy(midx-10,midy);
	cout << "Pick Option: ";
	
}

void draw(){
	textcolor(RED);
	for(int i=0; i<maxy; i++){
		gotoxy(90, i);
		cout << "\xba";
		
	}
	for(int i=0; i<maxx; i++){
		gotoxy(i, 2);
		cout << "\xcd";
	}
	
	for(int i=0; i<120; i++){
		gotoxy(i,maxy);
		cout << "\xcd";	
	}
	gotoxy(90, 2);
	cout << "\xb9";
	
	gotoxy(90, maxy);
	cout << "\xca";
	
	textcolor(LIGHTBLUE);
	gotoxy(midx-5, 0);
	cout << "BIRD ATTACK";
	
	gotoxy(93, 6);
	cout << "objective:";
	gotoxy(93, 7);
	cout << "-kill all birds";
	gotoxy(93, 8);
	cout << "-dont let birds get through";
	
	gotoxy(100, 10);
	cout << "movement:";
	gotoxy(100, 11);
	cout << "W = up";
	gotoxy(100, 12);
	cout << "S = down";
	gotoxy(100, 13);
	cout << "D = Shoot";
	
	textcolor(GREEN);
	gotoxy(midx-10, midy);
	cout << "Press any key to start";
	getch();
	gotoxy(midx-10, midy);
	cout << "                      ";
	
	textcolor(WHITE);
}

void genenemy(int ind){
	/*
	range random [3, 25]
	
	karena rand() % (23) = [0,22]
	lalu x dan y ditambah 3, sehingga menjadi [3,25]
	
	*/
	
	enemyposy[ind] = 3 + rand() % (23);	
}

void drawenemy(int ind){
	if(enemyflag[ind]==true){
		textcolor(LIGHTGREEN);
		gotoxy(enemyposx[ind], enemyposy[ind]);
		cout << "\xaao-\\\\>";
		textcolor(WHITE);
	}	
}

void eraseenemy(int ind){
	gotoxy(enemyposx[ind], enemyposy[ind]);
	cout << "      ";
}

void resetenemy(int ind){
	eraseenemy(ind);
	enemyposx[ind] = 84;
	genenemy(ind);
}

bool coll(int ind){
	if(enemyposx[ind] - posbullx[ind] >0){
		if(enemyposy[ind]-posbully[ind] == 0){
		return false;
		}
	}
	return true;
}

void drawplayer(){
	textcolor(LIGHTWHITE);
	
	gotoxy(plposx, plposy);
	cout << player;
	
	textcolor(WHITE);
}

void eraseplayer(){
	
	gotoxy(plposx, plposy);
	cout << " ";
	gotoxy(plposx+1, plposy);
	cout << " ";
}
void drawbullet(int ind){
	if(bullflag[ind]==true){
	textcolor(YELLOW);
	gotoxy(posbullx[ind], posbully[ind]);
	cout << "\xf8";
	textcolor(WHITE);
	}
}

void erasebullet(int ind){
	
	gotoxy(posbullx[ind], posbully[ind]);
	cout << " ";
	
}

//void shoot(){
//	while(true){
//	
//	erasebullet();
//	char mov2 = getch();
//	if(mov2==KEY_SPACE){
//		if(posbullx < 90){
//			posbullx++;
//		}
//	}
	//drawbullet(ind);
	
//	Sleep(50);
//	}
//}

void updatescr(){

	gotoxy(midx-3, 1);
	cout << "Score: " << score;
	
}

void updatelifes(){
	
	gotoxy(maxx+1, 0);
	cout << "Life: " << lifes;
}

void eraselifes(){
	gotoxy(maxx+1, 0);
	cout << "Life:";
}
	
void gameover(){
	system("cls");
	textcolor(RED);
	gotoxy(midx-10, midy);
	cout << "GAME OVER";
	gotoxy(midx-10, midy+1);
	cout << "Press any key to go back to menu";
	textcolor(WHITE);
	getch();
}


void play(){
	score = 0;
	posbully[0] = plposy;
	posbully[1] = plposy;
	posbullx[0] = plposx + 2;
	posbullx[1] = plposx + 2;
	enemyflag[0] = true;
	enemyflag[1] = false;
	enemyflag[2] = false;
	enemyflag[3] = false;
	
	bullflag[0] = false;
	bullflag[1] = false;
	enemyposx[0]=enemyposx[1]=enemyposx[2]=enemyposx[3] = 84;
	system("cls");
	draw();
	updatescr();
	updatelifes();
	genenemy(0);
	genenemy(1);
	genenemy(2);
	genenemy(3);
	lifes = 3;
	
	while(true)
	{

		
		if(kbhit())
		{
					
			char mov = getch();
			if(mov=='w'|| mov== 'W' || mov==KEY_UP)
			{
				if(plposy>2){
					plposy--;
				}
			} 			
			else if(mov=='s' || mov=='S' || mov==KEY_DOWN)
			{
				if(plposy<maxy){
					plposy++;
				}
			} 			
<<<<<<< HEAD:9_A.cpp
			
			
			if(mov == KEY_SPACE)
=======
			else if(mov == KEY_SPACE)
>>>>>>> 3506f7017da803f5ca482517fe4de978e7ced17c:game4.cpp
			{
				
				if (bullflag[0] = false){
					bullflag[0] = true;
				} else if (bullflag[0] = true){
					bullflag[1] = true;
				}
			}			
		}
		
		drawplayer();
		
		for(int i=0; i<2; i++){
			drawbullet(i);
		}
		
		for (int i = 0; i < 4; i++)
		{
			drawenemy(i);
		}
		
		for (int i = 0; i < 4; i++)
		{
			if (coll(i) == true)
			{
				score++;
				updatescr();
			}
		}
		
		Sleep(30);
		eraseplayer();
		
		for (int i = 0; i < 3; i++){
			erasebullet(i);
		}
		
		
		for (int i = 0; i < 3; i++){
			eraseenemy(i);
		}
		
		
		
		if(enemyposx[0]==50){
			if(enemyflag[1]==false){
				enemyflag[1]= true;
			}
		}
		
		if(enemyposx[1]==50){
			if(enemyflag[2]==false){
				enemyflag[2]= true;
			}
		}
		
		
		
		for(int i=0; i<4; i++){
			if(enemyflag[i]==true){
				enemyposx[i] -= 1;
			}
		}
		
		for(int i=0; i<4; i++){
<<<<<<< HEAD:9_A.cpp
			if(posbullx[0] < maxx || posbullx[1] < maxx){
				if(bullflag[i]==true){
					posbullx[i] += 1;
				}
			}	
=======
			if(bullflag[i]==true){
				enemyposx[i] += 1;
			}
>>>>>>> 3506f7017da803f5ca482517fe4de978e7ced17c:game4.cpp
		}
		
		for(int i=0; i<4; i++){
			
			if(enemyposx[i]==0 || enemyposx[i] == plposx){
				resetenemy(i);
				lifes--;
				updatelifes();
				
				if(lifes<=0){
					gameover();
					return;
				}
			}
		}
	}
}


int main(){

	setcursor(0,0);
	gotoxy(midx, midy-1);
	cout << "  ///";
	gotoxy(midx, midy);
	cout << "\xaao===>";
	gotoxy(midx, midy+1);
	cout << " zaky";
	textcolor(0);
	getche();
	textcolor(WHITE);
	
	do{
		system("cls");
		
		play();
				
	} while(true);
	
	
	return 0;
}
