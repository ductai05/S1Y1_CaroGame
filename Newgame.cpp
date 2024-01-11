#include "Newgame.h"
#include "GameControl.h"
using namespace std;

/*-----------------@- Function Import name -@-----------------------*/
bool putname(int XX, int YY, string &str) {   
	int sz = 0, Xi = XX, Yi = YY;	// [Xi, Yi] is located of pointer in head line
	string tmp = str;				// tmp is a origin name

	setColor(15, 8);
	gotoXY(Xi, Yi);
	cout << str;

	while (true) {
		char ch = _getch();
		if ((int)ch < 0) {			// If input is arrow, we must getchar one more
			ch = _getch();
			continue;
		}

		if (ch == 13) break;		// If input is "enter" then exit with putname = 1

		if (ch == 27) return 0;		// If input is "esc" then back to menu with putname = 2

		if (ch == '\b' && sz) {		// If input is "backspace" then delete last char
			str.pop_back(); --sz;
			--XX; gotoXY(XX, YY); cout << " ";
			gotoXY(XX, YY);

			if (sz == 0) {
				str = tmp;
				setColor(15, 8);
				gotoXY(Xi, Yi);
				cout << str;
			}

		} else if ((('a' <= ch && ch <= 'z') || ('A' <= ch && ch <= 'Z') || isdigit(ch)) && sz < 10) {  // Length of name is less than or equal 10
			if (sz == 0) {
				str = "";
				setColor(15, 0);
				gotoXY(Xi, Yi);
				cout << "          ";
			}

			str.push_back(ch); ++sz;
			gotoXY(XX, YY);
			cout << ch; ++XX;
		}
	} return 1;
}
	
void mode_2(int XX, int YY) {
	/*------------------ DECOR ---------------------------*/
	system("cls"); drawNEW_GAME(XX - 20, YY - 9);
	decorate_draw(48, 21, "pixel_art/Swords.txt");
	/*----------------------------------------------------*/

	/*----------------- Import Name  ---------------------*/
	string name1, name2;
	drawBoardMenu(XX, YY, 29, 15, " NAME PLAYER 1: ");
	if (!putname(XX + 17, YY + 1, name1 = "[player1]")) return;   // Name of player 1

	drawBoardMenu(XX, YY + 3, 29, 15, " NAME PLAYER 2: ");
	if (!putname(XX + 17, YY + 4, name2 = "[player2]")) return;   // Name of player 2

	startGame(false, true, XX + 3, YY, name1, name2, {}, "", 0, 0);
	/*----------------------------------------------------*/
}

void mode_1(int XX, int YY) {
	/*------------------ DECOR ---------------------------*/
	system("cls"); drawNEW_GAME(XX - 21, YY - 9);
	decorate_draw(48, 21, "pixel_art/Swords.txt");
	/*----------------------------------------------------*/

	/*----------------- Import Name  ---------------------*/
	string name;
	drawBoardMenu(XX, YY, 27, 15, " NAME PLAYER:   ");
	if (!putname(XX + 15, YY + 1, name = "[player]")) return;       // Name of player
	startGame(true, true, XX + 2, YY, name, "BOT", {}, "", 0, 0);   
	/*----------------------------------------------------*/
}
	
void newGame(int XX, int YY) {
	struct _aboutMenu1 {
		int X1, Y1, size1, b_color1;
		string str1;

		void draw() {
			drawBoardMenu(X1, Y1, size1, b_color1, str1);
		}
	};

	_aboutMenu1 s1[2], s2[2];  // s1: unselect  ;  s2: select
	s1[0] = { XX, YY + 1, 21, 15, "     1 PLAYER      " };
	s1[1] = { XX, YY + 4, 21, 15, "     2 PLAYERS     " };

	s2[0] = { XX, YY + 1, 21, 14, ">>   1 PLAYER    <<" };
	s2[1] = { XX, YY + 4, 21, 14, ">>   2 PLAYERS   <<" };

	system("cls");
	int S = 0;  // pointer in menu

	while (true) {
		/*------------------ DECOR ---------------------------*/
		drawNEW_GAME(XX - 23, YY - 9);
		decorate_draw(48, 21, "pixel_art/swords.txt");
		for (int i = 0; i < 2; ++i)
			s1[i].draw();
		s2[S].draw();
		/*----------------------------------------------------*/

		/*------------- Menu Newgame selection ---------------*/
		int _in1 = nextMove();
		if (_in1 == 1 || _in1 == 3) S ^= 1;       // Move
		else if (_in1 == 0) {					  // Enter
			if (S == 0) mode_1(XX - 2, YY);		  // Mode: 1 player
			else if (S == 1) mode_2(XX - 3, YY);  // Mode: 2 player
			else assert(false);
			break;
		} else if (_in1 == 5)					  // Exit
			break;
		/*----------------------------------------------------*/
	}
}



