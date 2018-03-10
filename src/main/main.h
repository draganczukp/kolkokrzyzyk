#pragma once


#include <iostream>
#include <string>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "symbols.h"

using namespace std;
void processInput(char in);
void newGame();
void play();
bool checkWin();
void printGrid();
void printLine(string left, string left_h, string right, string right_h, string sep, string sep_h, string mid, string mid_h);
