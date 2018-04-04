#include "main.h"

using namespace std;

bool gameover = false;
/* char player = 'x'; */
bool player = true;
int turns = 0;

char grid[9][9];

int X=0, Y=0;

int main(){

	char ans='y';
	newGame();
	while(ans!='N'&&ans!='n'){
		play();
		cout << "Nowa Gra? (Y/n): ";
		/* ans = getchar(); */
		cin >> ans;
		if(ans=='y'||ans=='Y'){
			newGame();
		}
	}
	return 0;
}

void play(){

	while(!gameover){
		system("clear||cls");

		printGrid();
		char in;
		do{
			in = getchar();
		}while(in==0x0a);
		processInput(in);
		player = !player;
	}

}
void processInput(char in){
	int x,y;
	switch(in){
		case 'q':
		case 'Q':
			gameover=true;
			return;
			break;
		case '7':
			x=0;
			y=0;
			break;
		case '8':
			x=1;
			y=0;
			break;
		case '9':
			x=2;
			y=0;
			break;
		case '4':
			x=0;
			y=1;
			break;
		case '5':
			x=1;
			y=1;
			break;
		case '6':
			x=2;
			y=1;
			break;
		case '1':
			x=0;
			y=2;
			break;
		case '2':
			x=1;
			y=2;
			break;
		case '3':
			x=2;
			y=2;
			break;
		default:
			x=-1;
			y=-1;
			break;
	}
	int px = 3*X+x;
	int py = 3*Y+y;

	grid[px][py] = player==true ? 'x' : 'o';

	X=x;
	Y=y;
}

void newGame(){
	for(int x=0;x<9;x++){
		for(int y=0;y<9;y++){
			grid[x][y] = ' ';
		}
	}
	gameover = false;
	turns=0;
}

void printGrid(){
	/* cout << TOP_LEFT; */
	printLine(TOP_LEFT, TOP_RIGHT, T_L_L, T_L_H, H_LIGHT,0);
	for (int y = 0; y < 9; ++y) {
		cout << V_LIGHT << " ";
		for (int x = 0; x < 9; ++x) {
			bool condition = (y>=Y*3 && y < (Y+1)*3) && (x>=X*3 && x<(X+1)*3);
			if(condition)
				cout << RED;
			cout << grid[x][y];
			if(x==2||x==5)
				cout << " " << V_HEAVY <<" ";
			else
				cout << " " << V_LIGHT << " ";
			if(condition)
				cout << RESET;
		}
		cout << endl;
		if(y==8){
			printLine(BOT_LEFT, BOT_RIGHT, B_L_L, B_L_H, H_LIGHT,y);
		}else if(y==2||y==5){
			printLine(L_L_H, R_L_H, X_L_H, X_H_H, H_HEAVY,y);
		}
		else{
			printLine(L_L_L, R_L_L, X_L_L, X_H_L, H_LIGHT,y);
		}
	}
	cout << endl;
	cout << "X: " << X;
	cout << "Y: " << Y;
}

void printLine(string left, string right, string sep, string sep_h, string mid, int y){
	cout << left;

	for (int x = 0; x < 9; ++x) {
		bool condition = (y>=Y*3 && y < (Y+1)*3) && (x>=X*3 && x<(X+1)*3);
		if(condition)
			cout << RED;
		cout << mid << mid << mid;
		if(x==8)
			cout << right << endl;
		else if(x==2||x==5)
			cout << sep_h;
		else
			cout << sep;
		if(condition)
			cout << RESET;
	}
}

//TODO
bool checkWin(){
	return false;
}
