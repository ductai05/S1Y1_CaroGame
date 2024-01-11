#include "Console.h"

void fixConsoleWindow(int WIDTH, int HEIGHT) {		// Fix console screen
	system("COLOR f0");
	HWND consoleWindow = GetConsoleWindow();

	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	SetWindowLong(consoleWindow, GWL_STYLE, style);

	SMALL_RECT r;
	r.Top = r.Left = 0;
	r.Right = WIDTH;
	r.Bottom = HEIGHT;

	COORD NewSize;
	NewSize.X = WIDTH;
	NewSize.Y = HEIGHT;

	HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleWindowInfo(Handle, TRUE, &r);
	SetConsoleScreenBufferSize(Handle, NewSize);
	ShowScrollBar(consoleWindow, SB_BOTH, 0);
}

void gotoXY(int x, int y) {		// Move pointer to (y, x)
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void setColor(int background_color, int text_color) { // Setcolor of pointer
	HANDLE hconsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int color_code = background_color * 16 + text_color;
	SetConsoleTextAttribute(hconsole, color_code);
}

/*---------------@- Function Draw Picture in "Pixel-art" -@------------------*/
void draw_square(int i, int j, int x, int y, int color) {
	x = (x - 1) * 2 + 1;
	gotoXY(x + i, y + j);
	setColor(color, color);
	cout << "  ";
	setColor(15, 15);
}

void decorate_draw(int x, int y, const string& nameFile) {
	ifstream file(nameFile.c_str());
	string s;
	int i = 0;
	while (getline(file, s))
	{
		i++;
		stringstream ss(s);
		int j = 0;
		while (!ss.eof())
		{
			j++;
			int color;
			ss >> color;
			draw_square(x, y, j, i, color);
		}
	}
}
/*---------------------------------------------------------------------------*/

void ShowCur(bool CursorVisibility) {  // CursorVisibility = 0 is hide, = 1 is appear
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor = { 1, CursorVisibility };
	SetConsoleCursorInfo(handle, &cursor);
}

void curr_coordinate(int& x, int& y)	// Get the locate of pointer
{
	CONSOLE_SCREEN_BUFFER_INFO curr;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curr);
	x = curr.dwCursorPosition.X;
	y = curr.dwCursorPosition.Y;
}

int nextMove() {   // Get operation from keyboard
	while (true) {
		if (_kbhit()) {
			char c = _getch();

			if (c == 13 || c == ' ') return 0;	// Enter
			if (c == 27) return 5;				// Exit

			if (c == -32) {						// Arrow
				c = _getch();

				if (c == 72) return 1;			// Up
				if (c == 75) return 2;			// Left
				if (c == 80) return 3;			// Down
				if (c == 77) return 4;			// Right
			}

			if (c == 'W' || c == 'w') return 1;	// Up
			if (c == 'A' || c == 'a') return 2;	// Left
			if (c == 'S' || c == 's') return 3;	// Down
			if (c == 'D' || c == 'd') return 4;	// Right

			if (c == 'U' || c == 'u') return 6;	// Undo
			if (c == 'I' || c == 'i') return 7;	// Save
		}
	}
}