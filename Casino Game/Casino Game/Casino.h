/************************************************
Casino.h

Header file that contains libraries and
class structures for the entire Casino program.

************************************************/

#pragma once
//Include libraries

#include <iostream>
#include <string>
#include <ctime>
#include <algorithm>
#include <direct.h>
#include <cstdlib>
#include <cstdio>

const int CHOICE_1 = 1;
const int CHOICE_2 = 2;
const int CHOICE_3 = 3;
const int CHOICE_4 = 4;
const int CHOICE_5 = 5;

/***********************************************
Casino Class

Used to determine information set by the Player
class. Whenever a game is played by the player,
money, a current value is set for updating. The
getter and setter functions are utilized whenever
we need to update the player's cash (and score)
values.

The flag functions are utilized to display each
option's help information a single time unless
requested by the user otherwise.

***********************************************/
class Casino
{
private:
	static bool instructFlags[4];
public:
	static bool checkFlags(int ID);
	static void updateFlags(int ID);
};