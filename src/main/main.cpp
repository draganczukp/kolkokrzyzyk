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
	cout << "\u250c\u2500\u2500\u2500\u252c\u2500\u2500\u2500\u252c\u2500\u2500\u2500\u2530\u2500\u2500\u2500\u252c\u2500\u2500\u2500\u252c\u2500\u2500\u2500\u2530\u2500\u2500\u2500\u252c\u2500\u2500\u2500\u252c\u2500\u2500\u2500\u2510" << endl << "\u2502 ";
	for (int y = 0; y < 8; ++y) {
		for (int x = 0; x < 9; ++x) {
			cout << grid[x][y];
			if(x==2||x==5)
				cout << " \u2503 ";
			else
				cout << " \u2502 ";
		}
		if(y==2||y==5)
			cout << endl << "\u251d\u2501\u2501\u2501\u253f\u2501\u2501\u2501\u253f\u2501\u2501\u2501\u254b\u2501\u2501\u2501\u253f\u2501\u2501\u2501\u253f\u2501\u2501\u2501\u254b\u2501\u2501\u2501\u253f\u2501\u2501\u2501\u253f\u2501\u2501\u2501\u2525" << endl << "\u2502 ";
		else
			cout << endl << "\u251c\u2500\u2500\u2500\u253c\u2500\u2500\u2500\u253c\u2500\u2500\u2500\u2542\u2500\u2500\u2500\u253c\u2500\u2500\u2500\u253c\u2500\u2500\u2500\u2542\u2500\u2500\u2500\u253c\u2500\u2500\u2500\u253c\u2500\u2500\u2500\u2524" << endl << "\u2502 ";
	}
	for (int x = 0; x < 9; ++x) {
		cout << grid[x][8];
		if(x==2||x==5)
			cout << " \u2503 ";
		else
			cout << " \u2502 ";
	}
	cout <<endl << "\u2514\u2500\u2500\u2500\u2534\u2500\u2500\u2500\u2534\u2500\u2500\u2500\u2538\u2500\u2500\u2500\u2534\u2500\u2500\u2500\u2534\u2500\u2500\u2500\u2538\u2500\u2500\u2500\u2534\u2500\u2500\u2500\u2534\u2500\u2500\u2500\u2518";
	cout << endl;
	cout << "X: " << X;
	cout << "Y: " << Y;
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
