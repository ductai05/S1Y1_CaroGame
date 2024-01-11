#include "Graphic.h"
#include "GameControl.h"
#define co_theme 15,0
const int BOARD_SIZE = 15;

extern _Point status[BOARD_SIZE + 5][BOARD_SIZE + 5];
void drawA(int XX, int YY) { // 6 * 8
	gotoXY(XX + 1, YY);
	setColor(0, 0); cout << "     ";
	setColor(co_theme); cout << char(187);

	gotoXY(XX, YY + 1);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(201) << char(205) << char(205);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(187);

	gotoXY(XX, YY + 2);
	setColor(0, 0); cout << "       ";
	setColor(co_theme); cout << char(186);

	gotoXY(XX, YY + 3);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(201) << char(205) << char(205);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(186);

	gotoXY(XX, YY + 4);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(186) << "  ";
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(186);

	gotoXY(XX, YY + 5);
	cout << char(200) << char(205) << char(188) << "  " << char(200) << char(205) << char(188);
}

void drawB(int XX, int YY) { // 6 * 8
	gotoXY(XX, YY);
	setColor(0, 0); for (int i = 0; i < 6; ++i) cout << " ";
	setColor(co_theme); cout << char(187);

	gotoXY(XX, YY + 1);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(201) << char(205) << char(205);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(187);
	
	gotoXY(XX, YY + 2);
	setColor(0, 0); for (int i = 0; i < 6; ++i) cout << " ";
	setColor(co_theme); cout << char(201) << char(188);

	gotoXY(XX, YY + 3);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(201) << char(205) << char(205);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(187);

	gotoXY(XX, YY + 4);
	setColor(0, 0); for (int i = 0; i < 6; ++i) cout << " ";
	setColor(co_theme); cout << char(201) << char(188);

	gotoXY(XX, YY + 5);
	cout << char(200);
	for (int i = 0; i < 5; ++i) cout << char(205);
	cout << char(188);
}

void drawC(int XX, int YY) { // 6 * 8
	gotoXY(XX + 1, YY);
	setColor(0, 0); cout << "      ";
	setColor(co_theme); cout << char(187);

	gotoXY(XX, YY + 1);
	setColor(0, 0);  cout << "  ";
	setColor(co_theme);
	cout << char(201);
	for (int i = 1; i <= 4; ++i) cout << char(205);
	cout << char(188);

	gotoXY(XX, YY + 2);
	setColor(0, 0);  cout << "  ";
	setColor(co_theme); cout << char(186);

	gotoXY(XX, YY + 3);
	setColor(0, 0);  cout << "  ";
	setColor(co_theme); cout << char(186);

	gotoXY(XX, YY + 4);
	cout << char(200);
	setColor(0, 0);  cout << "      ";
	setColor(co_theme); cout << char(187);

	gotoXY(XX + 1, YY + 5);
	cout << char(200);
	for (int i = 1; i <= 5; ++i) cout << char(205);
	cout << char(188);
}

void drawO(int XX, int YY, int co_txt = 0) { // 6 * 9
	gotoXY(XX + 1, YY);
	setColor(co_txt, 0); cout << "      ";
	setColor(15, co_txt); cout << char(187);

	gotoXY(XX, YY + 1);
	setColor(co_txt, 0); cout << "  ";
	setColor(15, co_txt); cout << char(201) << char(205) << char(205) << char(205);
	setColor(co_txt, 0); cout << "  ";
	setColor(15, co_txt); cout << char(187);

	gotoXY(XX, YY + 2);
	setColor(co_txt, 0); cout << "  ";
	setColor(15, co_txt); cout << char(186) << "   ";
	setColor(co_txt, 0); cout << "  ";
	setColor(15, co_txt); cout << char(186);

	gotoXY(XX, YY + 3);
	setColor(co_txt, 0); cout << "  ";
	setColor(15, co_txt); cout << char(186) << "   ";
	setColor(co_txt, 0); cout << "  ";
	setColor(15, co_txt); cout << char(186);

	gotoXY(XX, YY + 4);
	cout << char(200);
	setColor(co_txt, 0); cout << "      ";
	setColor(15, co_txt); cout << char(201) << char(188);

	gotoXY(XX + 1, YY + 5);
	cout << char(200);
	for (int i = 1; i <= 5; ++i) cout << char(205);
	cout << char(188);
	setColor(co_theme);
}

void drawR(int XX, int YY) { // 6 * 8
	gotoXY(XX, YY);
	setColor(0, 0); cout << "      ";
	setColor(co_theme); cout << char(187);

	gotoXY(XX, YY + 1);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(201) << char(205) << char(205);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(187);

	gotoXY(XX, YY + 2);
	setColor(0, 0); cout << "      ";
	setColor(co_theme); cout << char(201) << char(188);

	gotoXY(XX, YY + 3);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(201) << char(205) << char(205);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(187);

	gotoXY(XX, YY + 4);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(186) << "  ";
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(186);

	gotoXY(XX, YY + 5);
	cout << char(200) << char(205) << char(188) << "  " << char(200) << char(205) << char(188);
}

void drawU(int XX, int YY) { // 6 * 9
	gotoXY(XX, YY);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(187) << "   ";
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(187);

	gotoXY(XX, YY + 1);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(186) << "   ";
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(186);

	gotoXY(XX, YY + 2);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(186) << "   ";
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(186);

	gotoXY(XX, YY + 3);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(186) << "   ";
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(186);

	gotoXY(XX, YY + 4);
	cout << char(200);
	setColor(0, 0); cout << "      ";
	setColor(co_theme); cout << char(201) << char(188);

	gotoXY(XX + 1, YY + 5);
	cout << char(200);
	for (int i = 1; i <= 5; ++i) cout << char(205);
	cout << char(188);
}

void drawT(int XX, int YY) { // 6 * 9
	gotoXY(XX, YY);
	setColor(0, 0);  cout << "        ";
	setColor(co_theme); cout << char(187);

	gotoXY(XX, YY + 1);
	cout << char(200) << char(205) << char(205);
	setColor(0, 0); cout << "  ";
	setColor(co_theme);  cout << char(201) << char(205) << char(205) << char(188);

	for (int i = 0; i < 3; ++i) {
		gotoXY(XX + 3, YY + 2 + i);
		setColor(0, 0); cout << "  ";
		setColor(co_theme); cout << char(186);
	}

	gotoXY(XX + 3, YY + 5);
	cout << char(200) << char(205) << char(188);
}

void drawL(int XX, int YY) {  // 6 * 8
	gotoXY(XX, YY);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(187);

	for (int i = 1; i <= 3; ++i) {
		gotoXY(XX, YY + i);
		setColor(0, 0); cout << "  ";
		setColor(co_theme); cout << char(186);
	}
	
	gotoXY(XX, YY + 4);
	setColor(0, 0); cout << "       ";
	setColor(co_theme); cout << char(187);

	gotoXY(XX, YY + 5);
	cout << char(200);
	for (int i = 0; i < 6; ++i) cout << char(205);
	cout << char(188);
}

void drawD(int XX, int YY) {  // 6 * 8
	gotoXY(XX, YY);
	setColor(0, 0); cout << "      ";
	setColor(co_theme); cout << char(187);

	gotoXY(XX, YY + 1);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(201) << char(205) << char(205);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(187);

	for (int i = 2; i <= 3; ++i) {
		gotoXY(XX, YY + i);
		setColor(0, 0); cout << "  ";
		setColor(co_theme); cout << char(186) << "  ";
		setColor(0, 0); cout << "  ";
		setColor(co_theme); cout << char(186);
	}

	gotoXY(XX, YY + 4);
	setColor(0, 0); cout << "      ";
	setColor(co_theme); cout << char(201) << char(188);

	gotoXY(XX, YY + 5);
	cout << char(200);
	for (int i = 0; i < 5; ++i) cout << char(205);
	cout << char(188);
}

void drawG(int XX, int YY) {  // 6 * 9
	gotoXY(XX + 1, YY);
	setColor(0, 0); cout << "      ";
	setColor(co_theme); cout << char(187);

	gotoXY(XX, YY + 1);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(201);
	for (int i = 0; i < 4; ++i) cout << char(205);
	cout << char(188);

	gotoXY(XX, YY + 2);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(186) << "  ";
	setColor(0, 0); cout << "   ";
	setColor(co_theme); cout << char(187);

	gotoXY(XX, YY + 3);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(186) << "   ";
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(186);

	gotoXY(XX, YY + 4);
	cout << char(200);
	setColor(0, 0); cout << "      ";
	setColor(co_theme); cout << char(201) << char(188);

	gotoXY(XX + 1, YY + 5);
	cout << char(200);
	for (int i = 0; i < 5; ++i) cout << char(205);
	cout << char(188);
}

void drawM(int XX, int YY) {  // 6 * 11
	gotoXY(XX, YY);
	setColor(0, 0); cout << "   ";
	setColor(co_theme); cout << char(187) << "   ";
	setColor(0, 0); cout << "   ";
	setColor(co_theme); cout << char(187);

	gotoXY(XX, YY + 1);
	setColor(0, 0); cout << "    ";
	setColor(co_theme); cout << char(187) << " ";
	setColor(0, 0); cout << "    ";
	setColor(co_theme); cout << char(186);

	gotoXY(XX, YY + 2);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(201);
	setColor(0, 0); cout << "    ";
	setColor(co_theme); cout << char(201);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(186);

	gotoXY(XX, YY + 3);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(186) << char(200);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(201) << char(188);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(186);

	gotoXY(XX, YY + 4);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(186) << " " << char(200) << char(205) << char(188) << " ";
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(186);

	gotoXY(XX, YY + 5);
	cout << char(200) << char(205) << char(188) << "     " << char(200) << char(205) << char(188);
}

void drawE(int XX, int YY) {  // 6 * 8
	gotoXY(XX, YY);
	setColor(0, 0); cout << "       ";
	setColor(co_theme); cout << char(187);

	gotoXY(XX, YY + 1);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(201);
	for (int i = 0; i < 4; ++i) cout << char(205);
	cout << char(188);

	gotoXY(XX, YY + 2);
	setColor(0, 0); cout << "     ";
	setColor(co_theme); cout << char(187);

	gotoXY(XX, YY + 3);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(201) << char(205) << char(205) << char(188);

	gotoXY(XX, YY + 4);
	setColor(0, 0); cout << "       ";
	setColor(co_theme); cout << char(187);

	gotoXY(XX, YY + 5);
	cout << char(200);
	for (int i = 0; i < 6; ++i) cout << char(205);
	cout << char(188);
}

void drawN(int XX, int YY) {  // 6 * 10
	gotoXY(XX, YY);
	setColor(0, 0); cout << "   ";
	setColor(co_theme); cout << char(187) << "   ";
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(187);

	gotoXY(XX, YY + 1);
	setColor(0, 0); cout << "    ";
	setColor(co_theme); cout << char(187) << "  ";
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(186);

	gotoXY(XX, YY + 2);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(201);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(187) << " ";
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(186);

	gotoXY(XX, YY + 3);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(186) << char(200);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(187);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(186);

	gotoXY(XX, YY + 4);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(186) << " " << char(200);
	setColor(0, 0); cout << "    ";
	setColor(co_theme); cout << char(186);

	gotoXY(XX, YY + 5);
	cout << char(200) << char(205) << char(188) << "  " << char(200);
	for (int i = 0; i < 3; ++i) cout << char(205);
	cout << char(188);
}

void drawW(int XX, int YY) {  // 6 * 10
	gotoXY(XX, YY);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(187) << "    ";
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(187);

	gotoXY(XX, YY + 1);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(186) << "    ";
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(186);

	gotoXY(XX, YY + 2);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(186) << " ";
	setColor(0, 0); cout << " ";
	setColor(co_theme); cout << char(187) << " ";
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(186);

	gotoXY(XX, YY + 3);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(186);
	setColor(0, 0); cout << "   ";
	setColor(co_theme); cout << char(187);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(186);

	gotoXY(XX, YY + 4);
	setColor(co_theme); cout << char(200);
	setColor(0, 0); cout << "   ";
	setColor(co_theme); cout << char(201);
	setColor(0, 0); cout << "   ";
	setColor(co_theme); cout << char(201) << char(188);

	gotoXY(XX + 1, YY + 5);
	cout << char(200) << char(205) << char(205) << char(188) << char(200) << char(205) << char(205) << char(188);
}

void drawH(int XX, int YY) {  // 6 * 8
	gotoXY(XX, YY);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(187) << "  ";
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(187);

	gotoXY(XX, YY + 1);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(186) << "  ";
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(186);

	gotoXY(XX, YY + 2);
	setColor(0, 0); cout << "       ";
	setColor(co_theme); cout << char(186);

	gotoXY(XX, YY + 3);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(201) << char(205) << char(205);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(186);

	gotoXY(XX, YY + 4);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(186) << "  ";
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(186);

	gotoXY(XX, YY + 5);
	cout << char(200) << char(205) << char(188) << "  " << char(200) << char(205) << char(188);
}

void drawP(int XX, int YY) {  // 6 * 8
	gotoXY(XX, YY );
	setColor(0, 0); cout << "      ";
	setColor(co_theme); cout << char(187);

	gotoXY(XX, YY + 1);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(201) << char(205) << char(205);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(187);

	gotoXY(XX, YY + 2);
	setColor(0, 0); cout << "      ";
	setColor(co_theme); cout << char(201) << char(188);

	gotoXY(XX, YY + 3);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(201) << char(205) << char(205) << char(205) << char(188);

	gotoXY(XX, YY + 4);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(186);

	gotoXY(XX, YY + 5);
	cout << char(200) << char(205) << char(188);
}

void drawX(int XX, int YY, int co_txt = 0) {  // 6 * 8
	gotoXY(XX, YY);
	setColor(co_txt, 0); cout << "  ";
	setColor(15, co_txt); cout << char(187) << "  ";
	setColor(co_txt, 0); cout << "  ";
	setColor(15, co_txt); cout << char(187);

	gotoXY(XX, YY + 1);
	cout << char(200);
	setColor(co_txt, 0); cout << "  ";
	setColor(15, co_txt); cout << char(187);
	setColor(co_txt, 0); cout << "  ";
	setColor(15, co_txt); cout << char(201) << char(188);

	gotoXY(XX, YY + 2);
	cout << " " << char(200);
	setColor(co_txt, 0); cout << "   ";
	setColor(15, co_txt); cout << char(201) << char(188);

	gotoXY(XX, YY + 3);
	cout << " ";
	setColor(co_txt, 0); cout << "  ";
	setColor(15, co_txt); cout << char(201);
	setColor(co_txt, 0); cout << "  ";
	setColor(15, co_txt); cout << char(187);

	gotoXY(XX, YY + 4);
	setColor(co_txt, 0); cout << "  ";
	setColor(15, co_txt); cout << char(201) << char(188) << " ";
	setColor(co_txt, 0); cout << "  ";
	setColor(15, co_txt); cout << char(187);

	gotoXY(XX, YY + 5);
	cout << char(200) << char(205) << char(188) << "  " << char(200) << char(205) << char(188);
	setColor(co_theme);
}

void drawI(int XX, int YY) {  // 6 * 3
	gotoXY(XX, YY);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(187);

	gotoXY(XX, YY + 1);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(186);

	gotoXY(XX, YY + 2);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(186);

	gotoXY(XX, YY + 3);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(186);

	gotoXY(XX, YY + 4);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(186);

	gotoXY(XX, YY + 5);
	cout << char(200) << char(205) << char(188);
}

void drawCARO(int XX, int YY) {
	drawC(XX, YY);
	drawA(XX + 8, YY);
	drawR(XX + 16, YY);
	drawO(XX + 24, YY);
}

void drawABOUT(int XX, int YY) {
	drawA(XX, YY);
	drawB(XX + 8, YY);
	drawO(XX + 16, YY);
	drawU(XX + 25, YY);
	drawT(XX + 34, YY);
}

void drawLOAD_GAME(int XX, int YY) {
	drawL(XX, YY);
	drawO(XX + 8, YY);
	drawA(XX + 17, YY);
	drawD(XX + 25, YY);
	drawG(XX + 37, YY);
	drawA(XX + 46, YY);
	drawM(XX + 54, YY);
	drawE(XX + 65, YY);
}

void drawNEW_GAME(int XX, int YY) {
	drawN(XX, YY);
	drawE(XX + 10, YY);
	drawW(XX + 18, YY);
	drawG(XX + 32, YY);
	drawA(XX + 41, YY);
	drawM(XX + 49, YY);
	drawE(XX + 60, YY);
}

void drawHELP(int XX, int YY) {
	drawH(XX, YY);
	drawE(XX + 8, YY);
	drawL(XX + 16, YY);
	drawP(XX + 24, YY);
}

void drawIN_MATCH(int XX, int YY) {
	drawI(XX, YY);
	drawN(XX + 3, YY);
	drawM(XX + 17, YY);
	drawA(XX + 28, YY);
	drawT(XX + 36, YY);
	drawC(XX + 45, YY);
	drawH(XX + 53, YY);
}

void drawX_WIN(int XX, int YY) {
	drawX(XX, YY);
	drawW(XX + 12, YY);
	drawI(XX + 22, YY);
	drawN(XX + 25, YY);
}

void drawO_WIN(int XX, int YY) {
	drawO(XX, YY);
	drawW(XX + 13, YY);
	drawI(XX + 23, YY);
	drawN(XX + 26, YY);
}

void drawDRAW(int XX, int YY) {
	drawD(XX, YY);
	drawR(XX + 8, YY);
	drawA(XX + 16, YY);
	drawW(XX + 24, YY);
}

void drawBoardMenu(int XX, int YY, int size, int b_color, string str = "") { // 3 * size, Menu Board
	setColor(co_theme);

	gotoXY(XX, YY); cout << char(201);
	for (int i = 0; i < size - 2; ++i) cout << char(205);
	cout << char(187);

	gotoXY(XX, YY + 1); cout << char(186);
	gotoXY(XX + size - 1, YY + 1); cout << char(186);

	gotoXY(XX, YY + 2); cout << char(200);
	for (int i = 0; i < size - 2; ++i) cout << char(205);
	cout << char(188);

	gotoXY(XX + 1, YY + 1);
	setColor(b_color, 0);  cout << str;
	setColor(co_theme);
}

void drawBoardSize(int XX, int YY, int h, int w) { // h * w, Board
	setColor(co_theme);

	gotoXY(XX, YY); cout << char(201);
	for (int i = 0; i < w - 2; ++i) cout << char(205);
	cout << char(187);

	for (int i = 1; i < h - 1; ++i) {
		gotoXY(XX, YY + i); cout << char(186);
		gotoXY(XX + w - 1, YY + i); cout << char(186);
	}

	gotoXY(XX, YY + h - 1); cout << char(200);
	for (int i = 0; i < w - 2; ++i) cout << char(205);
	cout << char(188);
}

void drawBoard(int Xi, int Yi, string name1, string name2, int Xscore, int Oscore, string fileName) {  // Caro Board
	setColor(co_theme);
	drawIN_MATCH(Xi - 20, Yi - 9);

	/*--------------------------- Draw Board ---------------------------------*/
	int XX = Xi - 31, YY = Yi - 2;		// [XX, YY] is located of pointer to draw board
	for (int y = 0; y <= 2 * BOARD_SIZE; ++y) {
		for (int x = 0; x <= 4 * BOARD_SIZE; ++x) {
			gotoXY(XX + x, YY + y);

			if (x == 0 && y == 0) cout << char(201);
			else if (x == 0 && y == 2 * BOARD_SIZE) cout << char(200);
			else if (x == 4 * BOARD_SIZE && y == 0) {
				cout << char(203);
				for (int i = 0; i < 20; ++i) cout << char(205);
				cout << char(187);
			} else if (x == 4 * BOARD_SIZE && y == 2 * BOARD_SIZE) {
				cout << char(202);
				for (int i = 0; i < 20; ++i) cout << char(205);
				cout << char(188);
			}

			else if (x % 4 == 0 && y == 0) cout << char(209);
			else if (x % 4 == 0 && y == 2 * BOARD_SIZE) cout << char(207);
			else if (x == 0 && y % 2 == 0) cout << char(199);
			else if (x == 4 * BOARD_SIZE && y % 2 == 0) cout << char(182);

			else if (x % 4 == 0 && y % 2 == 0) cout << char(197);
			else if (x % 4 == 0) {
				if (x == 0 || x == 4 * BOARD_SIZE) cout << char(186);
				else cout << char(179);
			} else if (y % 2 == 0) {
				if (y == 0 || y == 2 * BOARD_SIZE) cout << char(205);
				else cout << char(196);
			} else cout << " ";
		} 
		
		if (y != 0 && y != 2 * BOARD_SIZE)
			cout << "                    " << char(186);
	}

	gotoXY(XX + 4 * BOARD_SIZE, YY + BOARD_SIZE); 
	cout << char(204);
	for (int i = 0; i < 20; ++i) cout << char(205);
	cout << char(185);
	/*--------------------------------------------------------------------------*/

	/*--------------------------- Update status --------------------------------*/
	for (int y = 1; y <= BOARD_SIZE; ++y)
		for (int x = 1; x <= BOARD_SIZE; ++x) {
			status[y][x].Y = YY + (y - 1) * 2 + 1;
			status[y][x].X = XX + (x - 1) * 4 + 2;
			status[y][x].opt = 0;
		}
	/*--------------------------------------------------------------------------*/

	/*---------------------- Information in Board ------------------------------*/
	setColor(11, 0); 
	gotoXY(XX + 4 * BOARD_SIZE + 10 - ((int)name1.size() + 1) / 2 , YY + 2); cout << " " << name1 << " ";
	gotoXY(XX + 4 * BOARD_SIZE + 10 - ((int)name2.size() + 1) / 2 , YY + 17); cout << " " << name2 << " ";

	drawX(XX + 4 * BOARD_SIZE + 7, YY + 5, 8);
	drawO(XX + 4 * BOARD_SIZE + 6, YY + 20, 8);

	gotoXY(XX + 4 * BOARD_SIZE + 7, YY + 12);
	cout << "Score: " << Xscore;
	gotoXY(XX + 4 * BOARD_SIZE + 7, YY + 27);
	cout << "Score: " << Oscore;

	drawName_Board(XX + 4 * BOARD_SIZE - 2, YY + 2 * BOARD_SIZE + 1, fileName);
	drawStatus(XX, YY + 2 * BOARD_SIZE + 1, 1);
	/*--------------------------------------------------------------------------*/
}

void drawStatus(int XX, int YY, int opt) {	// Draw status in Caro Board
	gotoXY(XX - 3, YY); 
	if (opt == 1) {
		setColor(11, 0); cout << ">> Playing";
		setColor(15, 0); cout << "    | 'I'- Save  | 'U'- Undo  | 'Esc'- Exit  |  ";
		ShowCur(1);
	}

	if (opt == 2) {
		setColor(11, 0);  cout << ">> File's name:";
		setColor(15, 0);  cout << "                                           ";
		ShowCur(1);
	}

	if (opt == 3) {
		setColor(11, 0);
		cout << ">> It already exists, do you want to replace it? Press Y/N";
		ShowCur(0);
	}

	if (opt == 4) {
		setColor(11, 0);
		cout << ">> Do you want to exit? Press Y/N (Remember to save game) ";
		ShowCur(0);
	} setColor(15, 0);
}

void drawName_Board(int XX, int YY, string fileName) {	// NameBoard frame
	gotoXY(XX, YY);
	setColor(0, 15);  cout << " BOARD NAME: ";
	if ((int)fileName.size() == 0) fileName = "[NULL]";
	while ((int)fileName.size() <= 10) fileName.push_back(' ');
	cout << fileName; 
	setColor(15, 0);
}

void drawPopUp(int XX, int YY, int h, int w) {			// Pop Up Board
	setColor(co_theme);

	gotoXY(XX + 2, YY); 
		cout << char(201); 
		for (int i = 0; i < w - 6; ++i) cout << char(205); 
		cout << char(187);

	gotoXY(XX + 1, YY + 1); cout << char(201) << char(188);
	for (int i = 2; i < w - 4; ++i) cout << " ";
	cout << char(200) << char(187);

	gotoXY(XX, YY + 2); cout << char(201) << char(188);
	for (int i = 3; i < w - 1; ++i) cout << " ";
	cout << char(200) << char(187);

	for (int i = 0; i < h - 6; ++i) {
		gotoXY(XX, YY + 3 + i); cout << char(186);
		for (int j = 1; j < w - 1; ++j) cout << " ";
		cout << char(186);
	}

	gotoXY(XX, YY + h - 3); cout << char(200) << char(187);
	for (int i = 3; i < w - 1; ++i) cout << " ";
	cout << char(201) << char(188);

	gotoXY(XX + 1, YY + h - 2); cout << char(200) << char(187);
	for (int i = 2; i < w - 4; ++i) cout << " ";
	cout << char(201) << char(188);

	gotoXY(XX + 2, YY + h - 1);
		cout << char(200); 
		for (int i = 0; i < w - 6; ++i) cout << char(205);
		cout << char(188);
}
