#pragma once
#include "Game.h"
class FrenzyUtil
{
private:
	//value held for the individual utility object
	int holdVal;
public:
	FrenzyUtil() {};
	FrenzyUtil(int v);
	void setVal(int v);
	int getVal();

	//Uses operator overloading for arithmetic
	//Performed on value held by T1 with T2
	friend int operator +(FrenzyUtil& T1, FrenzyUtil& T2);
	friend int operator -(FrenzyUtil& T1, FrenzyUtil& T2);
	friend int operator *(FrenzyUtil& T1, FrenzyUtil& T2);
};