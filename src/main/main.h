#pragma once


#define ENTER (0x0a)

#include <iostream>
#include <string>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "symbols.h"
#include "colors.h"

typedef struct Point{
	int x;
	int y;
} Point;

using namespace std;
void processInput(char in);
void newGame();
void play();
bool checkWin();
void printGrid();
void printLine(string left, string right, string sep, string sep_h, string mid_h, int y);
void getInputField(char in, Point *point);
bool shouldColor(int x, int y);
bool isInputValid(char in);
