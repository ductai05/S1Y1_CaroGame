#include "library.h"
#include "GameControl.h"
#include "Console.h"
#include "Graphic.h"
#include "Newgame.h"
#include "LoadGame.h"

#define co_theme 15, 0
using namespace std;

/*-----------------------@- MENU ABOUT -@-------------------------------------*/
void about(int Xi, int Yi) {
	system("cls");
	drawABOUT(Xi - 10, Yi - 9);
	int XX = Xi - 6, YY = Yi + 1;

	drawPopUp(XX - 28, YY - 2, 25, 90);
	gotoXY(XX + 4, YY);      cout << "HCMUS - 23TNT1 - Group 5:";
	gotoXY(XX + 3, YY + 18); cout << "Advisor: Dr.Truong Toan Thinh";

	setColor(14, 0);
	gotoXY(XX + 6, YY + 20); cout << "<< Press ESC to exit >>";
	setColor(co_theme);

	Xi = 29, Yi = 13;
	decorate_draw(Xi, Yi, "pixel_art/Khoa.txt");
	setColor(co_theme); 
	gotoXY(Xi + 1, Yi + 15);  cout << "Dinh Duc Anh Khoa";
	gotoXY(Xi + 6, Yi + 16); cout << "23122001";

	decorate_draw(Xi + 21, Yi, "pixel_art/Duong.txt");
	setColor(co_theme);
	gotoXY(Xi + 21, Yi + 15);  cout << "Nguyen Dinh Ha Duong";
	gotoXY(Xi + 27, Yi + 16); cout << "23122002";

	decorate_draw(Xi + 42, Yi, "pixel_art/Tai.txt");
	setColor(co_theme);
	gotoXY(Xi + 46, Yi + 15);  cout << "Dinh Duc Tai";
	gotoXY(Xi + 48, Yi + 16); cout << "23122013";

	decorate_draw(Xi + 63, Yi, "pixel_art/Trung.txt");
	setColor(co_theme);
	gotoXY(Xi + 64, Yi + 15);  cout << "Nguyen Le Hoang Trung";
	gotoXY(Xi + 70, Yi + 16); cout << "23122004";

	while (nextMove() != 5);
}

/*-----------------------@- MENU HELP -@-------------------------------------*/
void help(int Xi, int Yi) {
	system("cls");
	drawHELP(Xi - 5, Yi - 9);

	int XX = Xi - 27, YY = Yi - 1;
	int h = 15, w = 76;

	drawPopUp(XX, YY, h, w);
	decorate_draw(31, 25 , "pixel_art/Whale.txt");
	setColor(co_theme);
	for (int i = 1; i < h - 3; ++i) {
		gotoXY(XX + 37, YY + i); 
		cout << "|";
	}

	setColor(11, 0);
	gotoXY(XX + 12, YY + 1);
	cout << "KEYBOARD GUIDE";

	gotoXY(XX + 54, YY + 1);
	cout << "RULE";

	setColor(co_theme);
	gotoXY(XX + 14, YY + 3);
	cout << "Player 1    Player 2";
	gotoXY(XX + 3, YY + 4);
	cout << "Go up:        W           " << char(30);
	gotoXY(XX + 3, YY + 5);
	cout << "Go left:      A           " << char(17);
	gotoXY(XX + 3, YY + 6);
	cout << "Go down:      S           " << char(31);
	gotoXY(XX + 3, YY + 7);
	cout << "Go right:     D           " << char(16);
	gotoXY(XX + 3, YY + 8);
	cout << "Mark    :   Space       Enter";
	gotoXY(XX + 6, YY + 10);
	cout << "         Other";
	gotoXY(XX + 3, YY + 11);
	cout << "Undo: U    Save: I    Exit: Esc";

	gotoXY(XX + 39, YY + 3);
	cout << "  Players alternate turns putting";
	gotoXY(XX + 39, YY + 4);
	cout << "their marks on an empty intersection";
	gotoXY(XX + 39, YY + 5);
	cout << "  X plays first. The winner is the";
	gotoXY(XX + 39, YY + 6);
	cout << "  first player to form an unbroken";
	gotoXY(XX + 39, YY + 7);
	cout << "   line of 5 marks horizontally,";
	gotoXY(XX + 39, YY + 8);
	cout << " vertically, or diagonally. If the";
	gotoXY(XX + 39, YY + 9);
	cout << " board is completely filled and no";
	gotoXY(XX + 39, YY + 10);
	cout << "  one can make a line of 5 marks,";
	gotoXY(XX + 39, YY + 11);
	cout << "   then the game ends in a draw.";

	setColor(14, 0);
	gotoXY(XX + 27, YY + 13); cout << "<< Press ESC to exit >>";
	setColor(co_theme);

	while (nextMove() != 5);
}

/*-----------------------@- MENU EXIT -@-------------------------------------*/
void exit() {
	system("cls");
	exit(0);
}

void drawMenu(int XX, int YY) { 
	struct _aboutMenu {

		int X, Y, size, b_color;
		string str;
		
		void draw() {
			drawBoardMenu(X, Y, size, b_color, str);
		}
	};

	_aboutMenu s1[5], s2[5];  // s1: unselect  ;  s2: select
	s1[0] = { XX, YY, 20, 15, "     NEW GAME     " };
	s1[1] = { XX, YY + 3, 20, 15, "     LOAD GAME    " };
	s1[2] = { XX, YY + 6, 20, 15, "       ABOUT      " };
	s1[3] = { XX, YY + 9, 20, 15, "       HELP       " };
	s1[4] = { XX, YY + 12, 20, 15, "       EXIT       " };

	s2[0] = { XX, YY, 20, 14, ">>   NEW GAME   <<" };
	s2[1] = { XX, YY + 3, 20, 14, ">>   LOAD GAME  <<"};
	s2[2] = { XX, YY + 6, 20, 14, ">>     ABOUT    <<"};
	s2[3] = { XX, YY + 9, 20, 14, ">>     HELP     <<" };
	s2[4] = { XX, YY + 12, 20, 14, ">>     EXIT     <<" };

	pullList();  // pull data to fileNames
	int S = 0;   // pointer in menu
	
	while (true) {
		/*------------------ DECOR ---------------------------*/
		drawCARO(XX - 6, YY - 9);
		for (int i = 0; i < 5; ++i)
			s1[i].draw();
		s2[S].draw();
		
		decorate_draw(8, 8, "pixel_art/Deadpool.txt");
		decorate_draw(90, 8, "pixel_art/Captain_America.txt");
		/*----------------------------------------------------*/

		ShowCur(0);
		int _in = nextMove();

		/*----------------- Menu selection -------------------*/
		if (_in == 1) S = (S + 4) % 5;        // Up
		else if (_in == 3) S = (S + 1) % 5;   // Down
		else if (_in == 0) {				  // Enter
			if (S == 0) newGame(XX, YY);
			else if (S == 1) loadGame(XX, YY);
			else if (S == 2) about(XX, YY);
			else if (S == 3) help(XX, YY);
			else if (S == 4) exit();
			else assert(false);
			system("cls");
		}
		/*----------------------------------------------------*/
	}
}

int32_t main() {
	fixConsoleWindow(140, 45);						  // Fix window size
	SetConsoleTitle(L"GameCaro - 23TNT1 - Group 5");  // Console's title

	ShowCur(0);
	drawMenu(61, 12);

	return 0;
}


