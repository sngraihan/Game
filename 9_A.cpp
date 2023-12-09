#include <iostream>
#include <conio.h>
#include <windows.h>

//           cd OneDrive\Documents\dev c++\New Folder
//              g++ -o game 9_A.cpp

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
bool enemyflag[4];

int posbully[4];
int posbullx[4];

bool bullflag[4];

char player[2] = {'\xdb', '\xfe'};

int score=0;
int lifes=5;

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

//void menu(){
//	gotoxy(midx-10,midy);
//	cout << "Pick Option:";
//	
//}
void instructions(){
	system("cls");
	textcolor(BLUE);
	gotoxy(midx-10, midy-5);
	cout << "objective:";
	gotoxy(midx-10, midy-4);
	textcolor(RED);
	cout << "- KILL ALL BIRDS!";
	gotoxy(midx-10, midy-3);
	cout << "- DONT LET BIRDS GET THROUGH!";
	textcolor(BLUE);
	gotoxy(midx-10, midy-2);
	cout << "movement:";
	gotoxy(midx-10, midy-1);
	cout << "W = up";
	gotoxy(midx-10, midy);
	cout << "S = down";
	gotoxy(midx-10, midy+1);
	cout << "SPACE = Shoot";
	textcolor(YELLOW);
	gotoxy(midx-10, midy+4);
	cout << "Press any key to go back to menu";
	textcolor(WHITE);
	getche();
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
	cout << "SPACE = Shoot";
	
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
		cout << "\xaao\\\\\\>";
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

void genbullet(int ind){
	
	posbullx[ind] = plposx;
	posbully[ind] = plposy;
}

void resetbullet(int ind){
	erasebullet(ind);
	bullflag[ind] = false;
	//genbullet(ind);
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
	gotoxy(midx-5, midy);
	cout << "GAME OVER";
	gotoxy(midx-5, midy+1);
	cout << "Highest score:" << score;

	textcolor(YELLOW);
	gotoxy(midx-5, midy+3);
	cout << "Press any key to go back to menu";
	textcolor(WHITE);
	getch();
}

bool coll(int ind){
	for(int i=0; i<4; i++){
	if(enemyposx[ind] - posbullx[i] >= 0 && enemyposx[ind] - posbullx[i] < 2){
		if (enemyposy[ind] - posbully[i] >= 0 && enemyposy[ind] - posbully[i] < 2){
			resetbullet(i);
			resetenemy(ind);
		return true;
		}
	}

	}
	return false;
}


void playeasy(){
	score = 0;
	enemyflag[0] = true;
	enemyflag[1] = false;
	enemyflag[2] = false;
	enemyflag[3] = false;
	
	bullflag[0] = false;
	bullflag[1] = false;
	bullflag[2] = false;
	bullflag[3] = false;


	enemyposx[0]=enemyposx[1]=enemyposx[2]=enemyposx[3] = 84;
	posbullx[0]=posbullx[1]=posbullx[2]=posbullx[3]= plposx;
	posbully[0]=posbully[1]=posbully[2]=posbully[3] = plposy;
	
	
	system("cls");
	draw();
	updatescr();
	updatelifes();
	genenemy(0);
	genenemy(1);
	genenemy(2);
	genenemy(3);
	lifes = 5;
	
	while(true)
	{
			
		if(kbhit())
		{
					
			char mov = getch();
			if(mov=='w'|| mov== 'W' || mov==KEY_UP)
			{
				if(plposy>3){
					plposy--;
				}
			} 			
			else if(mov=='s' || mov=='S' || mov==KEY_DOWN)
			{
				if(plposy<maxy-1){
					plposy++;
				}
			} else if(mov == KEY_SPACE){
				for (int i = 0; i < 4; i++){
               		if (bullflag[i] == false){
                    	bullflag[i] = true;
                    	posbullx[i] = plposx;
                    	posbully[i] = plposy;
                    	break; 
                	}
            	}
				
			}		
		}
		
		drawplayer();
		
		for(int i=0; i<4; i++){
			drawbullet(i);
		}
		
		for (int i = 0; i < 4; i++)
		{
			drawenemy(i);
		}
		
		for (int i = 0; i < 4; i++){
				if (coll(i) == true)
				{
					score++;
					updatescr();
				}
		}
		
		Sleep(50);
		eraseplayer();
		
		for (int i = 0; i < 4; i++){
			erasebullet(i);
		}
		
		
		for (int i = 0; i < 4; i++){
			eraseenemy(i);
		}
		
		
		
		if(enemyposx[0]==30){
			if(enemyflag[1]==false){
				enemyflag[1]= true;
			}
		}
		
		if(enemyposx[1]==30){
			if(enemyflag[2]==false){
				enemyflag[2]= true;
			}
		}
		
		
		
		for(int i=0; i<4; i++){
			if(enemyflag[i]==true){
				enemyposx[i]--;
			}
		}
		
		for(int i=0; i<4; i++){

			if(bullflag[i]==true && posbullx[i] < maxx-1){
				
					posbullx[i]++;
					
			}	
		}
		
		for(int i=0;i<4;i++){
			if(posbullx[i]==maxx-1){
				resetbullet(i);
			}
			
		}
		
		for(int i=0; i<4; i++){
			
			if(enemyposx[i]==0 || enemyposx[i] == plposx){
				resetenemy(i);
				lifes--;
				updatelifes();
			}
		}
		
		if(lifes<=0){
					gameover();
					lifes = 5;
					return;
		}
	}
}



void playmedium(){
	score = 0;
	enemyflag[0] = true;
	enemyflag[1] = false;
	enemyflag[2] = false;
	enemyflag[3] = false;
	
	bullflag[0] = false;
	bullflag[1] = false;
	bullflag[2] = false;
	bullflag[3] = false;


	enemyposx[0]=enemyposx[1]=enemyposx[2]=enemyposx[3] = 84;
	posbullx[0]=posbullx[1]=posbullx[2]=posbullx[3]= plposx;
	posbully[0]=posbully[1]=posbully[2]=posbully[3] = plposy;
	
	
	system("cls");
	draw();
	updatescr();
	updatelifes();
	genenemy(0);
	genenemy(1);
	genenemy(2);
	genenemy(3);
	lifes = 5;
	
	while(true)
	{
			
		if(kbhit())
		{
					
			char mov = getch();
			if(mov=='w'|| mov== 'W' || mov==KEY_UP)
			{
				if(plposy>3){
					plposy--;
				}
			} 			
			else if(mov=='s' || mov=='S' || mov==KEY_DOWN)
			{
				if(plposy<maxy-1){
					plposy++;
				}
			} else if(mov == KEY_SPACE){
				for (int i = 0; i < 4; i++){
               		if (bullflag[i] == false){
                    	bullflag[i] = true;
                    	posbullx[i] = plposx;
                    	posbully[i] = plposy;
                    	break; 
                	}
            	}
				
			}		
		}
		
		drawplayer();
		
		for(int i=0; i<4; i++){
			drawbullet(i);
		}
		
		for (int i = 0; i < 4; i++)
		{
			drawenemy(i);
		}
		
		for (int i = 0; i < 4; i++){
				if (coll(i) == true)
				{
					score++;
					updatescr();
				}
		}
		
		Sleep(40);
		eraseplayer();
		
		for (int i = 0; i < 4; i++){
			erasebullet(i);
		}
		
		
		for (int i = 0; i < 4; i++){
			eraseenemy(i);
		}
		
		
		
		if(enemyposx[0]==30){
			if(enemyflag[1]==false){
				enemyflag[1]= true;
			}
		}
		
		if(enemyposx[1]==30){
			if(enemyflag[2]==false){
				enemyflag[2]= true;
			}
		}
		
		if(enemyposx[2]==30){
			if(enemyflag[3]==false){
				enemyflag[3]= true;
			}
		}
		
		
		for(int i=0; i<4; i++){
			if(enemyflag[i]==true){
				enemyposx[i]--;
			}
		}
		
		for(int i=0; i<4; i++){

			if(bullflag[i]==true && posbullx[i] < maxx-1){
				
					posbullx[i]++;
					
			}	
		}
		
		for(int i=0;i<4;i++){
			if(posbullx[i]==maxx-1){
				resetbullet(i);
			}
			
		}
		
		for(int i=0; i<4; i++){
			
			if(enemyposx[i]==0 || enemyposx[i] == plposx){
				resetenemy(i);
				lifes--;
				updatelifes();
			}
		}
		
		if(lifes<=0){
					gameover();
					lifes = 5;
					return;
		}
	}
}



void playhard(){

}

void select(){
	system("cls");
	textcolor(PINK);
	gotoxy(midx-10,midy-7);
	cout << "1. easy";
	gotoxy(midx-10,midy-6);
	cout << "2. medium";
	gotoxy(midx-10,midy-5);
	cout << "3. hard";
	gotoxy(midx-10,midy-4);
	cout << "4. impossible";
	gotoxy(midx-10,midy-3);
	cout << "5. back to menu";
	gotoxy(midx-10,midy-1);	
	cout << "select game difficulty: ";
	textcolor(WHITE);
	char op2 = getche();
		
		if (op2 == '1')
			playeasy();
		else if (op2 == '2')
			playmedium();
		else if (op2 == '3')
			playhard();
		else if (op2 == '5')
			return;
	
}

int main(){

//	setcursor(0,0);
//	gotoxy(midx, midy-1);
//	cout << "  ///";
//	gotoxy(midx, midy);
//	cout << "\xaao===>";
//	gotoxy(midx, midy+1);
//	cout << " amalaaaa";
//	textcolor(0);
//	getche();
//	textcolor(WHITE);
	
	do{
		system("cls");
		textcolor(YELLOW);
		for(int i=midx-10; i<midx+14; i++){
		gotoxy(i, midy-10);
		cout << "\xcd";
		}
		gotoxy(midx-10, midy-9);
		cout << "\xba      BIRD ATTACK     \xba";
		gotoxy(midx-10, midy-8);
		cout << "\xba                      \xba";
		for(int i=midx-10; i<midx+14; i++){
		gotoxy(i, midy-7);
		cout << "\xcd";
		}
		textcolor(LIGHTGREEN);
		gotoxy(midx-1, midy-8);
		cout << "\xaao\\\\\\>";
		textcolor(YELLOW);
		gotoxy(midx-10, midy-5);
		cout << "1. Start Game";
		gotoxy(midx-10, midy-4);
		cout << "2. Instructions";
		gotoxy(midx-10, midy-3);
		cout << "3. Quit";
		gotoxy(midx-10, midy-2);
		cout << "Select option: ";

		textcolor(WHITE);
		char op = getche();
		
		if (op == '1')
			select();
		else if (op == '2')
			instructions();
		else if (op == '3')
			exit(0);
		
				
	} while(true);
	
	
	return 0;
}
