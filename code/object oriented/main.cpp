#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <cstdlib>
#include <conio.h>
#include <Windows.h>
#include <thread>
#include <chrono>
#include <string>
#include <fstream>
using namespace std;
HANDLE  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
char a[3][3];
string s, ss;
int b, x, g, y_record, c_record, n1_record, n2_record, load = 0, gametype = 0;
class graphic {
public:
	void type(string s, int speed);
	void choose_theme();
	void center_vertical();
	void center_horizontal();
	void center_horizontal1();
	void set_theme(char t);
	void win_graph(int);
	void x_graph();
	void o_graph();
}graph1;
class Menu {
public:
	int menu();
	void choose();
	void level();
	void choose_play_type();//entekhbe bazi ba pc ya baziye 2nafare 
	void choose_multiplay();//bazi 2nafare//entekhab
	void replay();
	void replay_multiplay();//bazi 2nafare//replay
	void load_o_menu();
}menu1;
class Game {
public:
	void game(int);
	void game_multiplay(int);//bazi 2nafare//game
	void view(int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int);
	void playpc();
	void playnum1();//bazi 2nafare//nafare avval
	void playnum2();//bazi 2nafare//nafare dovvom
	void playme();
	void check(int);
	void save();
	void save_o();
	void load_o();
}game1;
struct color {
	string theme;
	int red, blue, yellow, text, select, blue_win, red_win;
}color;
void graphic::x_graph() {

	SetConsoleTextAttribute(hConsole, color.red);
	system("cls"); graph1.center_vertical();
	graph1.center_horizontal();	cout << "\t  8b        d8\n";
	graph1.center_horizontal();	cout << "\t   Y8,    ,8P \n";
	graph1.center_horizontal();	cout << "\t    `8b  d8'  \n";
	graph1.center_horizontal();	cout << "\t      Y88P    \n";
	graph1.center_horizontal();	cout << "\t      d88b    \n";
	graph1.center_horizontal();	cout << "\t    ,8P  Y8,  \n";
	graph1.center_horizontal();	cout << "\t   d8'    `8b \n";
	graph1.center_horizontal();	cout << "\t  8P        Y8\n\n\n";
}
void graphic::o_graph() {

	SetConsoleTextAttribute(hConsole, color.blue);
	system("cls"); graph1.center_vertical();
	graph1.center_horizontal();	cout << "\t   ,ad8888ba,  \n";
	graph1.center_horizontal();	cout << "\t  d8'      `8b \n";
	graph1.center_horizontal();	cout << "\t d8'        `8b\n";
	graph1.center_horizontal();	cout << "\t 88          88\n";
	graph1.center_horizontal();	cout << "\t 88          88\n";
	graph1.center_horizontal();	cout << "\t Y8,        ,8P\n";
	graph1.center_horizontal();	cout << "\t  Y8a.    .a8P \n";
	graph1.center_horizontal();	cout << "\t    YY8888YY   \n\n\n";
}
void graphic::win_graph(int a) {
	switch (a) {
	case 1:
		//you
		y_record++;
		game1.save();
		SetConsoleTextAttribute(hConsole, color.blue);
		cout << "\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t   ##    ##  #######  ##     ## \n\t\t\t\t\t    ##  ##  ##     ## ##     ## \n\t\t\t\t\t     ####   ##     ## ##     ##\n\t\t\t\t\t      ##    ##     ## ##     ##\n\t\t\t\t\t      ##    ##     ## ##     ## \n\t\t\t\t\t      ##    ##     ## ##     ## \n\t\t\t\t\t      ##     #######   #######   ";
		break;
	case 2:
		//computer
		c_record++;
		game1.save();
		SetConsoleTextAttribute(hConsole, color.red);
		cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t     ######   #######  ##     ## ########  ##     ## ######## ######## ########  \n\t\t    ##    ## ##     ## ###   ### ##     ## ##     ##    ##    ##       ##     ##  \n\t\t    ##       ##     ## #### #### ##     ## ##     ##    ##    ##       ##     ## \n\t\t    ##       ##     ## ## ### ## ########  ##     ##    ##    ######   ########  \n\t\t    ##       ##     ## ##     ## ##        ##     ##    ##    ##       ##   ##  \n\t\t    ##    ## ##     ## ##     ## ##        ##     ##    ##    ##       ##    ##\n\t\t     ######   #######  ##     ## ##         #######     ##    ######## ##     ##  ";
		break;
	case 3:
		//num 2
		n2_record++;
		game1.save();
		SetConsoleTextAttribute(hConsole, color.blue);
		cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t       #######\n\t\t\t\t\t\t      ##     ##  \n\t\t\t\t\t\t             ## \n\t\t\t\t\t\t       ####### \n\t\t\t\t\t\t      ##          \n\t\t\t\t\t\t      ##          \n\t\t\t\t\t\t      #########";
		break;
	case 4:
		//num1
		n1_record++;
		game1.save();
		SetConsoleTextAttribute(hConsole, color.red);
		cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t          ##  \n\t\t\t\t\t\t        ####  \n\t\t\t\t\t\t          ##     \n\t\t\t\t\t\t          ##     \n\t\t\t\t\t\t          ##     \n\t\t\t\t\t\t          ##     \n\t\t\t\t\t\t        ###### ";
		break;
	default:
		break;
	}
	SetConsoleTextAttribute(hConsole, color.yellow);
	cout << "\n\n\n\n\n\n\n\t\t\t\t\t      ##      ## #### ##    ##\n\t\t\t\t\t      ##  ##  ##  ##  ###   ##\n\t\t\t\t\t      ##  ##  ##  ##  ####  ##\n\t\t\t\t\t      ##  ##  ##  ##  ## ## ##\n\t\t\t\t\t      ##  ##  ##  ##  ##  ####\n\t\t\t\t\t      ##  ##  ##  ##  ##   ###\n\t\t\t\t\t       ###  ###  #### ##    ##";
}
void graphic::set_theme(char t) {
	if (t == 'b') {
		color.theme = "color 0f";
		color.red = 12;
		color.blue = 9;
		color.yellow = 14;
		color.text = 15;
		color.select = 159;
		color.blue_win = 159;
		color.red_win = 207;
	}
	else if (t == 'w')
	{
		color.theme = "color f0";
		color.red = 252;
		color.blue = 249;
		color.yellow = 250;
		color.text = 240;
		color.select = 224;
	}
}
void graphic::center_vertical() {
	cout << "\n\n\n\n\n\n\n\n\n\n\n";
};
void graphic::center_horizontal() {
	cout << "\t\t\t\t\t";
}
void graphic::center_horizontal1() {
	cout << "\t\t\t\t\t      ";
}
void graphic::type(string s, int speed) {
	for (const auto c : s) {
		cout << c << flush;
		this_thread::sleep_for(chrono::milliseconds(speed));
	}
}
void graphic::choose_theme() {

	system((color.theme).c_str());
	system("cls");
	graph1.center_vertical();
	cout << "\n\n\n\n\n";
	graph1.center_horizontal(); cout << "         choose a number :\n";
	graph1.center_horizontal(); cout << "_________________________________\n\n\n";
	graph1.center_horizontal(); cout << "             1-Black\n\n";
	graph1.center_horizontal(); cout << "             2-White\n\n";
	graph1.center_horizontal(); cout << "_________________________________\n";

	while (1) {
		char f = getche();
		if (f == '1') {
			graph1.set_theme('b');
			break;
		}
		else if (f == '2') {
			graph1.set_theme('w');
			break;
		}

		else {
			graph1.center_vertical();
			graph1.center_horizontal();
			SetConsoleTextAttribute(hConsole, color.yellow);
			cout << "\t     ";
			s = "Error!";
			graph1.type(s, 120);
		}
		choose_theme();
	}
	menu1.menu();
}
int Menu::menu() {
	string line;
	system("cls");
	system((color.theme).c_str());
	int f;
	SetConsoleTextAttribute(hConsole, color.text);
	graph1.center_vertical();
	cout << "\n\n\n\n\n";
	graph1.center_horizontal(); cout << "        choose a number :\n";
	graph1.center_horizontal(); cout << "_________________________________\n\n";
	graph1.center_horizontal(); cout << "          1-start new game\n\n";
	graph1.center_horizontal(); cout << "          2-continue game\n\n";
	graph1.center_horizontal(); cout << "          3-change theme\n\n";
	graph1.center_horizontal(); cout << "          4-leader board\n\n";
	graph1.center_horizontal(); cout << "          5-exit\n";
	graph1.center_horizontal(); cout << "_________________________________\n";

	while (1) {
		f = getche();
		if (f == '1') {
			system("cls");
			system((color.theme).c_str());
			graph1.center_vertical();
			cout << "\n\n\n\n\n";
			graph1.center_horizontal(); cout << "        choose a number :\n";
			graph1.center_horizontal(); cout << "_________________________________\n\n";
			graph1.center_horizontal(); cout << "          ";
			SetConsoleTextAttribute(hConsole, color.select);
			cout << "1-start new game\n\n";
			SetConsoleTextAttribute(hConsole, color.text);
			graph1.center_horizontal(); cout << "          2-continue game\n\n";
			graph1.center_horizontal(); cout << "          3-change theme\n\n";
			graph1.center_horizontal(); cout << "          4-leader board\n\n";
			graph1.center_horizontal(); cout << "          5-exit\n";
			graph1.center_horizontal(); cout << "_________________________________\n";
			this_thread::sleep_for(chrono::milliseconds(500));
			choose_play_type();
			break;
		}
		else if (f == '2') {
			system("cls");
			cout << "\n\n\n\n\n";
			system((color.theme).c_str());
			graph1.center_vertical();
			graph1.center_horizontal(); cout << "        choose a number :\n";
			graph1.center_horizontal(); cout << "_________________________________\n\n";
			graph1.center_horizontal(); cout << "          1-start new game\n\n";
			graph1.center_horizontal(); cout << "          ";
			SetConsoleTextAttribute(hConsole, color.select);
			cout << "2-continue game\n\n";
			SetConsoleTextAttribute(hConsole, color.text);
			graph1.center_horizontal(); cout << "          3-change theme\n\n";
			graph1.center_horizontal(); cout << "          4-leader board\n\n";
			graph1.center_horizontal(); cout << "          5-exit\n";
			graph1.center_horizontal(); cout << "_________________________________\n";
			this_thread::sleep_for(chrono::milliseconds(500));
			menu1.load_o_menu();
			break;
		}
		else if (f == '3') {
			system("cls");
			cout << "\n\n\n\n\n";
			system((color.theme).c_str());
			graph1.center_vertical();
			graph1.center_horizontal(); cout << "        choose a number :\n";
			graph1.center_horizontal(); cout << "_________________________________\n\n";
			graph1.center_horizontal(); cout << "          1-start new game\n\n";
			graph1.center_horizontal(); cout << "          2-continue game\n\n";
			graph1.center_horizontal(); cout << "          ";
			SetConsoleTextAttribute(hConsole, color.select);
			cout << "3-change theme\n\n";
			SetConsoleTextAttribute(hConsole, color.text);
			graph1.center_horizontal(); cout << "          4-leader board\n\n";
			graph1.center_horizontal(); cout << "          5-exit\n";
			graph1.center_horizontal(); cout << "_________________________________\n";
			this_thread::sleep_for(chrono::milliseconds(500));
			graph1.choose_theme();
			break;
		}
		else if (f == '4') {
			system("cls");
			cout << "\n\n\n\n\n";
			system((color.theme).c_str());
			graph1.center_vertical();
			graph1.center_horizontal(); cout << "        choose a number :\n";
			graph1.center_horizontal(); cout << "_________________________________\n\n";
			graph1.center_horizontal(); cout << "          1-start new game\n\n";
			graph1.center_horizontal(); cout << "          2-continue game\n\n";
			graph1.center_horizontal(); cout << "          3-change theme\n\n";
			graph1.center_horizontal(); cout << "          ";
			SetConsoleTextAttribute(hConsole, color.select);
			cout << "4-leader board\n\n";
			SetConsoleTextAttribute(hConsole, color.text);
			graph1.center_horizontal(); cout << "          5-exit\n";
			graph1.center_horizontal(); cout << "_________________________________\n";
			this_thread::sleep_for(chrono::milliseconds(500));
			system("cls");
			graph1.center_vertical();
			cout << "\n\n\n\n\n\n";
			graph1.center_horizontal();
			cout << "  ";
			cout << "num\tname\t      record\n";
			graph1.center_horizontal();
			cout << "  ";
			cout << "___________________________\n";
			ifstream show("records.txt");
			if (!show) {
				cerr << "Could not open file!";
				exit(EXIT_FAILURE);
			}
			if (show.is_open())
			{
				while (getline(show, line))
				{
					cout << "\n";
					graph1.center_horizontal();
					cout << "  ";
					cout << line << '\n';

				}
				show.close();
			}

			getchar();
		}
		else if (f == '5') {
			exit(0);
			break;
		}

		else {
			graph1.center_vertical();
			graph1.center_horizontal();
			SetConsoleTextAttribute(hConsole, color.yellow);
			cout << "\t     ";
			s = "Error!";
			graph1.type(s, 120);
		}
		menu1.menu();
	}
	return 0;
}
void Menu::level() {
	int gs;
	system("cls");
	cout << "\n\n\n\n\n\n\n";
	graph1.center_vertical();
	graph1.center_horizontal();
	cout << "     ";
	cout << "choose your level : \n";
	graph1.center_horizontal();
	cout << "____________________________\n\n";
	graph1.center_horizontal();
	cout << "    1-easy        2-hard\n\n\t\t\t\t\t\t     ";
	while (1) {
		gs = getche();
		if (gs == '1') {
			g = 1;
			menu1.choose();
			break;
		}
		else if (gs == '2') {
			g = 2;
			menu1.choose();
			break;
		}
		else {
			graph1.center_vertical();
			graph1.center_horizontal();
			SetConsoleTextAttribute(hConsole, color.yellow);
			cout << "\t   ";
			ss = "Error!";
			graph1.type(ss, 120);
			SetConsoleTextAttribute(hConsole, color.text);
		}
		menu1.level();
	}
}
void Menu::choose_play_type() {
	system((color.theme).c_str());
	SetConsoleTextAttribute(hConsole, color.text);
	system("cls");
	int f;
	graph1.center_vertical();
	cout << "\n\n\n\n\n";
	graph1.center_horizontal(); cout << "        choose a number :\n";
	graph1.center_horizontal(); cout << "_________________________________\n\n";
	graph1.center_horizontal(); cout << "         1 - singleplay\n\n";
	graph1.center_horizontal(); cout << "         2 - multiplay\n";
	graph1.center_horizontal(); cout << "_________________________________\n\n";
	graph1.center_horizontal(); cout << "     enter your selection : ";
	while (1) {
		f = getche();
		if (f == '1') {
			menu1.level();
			menu1.choose();
			break;
		}
		else if (f == '2') {
			menu1.choose_multiplay();
			break;
		}
		else {
			graph1.center_vertical();
			graph1.center_horizontal();
			SetConsoleTextAttribute(hConsole, color.yellow);
			cout << "\t     ";
			s = "Error!";
			graph1.type(s, 120);
		}
		menu1.choose_play_type();
	}
}
void Menu::choose_multiplay() {
	system((color.theme).c_str());
	a[0][0] = '1'; a[0][1] = '2'; a[0][2] = '3';
	a[1][0] = '4'; a[1][1] = '5'; a[1][2] = '6';
	a[2][0] = '7'; a[2][1] = '8'; a[2][2] = '9';
	if (load == 2)
		game1.load_o();
	system("cls");
	srand(time(0));
	int x = rand();
	x = ((x) % 2);
	cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t\t  random start : ";
	if (x == 1) {
		graph1.x_graph();
		SetConsoleTextAttribute(hConsole, color.text);
	}
	else
	{
		graph1.o_graph();
		SetConsoleTextAttribute(hConsole, color.text);
	}
	graph1.center_horizontal();	cout << "\t    is first\n";
	cout << "\n\t\t\t\t\t_________________________________\n\n\t\t\t\t\t     num1 :";
	SetConsoleTextAttribute(hConsole, color.red);
	cout << " x      ";
	SetConsoleTextAttribute(hConsole, color.text);
	cout << "num2: ";
	SetConsoleTextAttribute(hConsole, color.blue);
	cout << "o";
	SetConsoleTextAttribute(hConsole, color.text);
	cout << "\n\t\t\t\t\t_________________________________";
	cout << "\n\n\t\t\t\t\t     press any key to start\n";
	getche();
	game1.game_multiplay(x);
}
void Menu::choose() {
	system((color.theme).c_str());
	a[0][0] = '1'; a[0][1] = '2'; a[0][2] = '3';
	a[1][0] = '4'; a[1][1] = '5'; a[1][2] = '6';
	a[2][0] = '7'; a[2][1] = '8'; a[2][2] = '9';
	if (load == 1)
		game1.load_o();
	system("cls");
	srand(time(0));
	int x = rand();
	x = ((x) % 2);
	cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t\t  random start : ";
	if (x == 1) {
		graph1.x_graph();
		SetConsoleTextAttribute(hConsole, color.text);
	}
	else
	{
		graph1.o_graph();
		SetConsoleTextAttribute(hConsole, color.text);
	}
	graph1.center_horizontal();	cout << "\t    is first\n";
	cout << "\n\t\t\t\t\t_________________________________\n\n\t\t\t\t\t     Computer :";
	SetConsoleTextAttribute(hConsole, color.red);
	cout << " x      ";
	SetConsoleTextAttribute(hConsole, color.text);
	cout << "You: ";
	SetConsoleTextAttribute(hConsole, color.blue);
	cout << "o";
	SetConsoleTextAttribute(hConsole, color.text);
	cout << "\n\t\t\t\t\t_________________________________";
	cout << "\n\n\t\t\t\t\t     press any key to start\n";
	getche();
	game1.game(x);
}
void Menu::replay_multiplay() {

	SetConsoleTextAttribute(hConsole, color.text);
	system("cls");
	int f;
	graph1.center_vertical();
	cout << "\n\n\n\n\n\n\n\n";
	cout << "\t\t\t\t       "; cprintf("  _________________________________\n");
	cout << "\t\t\t\t       "; cprintf(" |                                 |\n");
	cout << "\t\t\t\t       ";    s = " | Do You want to play again?(Y/N) |\n"; graph1.type(s, 80);
	cout << "\t\t\t\t       "; cprintf(" |_________________________________|\n\n\t\t\t\t\t\t\t ");
	f = getche();

	if (f == 'y' || f == 'Y')
	{
		system("cls");
		a[0][0] = '1'; a[0][1] = '2'; a[0][2] = '3';
		a[1][0] = '4'; a[1][1] = '5'; a[1][2] = '6';
		a[2][0] = '7'; a[2][1] = '8'; a[2][2] = '9';
		graph1.center_vertical(); printf("\n\n\n\n\n\n\t\t\t\t\t _________________________________\n\t\t\t\t\t|\t\t\t\t  |\n\t\t\t\t\t|\t  Who goes first?\t  |\n\t\t\t\t\t|_________________________________|\n\t\t\t\t\t    |\t\t\t      |\n\t\t\t\t\t    |  press 1 to start num1  |\n\t\t\t\t\t    |\t\t\t      |\n\t\t\t\t\t    |  press 2 to start num2  |\n\t\t\t\t\t    |\t\t\t      |\n\t\t\t\t\t    | press 3 to start random |\n\t\t\t\t\t    |_________________________|\n\n\t\t\t\t\t\t        ");
		f = getche();
		if (f == '1')
			game1.game_multiplay(1);
		else if (f == '2')
			game1.game_multiplay(0);
		else if (f == '3') {
			b = rand();
			b = ((b) % 2);
			game1.game_multiplay(b);
		}
		else {
			SetConsoleTextAttribute(hConsole, 12);
			cprintf("\n\n\n\n\n\n\n\n\t\t\t\t\t _______________________________\n\t\t\t\t\t|\t\t\t\t|\n\t\t\t\t\t|try again (press 1 or 2 or 3) !|\n\t\t\t\t\t|_______________________________|\n\t\t\t\t");
			getche();
			replay_multiplay();
		}
	}

	if (f == 'n' || f == 'N')
		menu1.menu();

	else {
		SetConsoleTextAttribute(hConsole, color.red);
		cprintf("\n\n\n\n\n\n\n\t\t\t\t\t    __________________________\n\t\t\t\t\t   |\t\t\t      |\n\t\t\t\t\t   |try again!( press Y or N )|\n\t\t\t\t\t   |__________________________|\n\t\t\t\t");
		getche();
		replay_multiplay();
	}
}
void Menu::replay() {

	SetConsoleTextAttribute(hConsole, color.text);
	system("cls");
	int f;
	graph1.center_vertical();
	cout << "\n\n\n\n\n\n\n\n";
	cout << "\t\t\t\t       "; cprintf("  _________________________________\n");
	cout << "\t\t\t\t       "; cprintf(" |                                 |\n");
	cout << "\t\t\t\t       ";    s = " | Do You want to play again?(Y/N) |\n"; graph1.type(s, 80);
	cout << "\t\t\t\t       "; cprintf(" |_________________________________|\n\n\t\t\t\t\t\t\t ");
	f = getche();

	if (f == 'y' || f == 'Y')
	{
		system("cls");
		a[0][0] = '1'; a[0][1] = '2'; a[0][2] = '3';
		a[1][0] = '4'; a[1][1] = '5'; a[1][2] = '6';
		a[2][0] = '7'; a[2][1] = '8'; a[2][2] = '9';
		while (1) {
			graph1.center_vertical(); printf("\n\n\n\n\n\n\t\t\t\t\t _________________________________\n\t\t\t\t\t|\t\t\t\t  |\n\t\t\t\t\t|\t  Who goes first?\t  |\n\t\t\t\t\t|_________________________________|\n\t\t\t\t\t    |\t\t\t      |\n\t\t\t\t\t    |press 1 to start computer|\n\t\t\t\t\t    |\t\t\t      |\n\t\t\t\t\t    |  press 2 to start you   |\n\t\t\t\t\t    |\t\t\t      |\n\t\t\t\t\t    | press 3 to start random |\n\t\t\t\t\t    |_________________________|\n\n\t\t\t\t\t\t        ");
			f = getche();
			if (f == '1') {
				game1.game(1);
				break;
			}
			else if (f == '2') {
				game1.game(0);
				break;
			}
			else if (f == '3') {
				b = rand();
				b = ((b) % 2);
				game1.game(b);
				break;
			}

			else {
				system("cls");
				graph1.center_vertical(); printf("\n\n\n\n\n\n\t\t\t\t\t _________________________________\n\t\t\t\t\t|\t\t\t\t  |\n\t\t\t\t\t|\t  Who goes first?\t  |\n\t\t\t\t\t|_________________________________|\n\t\t\t\t\t    |\t\t\t      |\n\t\t\t\t\t    |press 1 to start computer|\n\t\t\t\t\t    |\t\t\t      |\n\t\t\t\t\t    |  press 2 to start you   |\n\t\t\t\t\t    |\t\t\t      |\n\t\t\t\t\t    | press 3 to start random |\n\t\t\t\t\t    |_________________________|\n\n\t\t\t\t\t\t        ");
				SetConsoleTextAttribute(hConsole, color.red);
				cprintf("\n\n\n\n\n\n\n\n\t\t\t\t\t _______________________________\n\t\t\t\t\t|\t\t\t\t|\n\t\t\t\t\t|try again (press 1 or 2 or 3) !|\n\t\t\t\t\t|_______________________________|\n\t\t\t\t");
				SetConsoleTextAttribute(hConsole, color.text);
				getche();
			}
			system("cls");
		}
	}

	if (f == 'n' || f == 'N')
		menu1.menu();

	else {
		SetConsoleTextAttribute(hConsole, color.red);
		cprintf("\n\n\n\n\n\n\n\t\t\t\t\t    __________________________\n\t\t\t\t\t   |\t\t\t      |\n\t\t\t\t\t   |try again!( press Y or N )|\n\t\t\t\t\t   |__________________________|\n\t\t\t\t");
		getch();
		menu1.replay();
	}
}
void Menu::load_o_menu() {
	system("cls");
	system((color.theme).c_str());
	int f;
	SetConsoleTextAttribute(hConsole, color.text);
	graph1.center_vertical();
	cout << "\n\n\n\n\n";
	graph1.center_horizontal(); cout << "        choose a number :\n";
	graph1.center_horizontal(); cout << "_________________________________\n\n";
	graph1.center_horizontal(); cout << "          1-load singleplay\n\n";
	graph1.center_horizontal(); cout << "          2-load multiplay\n\n";
	graph1.center_horizontal(); cout << "_________________________________\n";
	while (1) {
		f = getch();
		if (f == '1') {
			gametype = 1;
			graph1.center_horizontal();
			cout << "\t     ";
			game1.load_o();
			game1.game(b);
		}
		if (f == '2') {
			gametype = 2;
			graph1.center_horizontal();
			cout << "\t     ";
			game1.load_o();
			game1.game_multiplay(b);
		}
		else {
			graph1.center_vertical();
			graph1.center_horizontal();
			SetConsoleTextAttribute(hConsole, color.yellow);
			cout << "\t     ";
			s = "Error!";
			graph1.type(s, 120);
		}
		load_o_menu();
	}


}
void Game::game_multiplay(int b) {
	gametype = 2;
	game1.save_o();
	game1.view(color.blue, color.red, color.blue, color.red, color.blue, color.red, color.blue, color.red, color.blue, color.red, color.blue, color.red, color.blue, color.red, color.blue, color.red, color.blue, color.red);
	game1.check(2);
	if (b == 1) {
		SetConsoleTextAttribute(hConsole, color.red);
		cout << "\n\n\n\n\t\t\t\t\t\t\t" << "red";
		SetConsoleTextAttribute(hConsole, color.text);
		game1.playnum1();
		game1.game_multiplay(0);
		gametype = 2;
		game1.save_o();
	}
	else if (b == 0) {
		SetConsoleTextAttribute(hConsole, color.blue);
		cout << "\n\n\n\n\t\t\t\t\t\t\t" << "blue";
		SetConsoleTextAttribute(hConsole, color.text);
		game1.playnum2();
		game1.game_multiplay(1);
		gametype = 2;
		game1.save_o();
	}
}
void Game::game(int b) {
	gametype = 1;
	game1.save_o();
	game1.view(color.blue, color.red, color.blue, color.red, color.blue, color.red, color.blue, color.red, color.blue, color.red, color.blue, color.red, color.blue, color.red, color.blue, color.red, color.blue, color.red);
	game1.check(1);
	if (b == 1) {
		SetConsoleTextAttribute(hConsole, color.red);
		cout << "\n\n\n\n\t\t\t\t\t\t\t" << "red";
		SetConsoleTextAttribute(hConsole, color.text);
		gametype = 1;
		game1.save_o();
		game1.playpc();
		game1.game(0);
	}
	else if (b == 0) {
		SetConsoleTextAttribute(hConsole, color.blue);
		cout << "\n\n\n\n\t\t\t\t\t\t\t" << "blue";
		SetConsoleTextAttribute(hConsole, color.text);
		gametype = 1;
		game1.save_o();
		game1.playme();
		game1.game(1);
	}
}
void Game::view(int b1, int r1, int b2, int r2, int b3, int r3, int b4, int r4, int b5, int r5, int b6, int r6, int b7, int r7, int b8, int r8, int b9, int r9) {

	system("cls");
	printf("\n\n");
	/*if (x==1)cout<<"blue";
	if (x==0)cout<<"red";*/
	system((color.theme).c_str());
	graph1.center_vertical(); graph1.center_horizontal1();
	//1---------------------------------------------------------------------------
	//1-line0
	if (a[0][0] == 'O') {
		SetConsoleTextAttribute(hConsole, b1);
	}
	else if (a[0][0] == 'X') {
		SetConsoleTextAttribute(hConsole, r1);
	}
	cprintf("       ");
	SetConsoleTextAttribute(hConsole, color.text);
	cprintf("|");

	if (a[0][1] == 'O') {
		SetConsoleTextAttribute(hConsole, b2);
	}
	else if (a[0][1] == 'X') {
		SetConsoleTextAttribute(hConsole, r2);
	}
	cprintf("       ");
	SetConsoleTextAttribute(hConsole, color.text);
	cprintf("|");

	if (a[0][2] == 'O') {
		SetConsoleTextAttribute(hConsole, b3);
	}
	else if (a[0][2] == 'X') {
		SetConsoleTextAttribute(hConsole, r3);
	}
	cprintf("       ");
	SetConsoleTextAttribute(hConsole, color.text);
	cprintf("\r\n");
	graph1.center_horizontal1();
	//1-line1
	if (a[0][0] == 'O') {
		SetConsoleTextAttribute(hConsole, b1);
	}
	else if (a[0][0] == 'X') {
		SetConsoleTextAttribute(hConsole, r1);
	}
	cprintf("       ");
	SetConsoleTextAttribute(hConsole, color.text);
	cprintf("|");

	if (a[0][1] == 'O') {
		SetConsoleTextAttribute(hConsole, b2);
	}
	else if (a[0][1] == 'X') {
		SetConsoleTextAttribute(hConsole, r2);
	}
	cprintf("       ");
	SetConsoleTextAttribute(hConsole, color.text);
	cprintf("|");

	if (a[0][2] == 'O') {
		SetConsoleTextAttribute(hConsole, b3);
	}
	else if (a[0][2] == 'X') {
		SetConsoleTextAttribute(hConsole, r3);
	}
	cprintf("       ");
	SetConsoleTextAttribute(hConsole, color.text);
	cprintf("\r\n");
	graph1.center_horizontal1();
	//1-line2
	if (a[0][0] == 'O') {
		SetConsoleTextAttribute(hConsole, b1);
	}
	else if (a[0][0] == 'X') {
		SetConsoleTextAttribute(hConsole, r1);
	}
	cprintf("   %c   ", a[0][0]);
	SetConsoleTextAttribute(hConsole, color.text);
	cprintf("|");
	if (a[0][1] == 'O') {
		SetConsoleTextAttribute(hConsole, b2);
	}
	else if (a[0][1] == 'X') {
		SetConsoleTextAttribute(hConsole, r2);
	}
	cprintf("   %c   ", a[0][1]);
	SetConsoleTextAttribute(hConsole, color.text);
	cprintf("|");
	if (a[0][2] == 'O') {
		SetConsoleTextAttribute(hConsole, b3);
	}
	else if (a[0][2] == 'X') {
		SetConsoleTextAttribute(hConsole, r3);
	}
	cprintf("   %c   \r\n", a[0][2]);
	SetConsoleTextAttribute(hConsole, color.text);
	graph1.center_horizontal1();
	//1-line3
	if (a[0][0] == 'O') {
		SetConsoleTextAttribute(hConsole, b1);
	}
	else if (a[0][0] == 'X') {
		SetConsoleTextAttribute(hConsole, r1);
	}
	cprintf("       ");
	SetConsoleTextAttribute(hConsole, color.text);
	cprintf("|");
	if (a[0][1] == 'O') {
		SetConsoleTextAttribute(hConsole, b2);
	}
	else if (a[0][1] == 'X') {
		SetConsoleTextAttribute(hConsole, r2);
	}
	cprintf("       ");
	SetConsoleTextAttribute(hConsole, color.text);
	cprintf("|");
	if (a[0][2] == 'O') {
		SetConsoleTextAttribute(hConsole, b3);
	}
	else if (a[0][2] == 'X') {
		SetConsoleTextAttribute(hConsole, r3);
	}
	cprintf("       ");
	SetConsoleTextAttribute(hConsole, color.text);
	cprintf("\r\n");
	graph1.center_horizontal1();
	//1-line4
	if (a[0][0] == 'O') {
		SetConsoleTextAttribute(hConsole, b1);
		if (b1 == color.blue) {
			SetConsoleTextAttribute(hConsole, color.text);
		}
	}
	else if (a[0][0] == 'X') {
		SetConsoleTextAttribute(hConsole, r1);
		if (r1 == color.red) {
			SetConsoleTextAttribute(hConsole, color.text);
		}
	}
	cprintf("_______");
	SetConsoleTextAttribute(hConsole, color.text);
	cprintf("|");

	if (a[0][1] == 'O') {
		SetConsoleTextAttribute(hConsole, b2);
		if (b2 == color.blue) {
			SetConsoleTextAttribute(hConsole, color.text);
		}
	}
	else if (a[0][1] == 'X') {
		SetConsoleTextAttribute(hConsole, r2);
		if (r2 == color.red) {
			SetConsoleTextAttribute(hConsole, color.text);
		}
	}
	cprintf("_______");
	SetConsoleTextAttribute(hConsole, color.text);
	cprintf("|");

	if (a[0][2] == 'O') {
		SetConsoleTextAttribute(hConsole, b3);
		if (b3 == color.blue) {
			SetConsoleTextAttribute(hConsole, color.text);
		}
	}
	else if (a[0][2] == 'X') {
		SetConsoleTextAttribute(hConsole, r3);
		if (r3 == color.red) {
			SetConsoleTextAttribute(hConsole, color.text);
		}
	}
	cprintf("_______");
	SetConsoleTextAttribute(hConsole, color.text);
	cprintf("\r\n");
	graph1.center_horizontal1();
	//2------------------------------------------------------------------------------------
	//2-line1
	if (a[1][0] == 'O') {
		SetConsoleTextAttribute(hConsole, b4);
	}
	else if (a[1][0] == 'X') {
		SetConsoleTextAttribute(hConsole, r4);
	}
	cprintf("       ");
	SetConsoleTextAttribute(hConsole, color.text);
	cprintf("|");

	if (a[1][1] == 'O') {
		SetConsoleTextAttribute(hConsole, b5);
	}
	else if (a[1][1] == 'X') {
		SetConsoleTextAttribute(hConsole, r5);
	}
	cprintf("       ");
	SetConsoleTextAttribute(hConsole, color.text);
	cprintf("|");

	if (a[1][2] == 'O') {
		SetConsoleTextAttribute(hConsole, b6);
	}
	else if (a[1][2] == 'X') {
		SetConsoleTextAttribute(hConsole, r6);
	}
	cprintf("       ");
	SetConsoleTextAttribute(hConsole, color.text);
	cprintf("\r\n");
	graph1.center_horizontal1();
	//2-line2
	if (a[1][0] == 'O') {
		SetConsoleTextAttribute(hConsole, b4);
	}
	else if (a[1][0] == 'X') {
		SetConsoleTextAttribute(hConsole, r4);
	}
	cprintf("       ");
	SetConsoleTextAttribute(hConsole, color.text);
	cprintf("|");

	if (a[1][1] == 'O') {
		SetConsoleTextAttribute(hConsole, b5);
	}
	else if (a[1][1] == 'X') {
		SetConsoleTextAttribute(hConsole, r5);
	}
	cprintf("       ");
	SetConsoleTextAttribute(hConsole, color.text);
	cprintf("|");

	if (a[1][2] == 'O') {
		SetConsoleTextAttribute(hConsole, b6);
	}
	else if (a[1][2] == 'X') {
		SetConsoleTextAttribute(hConsole, r6);
	}
	cprintf("       ");
	SetConsoleTextAttribute(hConsole, color.text);
	cprintf("\r\n");
	//2-line3
	graph1.center_horizontal1();
	if (a[1][0] == 'O') {
		SetConsoleTextAttribute(hConsole, b4);
	}
	else if (a[1][0] == 'X') {
		SetConsoleTextAttribute(hConsole, r4);
	}
	cprintf("   %c   ", a[1][0]);
	SetConsoleTextAttribute(hConsole, color.text);
	cprintf("|");

	if (a[1][1] == 'O') {
		SetConsoleTextAttribute(hConsole, b5);
	}
	else if (a[1][1] == 'X') {
		SetConsoleTextAttribute(hConsole, r5);
	}
	cprintf("   %c   ", a[1][1]);
	SetConsoleTextAttribute(hConsole, color.text);
	cprintf("|");
	if (a[1][2] == 'O') {
		SetConsoleTextAttribute(hConsole, b6);
	}
	else if (a[1][2] == 'X') {
		SetConsoleTextAttribute(hConsole, r6);
	}
	cprintf("   %c   ", a[1][2]);
	SetConsoleTextAttribute(hConsole, color.text);
	cprintf("\r\n");
	graph1.center_horizontal1();
	//2-line4
	if (a[1][0] == 'O') {
		SetConsoleTextAttribute(hConsole, b4);
	}
	else if (a[1][0] == 'X') {
		SetConsoleTextAttribute(hConsole, r4);
	}
	cprintf("       ");
	SetConsoleTextAttribute(hConsole, color.text);
	cprintf("|");

	if (a[1][1] == 'O') {
		SetConsoleTextAttribute(hConsole, b5);
	}
	else if (a[1][1] == 'X') {
		SetConsoleTextAttribute(hConsole, r5);
	}
	cprintf("       ");
	SetConsoleTextAttribute(hConsole, color.text);
	cprintf("|");
	if (a[1][2] == 'O') {
		SetConsoleTextAttribute(hConsole, b6);
	}
	else if (a[1][2] == 'X') {
		SetConsoleTextAttribute(hConsole, r6);
	}
	cprintf("       ");
	SetConsoleTextAttribute(hConsole, color.text);
	cprintf("\r\n");
	graph1.center_horizontal1();
	//2-line5
	if (a[1][0] == 'O') {
		SetConsoleTextAttribute(hConsole, b4);
		if (b4 == color.blue) {
			SetConsoleTextAttribute(hConsole, color.text);
		}
	}
	else if (a[1][0] == 'X') {
		SetConsoleTextAttribute(hConsole, r4);
		if (r4 == color.red) {
			SetConsoleTextAttribute(hConsole, color.text);
		}
	}
	cprintf("_______");
	SetConsoleTextAttribute(hConsole, color.text);
	cprintf("|");

	if (a[1][1] == 'O') {
		SetConsoleTextAttribute(hConsole, b5);
		if (b5 == color.blue) {
			SetConsoleTextAttribute(hConsole, color.text);
		}
	}
	else if (a[1][1] == 'X') {
		SetConsoleTextAttribute(hConsole, r5);
		if (r5 == color.red) {
			SetConsoleTextAttribute(hConsole, color.text);
		}
	}
	cprintf("_______");
	SetConsoleTextAttribute(hConsole, color.text);
	cprintf("|");
	if (a[1][2] == 'O') {
		SetConsoleTextAttribute(hConsole, b6);
		if (b6 == color.blue) {
			SetConsoleTextAttribute(hConsole, color.text);
		}
	}
	else if (a[1][2] == 'X') {
		SetConsoleTextAttribute(hConsole, r6);
		if (r6 == color.red) {
			SetConsoleTextAttribute(hConsole, color.text);
		}
	}
	cprintf("_______");
	SetConsoleTextAttribute(hConsole, color.text);
	cprintf("\r\n");
	//3----------------------------------------------------------------------------------
	//3-line1
	graph1.center_horizontal1();
	if (a[2][0] == 'O') {
		SetConsoleTextAttribute(hConsole, b7);
	}
	else if (a[2][0] == 'X') {
		SetConsoleTextAttribute(hConsole, r7);
	}
	cprintf("       ");
	SetConsoleTextAttribute(hConsole, color.text);
	cprintf("|");
	if (a[2][1] == 'O') {
		SetConsoleTextAttribute(hConsole, b8);
	}
	else if (a[2][1] == 'X') {
		SetConsoleTextAttribute(hConsole, r8);
	}
	cprintf("       ");
	SetConsoleTextAttribute(hConsole, color.text);
	cprintf("|");
	if (a[2][2] == 'O') {
		SetConsoleTextAttribute(hConsole, b9);
	}
	else if (a[2][2] == 'X') {
		SetConsoleTextAttribute(hConsole, r9);
	}
	cprintf("       ");
	SetConsoleTextAttribute(hConsole, color.text);
	cprintf("\r\n");
	graph1.center_horizontal1();
	//3-line2
	if (a[2][0] == 'O') {
		SetConsoleTextAttribute(hConsole, b7);
	}
	else if (a[2][0] == 'X') {
		SetConsoleTextAttribute(hConsole, r7);
	}
	cprintf("       ");
	SetConsoleTextAttribute(hConsole, color.text);
	cprintf("|");
	if (a[2][1] == 'O') {
		SetConsoleTextAttribute(hConsole, b8);
	}
	else if (a[2][1] == 'X') {
		SetConsoleTextAttribute(hConsole, r8);
	}
	cprintf("       ");
	SetConsoleTextAttribute(hConsole, color.text);
	cprintf("|");
	if (a[2][2] == 'O') {
		SetConsoleTextAttribute(hConsole, b9);
	}
	else if (a[2][2] == 'X') {
		SetConsoleTextAttribute(hConsole, r9);
	}
	cprintf("       ");
	SetConsoleTextAttribute(hConsole, color.text);
	cprintf("\r\n");
	graph1.center_horizontal1();
	//3-line3
	if (a[2][0] == 'O') {
		SetConsoleTextAttribute(hConsole, b7);
	}
	else if (a[2][0] == 'X') {
		SetConsoleTextAttribute(hConsole, r7);
	}
	cprintf("   %c   ", a[2][0]);
	SetConsoleTextAttribute(hConsole, color.text);
	cprintf("|");
	if (a[2][1] == 'O') {
		SetConsoleTextAttribute(hConsole, b8);
	}
	else if (a[2][1] == 'X') {
		SetConsoleTextAttribute(hConsole, r8);
	}
	cprintf("   %c   ", a[2][1]);
	SetConsoleTextAttribute(hConsole, color.text);
	cprintf("|");
	if (a[2][2] == 'O') {
		SetConsoleTextAttribute(hConsole, b9);
	}
	else if (a[2][2] == 'X') {
		SetConsoleTextAttribute(hConsole, r9);
	}
	cprintf("   %c   ", a[2][2]);
	SetConsoleTextAttribute(hConsole, color.text);
	cprintf("\r\n");
	graph1.center_horizontal1();
	//3-line4
	if (a[2][0] == 'O') {
		SetConsoleTextAttribute(hConsole, b7);
	}
	else if (a[2][0] == 'X') {
		SetConsoleTextAttribute(hConsole, r7);
	}
	cprintf("       ");
	SetConsoleTextAttribute(hConsole, color.text);
	cprintf("|");
	if (a[2][1] == 'O') {
		SetConsoleTextAttribute(hConsole, b8);
	}
	else if (a[2][1] == 'X') {
		SetConsoleTextAttribute(hConsole, r8);
	}
	cprintf("       ");
	SetConsoleTextAttribute(hConsole, color.text);
	cprintf("|");
	if (a[2][2] == 'O') {
		SetConsoleTextAttribute(hConsole, b9);
	}
	else if (a[2][2] == 'X') {
		SetConsoleTextAttribute(hConsole, r9);
	}
	cprintf("       ");
	SetConsoleTextAttribute(hConsole, color.text);
	cprintf("\r\n");
	graph1.center_horizontal1();

	//3-line5
	if (a[2][0] == 'O') {
		SetConsoleTextAttribute(hConsole, b7);
	}
	else if (a[2][0] == 'X') {
		SetConsoleTextAttribute(hConsole, r7);
	}
	cprintf("       ");
	SetConsoleTextAttribute(hConsole, color.text);
	cprintf("|");
	if (a[2][1] == 'O') {
		SetConsoleTextAttribute(hConsole, b8);
	}
	else if (a[2][1] == 'X') {
		SetConsoleTextAttribute(hConsole, r8);
	}
	cprintf("       ");
	SetConsoleTextAttribute(hConsole, color.text);
	cprintf("|");
	if (a[2][2] == 'O') {
		SetConsoleTextAttribute(hConsole, b9);
	}
	else if (a[2][2] == 'X') {
		SetConsoleTextAttribute(hConsole, r9);
	}
	cprintf("       ");
	SetConsoleTextAttribute(hConsole, color.text);
	cprintf("\r\n");
	graph1.center_horizontal1();

}
void Game::playpc() {
	//win 1 !!
	if (a[0][0] == 'X' && a[0][1] == 'X' && a[0][2] == '3' && (g == 1 || g == 2))
		a[0][2] = 'X';
	else if (a[0][0] == 'X' && a[0][2] == 'X' && a[0][1] == '2' && (g == 1 || g == 2))
		a[0][1] = 'X';
	else if (a[0][0] == 'X' && a[1][0] == 'X' && a[2][0] == '7' && (g == 1 || g == 2))
		a[2][0] = 'X';
	else if (a[0][0] == 'X' && a[2][0] == 'X' && a[1][0] == '4' && (g == 1 || g == 2))
		a[1][0] = 'X';
	else if (a[0][0] == 'X' && a[1][1] == 'X' && a[2][2] == '9' && (g == 1 || g == 2))
		a[2][2] = 'X';



	else if (a[0][2] == 'X' && a[0][1] == 'X' && a[0][0] == '1' && (g == 1 || g == 2))
		a[0][0] = 'X';
	else if (a[0][2] == 'X' && a[1][1] == 'X' && a[2][0] == '7' && (g == 1 || g == 2))
		a[2][0] = 'X';
	else if (a[0][2] == 'X' && a[1][2] == 'X' && a[2][2] == '9' && (g == 1 || g == 2))
		a[2][2] = 'X';
	else if (a[0][2] == 'X' && a[2][2] == 'X' && a[1][2] == '6' && (g == 1 || g == 2))
		a[1][2] = 'X';



	else if (a[2][0] == 'X' && a[1][0] == 'X'&& a[0][0] == '1' && (g == 1 || g == 2))
		a[0][0] = 'X';
	else if (a[2][0] == 'X' && a[2][1] == 'X' && a[2][2] == '9' && (g == 1 || g == 2))
		a[2][2] = 'X';
	else if (a[2][0] == 'X' && a[2][2] == 'X' && a[2][1] == '8' && (g == 1 || g == 2))
		a[2][1] = 'X';
	else if (a[2][0] == 'X' && a[1][1] == 'X' && a[0][2] == '3' && (g == 1 || g == 2))
		a[0][2] = 'X';



	else if (a[2][2] == 'X' &&  a[1][2] == 'X'&& a[0][2] == '3' && (g == 1 || g == 2))
		a[0][2] = 'X';
	else if (a[2][2] == 'X' && a[2][1] == 'X' && a[2][0] == '7' && (g == 1 || g == 2))
		a[2][0] = 'X';
	else if (a[2][2] == 'X' && a[1][1] == 'X' && a[0][0] == '1' && (g == 1 || g == 2))
		a[0][0] = 'X';

	//win 2 !!

	else if (a[1][2] == 'X' && a[1][1] == 'X' && a[1][0] == '4' && (g == 1 || g == 2))
		a[1][0] = 'X';

	else if (a[1][0] == 'X' && a[1][1] == 'X' && a[1][2] == '6' && (g == 1 || g == 2))
		a[1][2] = 'X';

	else if (a[0][1] == 'X' && a[1][1] == 'X' && a[2][1] == '8' && (g == 1 || g == 2))
		a[2][1] = 'X';

	else if (a[2][1] == 'X' && a[1][1] == 'X' && a[0][1] == '2' && (g == 1 || g == 2))
		a[0][1] = 'X';

	else if (a[1][1] == '5'&&g == 2)
		a[1][1] = 'X';
	//anti lose
	else if (((a[0][1] == 'O' && a[0][2] == 'O' && a[0][0] == '1') || (a[2][2] == 'O' && a[1][1] == 'O' && a[0][0] == '1') || (a[1][0] == 'O' && a[2][0] == 'O' && a[0][0] == '1')) && (g == 2))
		a[0][0] = 'X';

	else if (((a[0][0] == 'O' && a[0][2] == 'O' && a[0][1] == '2') || (a[1][1] == 'O' && a[2][1] == 'O' && a[0][1] == '2')) && (g == 2))
		a[0][1] = 'X';

	else if (((a[1][2] == 'O' && a[2][2] == 'O' && a[0][2] == '3') || (a[2][0] == 'O' && a[1][1] == 'O' && a[0][2] == '3') || (a[0][0] == 'O' && a[0][1] == 'O' && a[0][2] == '3')) && (g == 2))
		a[0][2] = 'X';

	else if (((a[0][0] == 'O' && a[2][0] == 'O' && a[1][0] == '4') || (a[1][2] == 'O' && a[1][1] == 'O' && a[1][0] == '4')) && (g == 2))
		a[1][0] = 'X';

	else if (((a[1][1] == 'O' && a[1][0] == 'O' && a[1][2] == '6') || (a[0][2] == 'O' && a[2][2] == 'O' && a[1][2] == '6')) && (g == 2))
		a[1][2] = 'X';

	else if (((a[0][0] == 'O' && a[1][0] == 'O' && a[2][0] == '7') || (a[0][2] == 'O' && a[1][1] == 'O' && a[2][0] == '7') || (a[2][2] == 'O' && a[2][1] == 'O' && a[2][0] == '7')) && (g == 2))
		a[2][0] = 'X';

	else if (((a[0][1] == 'O' && a[1][1] == 'O' && a[2][1] == '8') || (a[2][2] == 'O' && a[2][0] == 'O' && a[2][1] == '8')) && (g == 2))
		a[2][1] = 'X';

	else if (((a[0][0] == 'O' && a[1][1] == 'O' && a[2][2] == '9') || (a[0][2] == 'O' && a[1][2] == 'O' && a[2][2] == '9') || (a[0][0] == 'O' && a[2][1] == 'O' && a[2][2] == '9')) && (g == 2))
		a[2][2] = 'X';
	else if (a[2][2] == '9' && a[0][0] == '1' && (g == 1 || g == 2))
		a[2][2] = 'X';
	else if (a[2][0] == '7' && a[0][2] == '3' && (g == 1 || g == 2))
		a[2][0] = 'X';

	//better 2
	else if (a[1][0] == '4' && a[1][2] == '6' && (g == 1 || g == 2))
		a[1][0] = 'X';
	else if (a[0][1] == '2' && a[2][1] == '8' && (g == 1 || g == 2))
		a[0][1] = 'X';

	//normal 1
	else if (a[2][2] == '9' && (g == 1 || g == 2))
		a[2][2] = 'X';
	else if (a[0][0] == '1' && (g == 1 || g == 2))
		a[0][0] = 'X';
	else if (a[0][2] == '3' && (g == 1 || g == 2))
		a[0][2] = 'X';
	else if (a[2][0] == '7' && (g == 1 || g == 2))
		a[2][0] = 'X';

	//normal 2
	else if (a[0][1] == '2' && (g == 1 || g == 2))
		a[0][1] = 'X';
	else if (a[1][2] == '6' && (g == 1 || g == 2))
		a[1][2] = 'X';
	else if (a[2][1] == '8' && (g == 1 || g == 2))
		a[2][1] = 'X';
	else if (a[1][0] == '4' && (g == 1 || g == 2))
		a[1][0] = 'X';
}
void Game::playnum1() {
	char e;
	cout << "\n\n\n\t\t\t\t\t\t\t ";
	e = getche();

	//vared kardane shomare
	if (e == '1' && a[0][0] != 'X' && a[0][0] != 'O')
		a[0][0] = 'X';

	else if (e == '2' && a[0][1] != 'X' && a[0][1] != 'O')
		a[0][1] = 'X';

	else if (e == '3' && a[0][2] != 'X' && a[0][2] != 'O')
		a[0][2] = 'X';

	else if (e == '4' && a[1][0] != 'X' && a[1][0] != 'O')
		a[1][0] = 'X';

	else if (e == '5' && a[1][1] != 'X' && a[1][1] != 'O')
		a[1][1] = 'X';

	else if (e == '6' && a[1][2] != 'X' && a[1][2] != 'O')
		a[1][2] = 'X';

	else if (e == '7' && a[2][0] != 'X' && a[2][0] != 'O')
		a[2][0] = 'X';

	else if (e == '8' && a[2][1] != 'X' && a[2][1] != 'O')
		a[2][1] = 'X';

	else if (e == '9' && a[2][2] != 'X' && a[2][2] != 'O')
		a[2][2] = 'X';
	else
	{
		printf("\n\n\n\n\t\t\t\t\t\t2 bare talash konid\n\t\t\t\t\tpress any key and keep on the game");   getche(); game1.game_multiplay(1);
	}
}
void Game::playnum2() {
	char e;
	cout << "\n\n\n\t\t\t\t\t\t\t ";
	e = getche();

	//vared kardane shomare
	if (e == '1' && a[0][0] != 'X' && a[0][0] != 'O') {

		a[0][0] = 'O';
	}

	else if (e == '2' && a[0][1] != 'X' && a[0][1] != 'O') {

		a[0][1] = 'O';
	}


	else if (e == '3' && a[0][2] != 'X' && a[0][2] != 'O') {

		a[0][2] = 'O';
	}


	else if (e == '4' && a[1][0] != 'X' && a[1][0] != 'O') {

		a[1][0] = 'O';
	}


	else if (e == '5' && a[1][1] != 'X' && a[1][1] != 'O') {

		a[1][1] = 'O';
	}


	else if (e == '6' && a[1][2] != 'X' && a[1][2] != 'O') {

		a[1][2] = 'O';
	}


	else if (e == '7' && a[2][0] != 'X' && a[2][0] != 'O') {

		a[2][0] = 'O';
	}


	else if (e == '8' && a[2][1] != 'X' && a[2][1] != 'O') {

		a[2][1] = 'O';
	}


	else if (e == '9' && a[2][2] != 'X' && a[2][2] != 'O') {

		a[2][2] = 'O';
	}
	else
	{
		printf("\n\n\n\n\t\t\t\t\t\t2 bare talash konid\n\t\t\t\t\tpress any key and keep on the game");   getche(); game1.game_multiplay(0);
	}
}
void Game::playme() {
	char e;
	cout << "\n\n\n\t\t\t\t\t\t\t ";

	e = getche();

	//vared kardane shomare
	if (e == '1' && a[0][0] != 'O' && a[0][0] != 'X')
		a[0][0] = 'O';

	else if (e == '2' && a[0][1] != 'O' && a[0][1] != 'X')
		a[0][1] = 'O';

	else if (e == '3' && a[0][2] != 'O' && a[0][2] != 'X')
		a[0][2] = 'O';

	else if (e == '4' && a[1][0] != 'O' && a[1][0] != 'X')
		a[1][0] = 'O';

	else if (e == '5' && a[1][1] != 'O' && a[1][1] != 'X')
		a[1][1] = 'O';

	else if (e == '6' && a[1][2] != 'O' && a[1][2] != 'X')
		a[1][2] = 'O';

	else if (e == '7' && a[2][0] != 'O' && a[2][0] != 'X')
		a[2][0] = 'O';

	else if (e == '8' && a[2][1] != 'O' && a[2][1] != 'X')
		a[2][1] = 'O';

	else if (e == '9' && a[2][2] != 'O' && a[2][2] != 'X')
		a[2][2] = 'O';
	else
	{
		printf("\n\n\n\n\t\t\t\t\t\t2 bare talash konid\n\t\t\t\t\tpress any key and keep on the game");   getche(); game1.game(0);
	}
}
void Game::check(int k) {

	int i;
	//o

	// You & num 2 <horizontall>  
	for (i = 0; i<3; i++)
	{
		if (a[i][0] == 'O' && a[i][1] == 'O' && a[i][2] == 'O')
		{
			system("cls");
			if (i == 0)
				game1.view(color.blue_win, color.red, color.blue_win, color.red, color.blue_win, color.red, color.blue, color.red, color.blue, color.red, color.blue, color.red, color.blue, color.red, color.blue, color.red, color.blue, color.red);
			if (i == 1)
				game1.view(color.blue, color.red, color.blue, color.red, color.blue, color.red, color.blue_win, color.red, color.blue_win, color.red, color.blue_win, color.red, color.blue, color.red, color.blue, color.red, color.blue, color.red);
			if (i == 2)
				game1.view(color.blue, color.red, color.blue, color.red, color.blue, color.red, color.blue, color.red, color.blue, color.red, color.blue, color.red, color.blue_win, color.red, color.blue_win, color.red, color.blue_win, color.red);
			this_thread::sleep_for(chrono::milliseconds(1500));
			system("cls");
			if (k == 1) {
				graph1.win_graph(1);
				this_thread::sleep_for(chrono::milliseconds(1500));   menu1.replay();
			}
			if (k == 2) {
				graph1.win_graph(3);
				this_thread::sleep_for(chrono::milliseconds(1500));	menu1.replay_multiplay();
			}
		}
	}
	// You & num 2 <vertical> 
	for (i = 0; i < 3; i++)
	{
		if (a[0][i] == 'O' && a[1][i] == 'O' && a[2][i] == 'O')
		{
			system("cls");
			if (i == 0)
				game1.view(color.blue_win, color.red, color.blue, color.red, color.blue, color.red, color.blue_win, color.red, color.blue, color.red, color.blue, color.red, color.blue_win, color.red, color.blue, color.red, color.blue, color.red);
			if (i == 1)
				game1.view(color.blue, color.red, color.blue_win, color.red, color.blue, color.red, color.blue, color.red, color.blue_win, color.red, color.blue, color.red, color.blue, color.red, color.blue_win, color.red, color.blue, color.red);
			if (i == 2)
				game1.view(color.blue, color.red, color.blue, color.red, color.blue_win, color.red, color.blue, color.red, color.blue, color.red, color.blue_win, color.red, color.blue, color.red, color.blue, color.red, color.blue_win, color.red);
			this_thread::sleep_for(chrono::milliseconds(1500));
			system("cls");
			if (k == 1) {
				graph1.win_graph(1);
				this_thread::sleep_for(chrono::milliseconds(1500));   menu1.replay();
			}
			if (k == 2) {
				graph1.win_graph(3);
				this_thread::sleep_for(chrono::milliseconds(1500));	menu1.replay_multiplay();
			}
		}
	}
	// You & num 2 <inclined> 
	if ((a[0][0] == 'O' && a[1][1] == 'O' && a[2][2] == 'O') || (a[0][2] == 'O' && a[1][1] == 'O' && a[2][0] == 'O')) {
		system("cls");
		if (a[0][0] == 'O' && a[1][1] == 'O' && a[2][2] == 'O')
			game1.view(color.blue_win, color.red, color.blue, color.red, color.blue, color.red, color.blue, color.red, color.blue_win, color.red, color.blue, color.red, color.blue, color.red, color.blue, color.red, color.blue_win, color.red);
		if (a[0][2] == 'O' && a[1][1] == 'O' && a[2][0] == 'O')
			game1.view(color.blue, color.red, color.blue, color.red, color.blue_win, color.red, color.blue, color.red, color.blue_win, color.red, color.blue, color.red, color.blue_win, color.red, color.blue, color.red, color.blue, color.red);
		this_thread::sleep_for(chrono::milliseconds(1500));
		system("cls");
		if (k == 1) {
			graph1.win_graph(1);
			this_thread::sleep_for(chrono::milliseconds(1500));   menu1.replay();
		}
		if (k == 2) {
			graph1.win_graph(3);
			this_thread::sleep_for(chrono::milliseconds(1500));	menu1.replay_multiplay();
		}
	}

	//x
	// Computer & num 1 horizontall
	for (i = 0; i < 3; i++)
	{
		if (a[i][0] == 'X' && a[i][1] == 'X' && a[i][2] == 'X') {
			system("cls");
			if (i == 0) //line 1
				game1.view(color.blue, color.red_win, color.blue, color.red_win, color.blue, color.red_win, color.blue, color.red, color.blue, color.red, color.blue, color.red, color.blue, color.red, color.blue, color.red, color.blue, color.red);
			if (i == 1) //line 2
				game1.view(color.blue, color.red, color.blue, color.red, color.blue, color.red, color.blue, color.red_win, color.blue, color.red_win, color.blue, color.red_win, color.blue, color.red, color.blue, color.red, color.blue, color.red);
			if (i == 2) //line 3
				game1.view(color.blue, color.red, color.blue, color.red, color.blue, color.red, color.blue, color.red, color.blue, color.red, color.blue, color.red, color.blue, color.red_win, color.blue, color.red_win, color.blue, color.red_win);
			this_thread::sleep_for(chrono::milliseconds(1500));
			system("cls");
			if (k == 1) {
				graph1.win_graph(2);
				this_thread::sleep_for(chrono::milliseconds(1500));
				menu1.replay();
			}
			if (k == 2) {
				graph1.win_graph(4);
				this_thread::sleep_for(chrono::milliseconds(1500));
				menu1.replay_multiplay();
			}
		}
	}
	// Computer & num 1 vertical 
	for (i = 0; i<3; i++)
	{
		if (a[0][i] == 'X' && a[1][i] == 'X' && a[2][i] == 'X') {
			system("cls");
			if (i == 0)
				game1.view(color.blue, color.red_win, color.blue, color.red, color.blue, color.red, color.blue, color.red_win, color.blue, color.red, color.blue, color.red, color.blue, color.red_win, color.blue, color.red, color.blue, color.red);
			if (i == 1)
				game1.view(color.blue, color.red, color.blue, color.red_win, color.blue, color.red, color.blue, color.red, color.blue, color.red_win, color.blue, color.red, color.blue, color.red, color.blue, color.red_win, color.blue, color.red);
			if (i == 2)
				game1.view(color.blue, color.red, color.blue, color.red, color.blue, color.red_win, color.blue, color.red, color.blue, color.red, color.blue, color.red_win, color.blue, color.red, color.blue, color.red, color.blue, color.red_win);
			this_thread::sleep_for(chrono::milliseconds(1500));
			system("cls");
			if (k == 1) {
				graph1.win_graph(2);
				this_thread::sleep_for(chrono::milliseconds(1500));
				menu1.replay();
			}
			if (k == 2) {
				graph1.win_graph(4);
				this_thread::sleep_for(chrono::milliseconds(1500));
				menu1.replay_multiplay();
			}
		}
	}
	// Computer & num 1 inclined 
	if ((a[0][2] == 'X' && a[1][1] == 'X' && a[2][0] == 'X') || (a[0][0] == 'X' && a[1][1] == 'X' && a[2][2] == 'X')) {
		if (a[0][0] == 'X' && a[1][1] == 'X' && a[2][2] == 'X')
			game1.view(color.blue, color.red_win, color.blue, color.red, color.blue, color.red, color.blue, color.red, color.blue, color.red_win, color.blue, color.red, color.blue, color.red, color.blue, color.red, color.blue, color.red_win);
		if (a[0][2] == 'X' && a[1][1] == 'X' && a[2][0] == 'X')
			game1.view(color.blue, color.red, color.blue, color.red, color.blue, color.red_win, color.blue, color.red, color.blue, color.red_win, color.blue, color.red, color.blue, color.red_win, color.blue, color.red, color.blue, color.red);
		this_thread::sleep_for(chrono::milliseconds(1500));
		system("cls");
		if (k == 1) {
			graph1.win_graph(2);
			this_thread::sleep_for(chrono::milliseconds(1500));
			menu1.replay();
		}
		if (k == 2) {
			graph1.win_graph(4);
			this_thread::sleep_for(chrono::milliseconds(1500));
			menu1.replay_multiplay();
		}
	}

	//draw
	else {
		if (a[0][0] != '1' && a[0][1] != '2' && a[0][2] != '3' && a[1][0] != '4' && a[1][1] != '5' && a[1][2] != '6' && a[2][0] != '7' && a[2][1] != '8' && a[2][2] != '9')
		{
			this_thread::sleep_for(chrono::milliseconds(1500));
			system("cls");
			graph1.center_vertical(); cout << "\n\n\n\n\n\n\n\t\t\t\t     ########  ########     ###    ##      ##\n\t\t\t\t     ##     ## ##     ##   ## ##   ##  ##  ##  \n\t\t\t\t     ##     ## ##     ##  ##   ##  ##  ##  ##  \n\t\t\t\t     ##     ## ########  ##     ## ##  ##  ##  \n\t\t\t\t     ##     ## ##   ##   ######### ##  ##  ##  \n\t\t\t\t     ##     ## ##    ##  ##     ## ##  ##  ##  \n\t\t\t\t     ########  ##     ## ##     ##  ###  ###  ";
			this_thread::sleep_for(chrono::milliseconds(1500));
			if (k == 1) {
				menu1.replay();
			}
			if (k == 2) {
				menu1.replay_multiplay();
			}
		}
	}
}
void Game::save() {
	fstream log("records.txt", ios::out);
	fstream computer("computer.txt", ios::out);
	fstream you("you.txt", ios::out);
	fstream num1("n1.txt", ios::out);
	fstream num2("n2.txt", ios::out);
	if (!log || !computer || !you || !num1 || !num2) {
		cerr << "Could not open file!";
		exit(EXIT_FAILURE);
	}
	if (y_record >= c_record && y_record >= n2_record && y_record >= n1_record) {
		log << "1" << "\t" << "You" << "\t" << "\t" << y_record << endl;
		if (c_record >= n2_record && c_record >= n1_record) {
			log << "2" << "\t" << "Computer" << "\t" << c_record << endl;
			if (n2_record >= n1_record) {
				log << "3" << "\t" << "Num 2" << "\t" << "\t" << n2_record << endl;
				log << "4" << "\t" << "Num 1" << "\t" << "\t" << n1_record << endl;
			}
			else if (n1_record >= n2_record) {
				log << "3" << "\t" << "Num 1" << "\t" << "\t" << n1_record << endl;
				log << "4" << "\t" << "Num 2" << "\t" << "\t" << n2_record << endl;
			}

		}
		else if (n2_record >= c_record && n2_record >= n1_record) {
			log << "2" << "\t" << "Num 2" << "\t" << "\t" << n2_record << endl;
			if (c_record >= n1_record) {
				log << "3" << "\t" << "Computer" << "\t" << c_record << endl;
				log << "4" << "\t" << "Num 1" << "\t" << "\t" << n1_record << endl;
			}
			else if (n1_record >= c_record) {
				log << "3" << "\t" << "Num 1" << "\t" << "\t" << n1_record << endl;
				log << "4" << "\t" << "Computer" << "\t" << c_record << endl;
			}
		}
		else if (n1_record >= c_record && n1_record >= n2_record) {
			log << "2" << "\t" << "Num 1" << "\t" << "\t" << n1_record << endl;
			if (c_record >= n2_record) {
				log << "3" << "\t" << "Computer" << "\t" << c_record << endl;
				log << "4" << "\t" << "Num 2" << "\t" << "\t" << n2_record << endl;
			}
			else if (n2_record >= c_record) {
				log << "3" << "\t" << "Num 2" << "\t" << "\t" << n2_record << endl;
				log << "4" << "\t" << "Computer" << "\t" << c_record << endl;
			}
		}
	}
	else if (c_record >= y_record && c_record >= n2_record && c_record >= n1_record) {
		log << "1" << "\t" << "Computer" << "\t" << c_record << endl;
		if (y_record >= n2_record && y_record >= n1_record) {
			log << "2" << "\t" << "You" << "\t" << "\t" << y_record << endl;
			if (n2_record >= n1_record) {
				log << "3" << "\t" << "Num 2" << "\t" << "\t" << n2_record << endl;
				log << "4" << "\t" << "Num 1" << "\t" << "\t" << n1_record << endl;
			}
			else if (n1_record >= n2_record) {
				log << "3" << "\t" << "Num 1" << "\t" << "\t" << n1_record << endl;
				log << "4" << "\t" << "Num 2" << "\t" << "\t" << n2_record << endl;
			}

		}
		else if (n2_record >= y_record && n2_record >= n1_record) {
			log << "2" << "\t" << "Num 2" << "\t" << "\t" << n2_record << endl;
			if (y_record >= n1_record) {
				log << "3" << "\t" << "You" << "\t" << "\t" << y_record << endl;
				log << "4" << "\t" << "Num 1" << "\t" << "\t" << n1_record << endl;
			}
			else if (n1_record >= y_record) {
				log << "3" << "\t" << "Num 1" << "\t" << "\t" << n1_record << endl;
				log << "4" << "\t" << "You" << "\t" << "\t" << y_record << endl;
			}
		}
		else if (n1_record >= y_record && n1_record >= n2_record) {
			log << "2" << "\t" << "Num 1" << "\t" << "\t" << n1_record << endl;
			if (y_record >= n2_record) {
				log << "3" << "\t" << "You" << "\t" << "\t" << y_record << endl;
				log << "4" << "\t" << "Num 2" << "\t" << "\t" << n2_record << endl;
			}
			else if (n2_record >= y_record) {
				log << "3" << "\t" << "Num 2" << "\t" << "\t" << n2_record << endl;
				log << "4" << "\t" << "You" << "\t" << "\t" << y_record << endl;
			}
		}
	}
	else if (n1_record >= c_record && n1_record >= n2_record && n1_record >= y_record) {
		log << "1" << "\t" << "Num 1" << "\t" << "\t" << n1_record << endl;
		if (c_record >= n2_record && c_record >= y_record) {
			log << "2" << "\t" << "Computer" << "\t" << c_record << endl;
			if (n2_record >= y_record) {
				log << "3" << "\t" << "Num 2" << "\t" << "\t" << n2_record << endl;
				log << "4" << "\t" << "You" << "\t" << "\t" << y_record << endl;
			}
			else if (y_record >= n2_record) {
				log << "3" << "\t" << "You" << "\t" << "\t" << y_record << endl;
				log << "4" << "\t" << "Num 2" << "\t" << "\t" << n2_record << endl;
			}

		}
		else if (n2_record >= c_record && n2_record >= y_record) {
			log << "2" << "\t" << "Num 2" << "\t" << "\t" << n2_record << endl;
			if (c_record >= y_record) {
				log << "3" << "\t" << "Computer" << "\t" << c_record << endl;
				log << "4" << "\t" << "You" << "\t" << "\t" << y_record << endl;
			}
			else if (y_record >= c_record) {
				log << "3" << "\t" << "You" << "\t" << "\t" << y_record << endl;
				log << "4" << "\t" << "Computer" << "\t" << c_record << endl;
			}
		}
		else if (y_record >= c_record && y_record >= n2_record) {
			log << "2" << "\t" << "You" << "\t" << "\t" << y_record << endl;
			if (c_record >= n2_record) {
				log << "3" << "\t" << "Computer" << "\t" << c_record << endl;
				log << "4" << "\t" << "Num 2" << "\t" << "\t" << n2_record << endl;
			}
			else if (n2_record >= c_record) {
				log << "3" << "\t" << "Num 2" << "\t" << "\t" << n2_record << endl;
				log << "4" << "\t" << "Computer" << "\t" << c_record << endl;
			}
		}
	}
	else if (n2_record >= c_record && n2_record >= y_record  && n2_record >= n1_record) {
		log << "1" << "\t" << "Num 2" << "\t" << "\t" << n2_record << endl;
		if (c_record >= y_record && c_record >= n1_record) {
			log << "2" << "\t" << "Computer" << "\t" << c_record << endl;
			if (y_record >= n1_record) {
				log << "3" << "\t" << "You" << "\t" << "\t" << y_record << endl;
				log << "4" << "\t" << "Num 1" << "\t" << "\t" << n1_record << endl;
			}
			else if (n1_record >= y_record) {
				log << "3" << "\t" << "Num 1" << "\t" << "\t" << n1_record << endl;
				log << "4" << "\t" << "You" << "\t" << "\t" << y_record << endl;
			}

		}
		else if (y_record >= c_record && y_record >= n1_record) {
			log << "2" << "\t" << "You" << "\t" << "\t" << y_record << endl;
			if (c_record >= n1_record) {
				log << "3" << "\t" << "Computer" << "\t" << c_record << endl;
				log << "4" << "\t" << "Num 1" << "\t" << "\t" << n1_record << endl;
			}
			else if (n1_record >= c_record) {
				log << "3" << "\t" << "Num 1" << "\t" << "\t" << n1_record << endl;
				log << "4" << "\t" << "Computer" << "\t" << c_record << endl;
			}
		}
		else if (n1_record >= c_record && n1_record >= y_record) {
			log << "2" << "\t" << "Num 1" << "\t" << "\t" << n1_record << endl;
			if (c_record >= y_record) {
				log << "3" << "\t" << "Computer" << "\t" << c_record << endl;
				log << "4" << "\t" << "You" << "\t" << "\t" << y_record << endl;
			}
			else if (y_record >= c_record) {
				log << "3" << "\t" << "You" << "\t" << "\t" << y_record << endl;
				log << "4" << "\t" << "Computer" << "\t" << c_record << endl;
			}
		}
	}
	computer << c_record;
	you << y_record;
	num1 << n1_record;
	num2 << n2_record;
}
void Game::save_o() {
	int i, j;
	if (gametype == 1) {
		ofstream snap("save_o1.txt");
		for (i = 0;i<9;i++)
			for (j = 0;j<9;j++)
				snap << a[i][j];
	}
	if (gametype == 2) {
		ofstream snap("save_o2.txt");
		for (i = 0;i<9;i++)
			for (j = 0;j<9;j++)
				snap << a[i][j];
	}
	ofstream snapb("save_ob.txt");
	snapb << b;
}
void Game::load_o() {
	int i, j;
	if (gametype == 1) {
		fstream snap("save_o1.txt", ios::in);
		for (i = 0;i<9;i++)
			for (j = 0;j < 9;j++)
				snap >> a[i][j];
		fstream snapb("save_ob.txt", ios::in);
		snapb >> b;
	}
	else if (gametype == 2) {
		fstream snap("save_o2.txt", ios::in);
		for (i = 0;i<9;i++)
			for (j = 0;j < 9;j++) {
				snap >> a[i][j];
			}
		fstream snapb("save_ob.txt", ios::in);
		snapb >> b;
	}
}
int main() {
	a[0][0] = '1'; a[0][1] = '2'; a[0][2] = '3';
	a[1][0] = '4'; a[1][1] = '5'; a[1][2] = '6';
	a[2][0] = '7'; a[2][1] = '8'; a[2][2] = '9';
	ifstream computer1("computer.txt");
	ifstream you1("you.txt");
	ifstream num11("n1.txt");
	ifstream num21("n2.txt");
	computer1 >> c_record;
	you1 >> y_record;
	num11 >> n1_record;
	num21 >> n2_record;
	int i, b = 4, c = 1;
	graph1.set_theme('b');
	system("mode con lines=45 cols=115");
	system((color.theme).c_str());
	cout << "\n\n\n\n\n\n\n\n\n  ";
	graph1.center_vertical();
	graph1.center_horizontal();
	cout << "            ";
	s = "WellCome!";
	graph1.type(s, 150);
	system("cls");
	for (i = 0; i<6; i++) {
		graph1.center_vertical();
		cout << "\n\n";
		SetConsoleTextAttribute(hConsole, b);
		graph1.center_horizontal();	cout << "\t  8b        d8\n";
		graph1.center_horizontal();	cout << "\t   Y8,    ,8P \n";
		graph1.center_horizontal();	cout << "\t    `8b  d8'  \n";
		graph1.center_horizontal();	cout << "\t      Y88P    \n";
		graph1.center_horizontal();	cout << "\t      d88b    \n";
		graph1.center_horizontal();	cout << "\t    ,8P  Y8,  \n";
		graph1.center_horizontal();	cout << "\t   d8'    `8b \n";
		graph1.center_horizontal();	cout << "\t  8P        Y8\n\n\n";
		SetConsoleTextAttribute(hConsole, c);
		graph1.center_horizontal();	cout << "\t   ,ad8888ba,  \n";
		graph1.center_horizontal();	cout << "\t  d8'      `8b \n";
		graph1.center_horizontal();	cout << "\t d8'        `8b\n";
		graph1.center_horizontal();	cout << "\t 88          88\n";
		graph1.center_horizontal();	cout << "\t 88          88\n";
		graph1.center_horizontal();	cout << "\t Y8,        ,8P\n";
		graph1.center_horizontal();	cout << "\t  Y8a.    .a8P \n";
		graph1.center_horizontal();	cout << "\t    YY8888YY   \n\n\n";
		this_thread::sleep_for(chrono::milliseconds(500));
		if (b == 4 && c == 1) {
			b = color.red;
			c = color.blue;
		}
		else if (b == color.red&&c == color.blue) {
			b = 4;
			c = 1;
		}
		system("cls");
	}
	menu1.menu();
	return 0;
}