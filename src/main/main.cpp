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
	printLine(TOP_LEFT, TOP_LEFT, TOP_RIGHT, TOP_RIGHT, T_L_L, T_L_H, H_LIGHT, H_HEAVY);
	for (int y = 0; y < 9; ++y) {
		cout << V_LIGHT << " ";
		for (int x = 0; x < 9; ++x) {
			cout << grid[x][y];
			if(x==2||x==5)
				cout << " " << V_HEAVY <<" ";
			else
				cout << " " << V_LIGHT << " ";
		}
		cout << endl;
		if(y==8){
			printLine(BOT_LEFT, BOT_LEFT, BOT_RIGHT, BOT_RIGHT, B_L_L, B_L_H, H_LIGHT, H_LIGHT);
		}else if(y==2||y==5){
			printLine(L_L_H, L_L_H, R_L_H, R_L_H, X_L_H, X_H_H, H_HEAVY, H_HEAVY);
		}
		else{
			printLine(L_L_L, L_L_L, R_L_L, R_L_L, X_L_L, X_H_L, H_LIGHT, H_LIGHT);
		}
		/* cout << endl; */
	}
	/* for (int x = 0; x < 9; ++x) { */
	/* 	cout << grid[x][8]; */
	/* 	if(x==2||x==5) */
	/* 		cout << " " << V_HEAVY <<" "; */
	/* 	else */
	/* 		cout << " " << V_LIGHT << " "; */
	/* } */
	cout << endl;
	cout << "X: " << X;
	cout << "Y: " << Y;
}

void printLine(string left, string left_h, string right, string right_h, string sep, string sep_h, string mid, string mid_h){
	cout << left;
	for (int x = 0; x < 9; ++x) {
		cout << mid << mid << mid;
		if(x==8)
			cout << right << endl;
		else if(x==2||x==5)
			cout << sep_h;
		else
			cout << sep;
	}
}

bool checkWin(){
	bool zzd = grid[0][0]==grid[0][1]&&grid[0][0]==grid[0][2] && grid[0][0]!=' ';
	bool jzd = grid[1][0]==grid[1][1]&&grid[1][0]==grid[1][2] && grid[1][0]!=' ';
	bool dzd = grid[2][0]==grid[2][1]&&grid[2][0]==grid[2][2] && grid[2][0]!=' ';

	bool zzl = grid[0][0]==grid[1][0]&&grid[0][0]==grid[2][0] && grid[0][0]!=' ';
	bool zjl = grid[0][1]==grid[1][1]&&grid[0][1]==grid[2][1] && grid[0][1]!=' ';
	bool zdl = grid[0][2]==grid[1][2]&&grid[0][2]==grid[2][2] && grid[0][1]!=' ';

	bool zzs = grid[0][0]==grid[1][1]&&grid[0][0]==grid[2][2] && grid[0][0]!=' ';
	bool dds = grid[2][0]==grid[1][1]&&grid[2][0]==grid[0][2] && grid[2][0]!=' ';

	return zzd || jzd || dzd
		|| zzl || zjl || zdl
		|| zzs || dds;
}
