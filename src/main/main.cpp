#include "main.h"

using namespace std;

bool gameover = false;
/* char player = 'x'; */
bool player = true;
int turns = 0;

char grid[3][3] = {
	{' ',' ',' '},
	{' ',' ',' '},
	{' ',' ',' '}
};

int main(){

	char ans='y';

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
		cout << player << endl;
		printf("%c|%c|%c\n", grid[0][0],grid[1][0],grid[2][0]);
		printf("------\n");
		printf("%c|%c|%c\n", grid[0][1],grid[1][1],grid[2][1]);
		printf("------\n");
		printf("%c|%c|%c\n", grid[0][2],grid[1][2],grid[2][2]);

		char in;
		do{
			in = getchar();
		}while(in==0x0a);
		processInput(in);
		/* if(checkWin()){ */
		/* 	gameover=true; */
		/* 	/1* cout << "Wygrywa " << player=='x' ? 'o' : 'x' << "."; *1/ */
		/* 	printf("Wygrywa gracz %c\n", player ? 'x' : 'o'); */
		/* 	return; */
		/* } */
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
	grid[x][y] = player==true ? 'x' : 'o';
	/* player = player=='x' ? 'o' : 'x'; */
}

void newGame(){
	for(int x=0;x<3;x++){
		for(int y=0;y<3;y++){
			grid[x][y] = ' ';
		}
	}
	gameover = false;
	turns=0;
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
