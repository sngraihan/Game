#include <iostream>
#include <conio.h>
#include <ncurses/ncurses.h>
#include <windows.h>
#include <unistd.h>

using namespace std;

#define warna init_pair

bool game = true;
int maxy, maxx, midy, midx;
char arah;

int lebar = 90, tinggi = 26, tinggigame = 50;

void windowplay(){
	maxy = 10;
	maxx = 55;
	//bikin window
//	WINDOW * win = newwin(maxy, maxx, 10, 30);
//	refresh();
//	
//	box(win, 0, 0);
//	wrefresh(win);
//	for(int i=2; i<)
	
	
	mvprintw(0, 30, "Player 1(left): w=up, s=down, d=shoot");
	mvprintw(1, 30, "Player 2(right): i=up, k=down, j=shoot");
	
    int badany = midy;
    int badanx = 1;
    
	int badanyp2 = midy;
	int badanxp2 = maxx-2;
	
	
	int posbullyp1 = midy;
	int posbullxp1 = badanx+1;
	
	int posbullyp2 = badanyp2;
	int posbullxp2 = badanxp2-1;


while ((arah = getch())) {
	
		//player pertama
	        
        mvprintw(badany, badanx, " ");
      	refresh();
      	
        switch (arah) {
            case 'w':
                badany -= 1;
                break;
            case 'W':
                badany -= 1;
                break;
            case 's':
                badany += 1;
                break;
            case 'S':
                badany += 1;
                break;
        }
        switch(arah){
		case 'd': 
		posbullyp1 = badany;
        posbullxp1 = badanx + 1;      
                while (posbullxp1 < maxx - 2) {
                    mvprintw(posbullyp1, posbullxp1, " ");
                    refresh();
                    
					posbullxp1++;
					
                    mvprintw(posbullyp1, posbullxp1, "=");
                    refresh();

                    
                    Sleep(1);
                }
                if(posbullxp1 = maxx - 2){
                	mvprintw(posbullyp1, posbullxp1, " ");
                    refresh();
				}
                break;
        case 'D': 
		posbullyp1 = badany;
        posbullxp1 = badanx + 1;      
                while (posbullxp1 < maxx - 2) {
                    mvprintw(posbullyp1, posbullxp1, " ");
                    refresh();
                    
					posbullxp1++;
					
                    mvprintw(posbullyp1, posbullxp1, "=");
                    refresh();

                    
                    Sleep(1);
                }
                if(posbullxp1 = maxx - 2){
                	mvprintw(posbullyp1, posbullxp1, " ");
                    refresh();
				}
                break;
    	}
        
        if(badany <= 1){
        	badany = 1;
		} else if(badany >= maxy-1){
			badany = maxy - 2;
		}
		
		mvprintw(badany, badanx, ">");
		refresh();
				
		
		
//		//player kedua
//		
//		mvwprintw(win, badanyp2, badanxp2, " ");
//		wrefresh(win);
//		
//		switch(arah){
//			case 'i':
//				badanyp2 -= 1;
//				break;
//			case 'I':
//				badanyp2 -= 1;
//				break;
//			case 'k':
//				badanyp2 += 1;
//				break;
//			case 'K':
//				badanyp2 += 1;
//				break;
//		}
//		
//		switch(arah){
//		case 'j': 
//		posbullyp2 = badanyp2;
//        posbullxp2 = badanxp2 - 1;      
//                while (posbullxp2 > 1) {
//                    mvwprintw(win, posbullyp2, posbullxp2, " ");
//                    wrefresh(win);
//                    
//					posbullxp2--;
//					
//                    mvwprintw(win, posbullyp2, posbullxp2, "=");
//                    wrefresh(win);
//
//                    
//                    Sleep(1);
//                }
//                if(posbullxp2 = 1){
//                	mvwprintw(win, posbullyp2, posbullxp2, " ");
//                    wrefresh(win);
//				}
//                break;
//        case 'J': 
//		posbullyp2 = badanyp2;
//        posbullxp2 = badanxp2 - 1;      
//                while (posbullxp2 > 1) {
//                    mvwprintw(win, posbullyp2, posbullxp2, " ");
//                    wrefresh(win);
//                    
//					posbullxp2--;
//					
//                    mvwprintw(win, posbullyp2, posbullxp2, "=");
//                    wrefresh(win);
//
//                    
//                    Sleep(1);
//                }
//                if(posbullxp2 = 1){
//                	mvwprintw(win, posbullyp2, posbullxp2, " ");
//                    wrefresh(win);
//				}
//                break;
//		}
//		
//		if(badanyp2 <= 1){
//			badanyp2 = 1;
//		} else if(badanyp2 >= maxy-1){
//			badanyp2 = maxy-2;
//		}
//		
//		mvwprintw(win, badanyp2, badanxp2, "<");
//		wrefresh(win);
			
		Sleep(1);
		refresh();
	}	
	
	
	
	
	
	
	

}


void loading(){
	for(int j=0; j<3; j++){
	Sleep(50);
	mvprintw(1,1,"loading   ");
	refresh();
	for(int i=8; i<11; i++){
	Sleep(200);
	mvprintw(1,i, ".");
	refresh();
}
}
}

void bullet(WINDOW * win){
	maxy = 10;
	maxx = 55;
	int posbullyp1 = midy;
	int posbullxp1 = 2;
	
	int posbullyp2 = midy;
	int posbullxp2 = maxx-3;
	
	char arah;
	while (arah = getch()){
		
		mvwprintw(win,1,1,"wubiwubwubc");
		
		switch(arah){
			
			
		
		}
	}
	
	
}


int main(){
	
	initscr();
	noecho();
	curs_set(0);
	getmaxyx(stdscr,maxy,maxx);
	maxy;
	maxx;
	midx = lebar/2;
	midy = tinggigame/2;
	
	
	
	
//	char burung[2][6] = {{'@', '=', '\\', '\\', '\\', '>'},
//					 {' ', ' ', ' ', '\\', '\\', '\\' }};
//	mvprintw(tinggigame, lebar, burung);
	
	windowplay();
	if(game==false){
		
	}
	
	
	
	getch();
	endwin();
	
	
	
	
	return 0;
}
