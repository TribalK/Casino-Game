#include "FrenzyUtil.h"

//Constructor
FrenzyUtil::FrenzyUtil(int v)
{
	this->holdVal = v;
}

//Setter function
void FrenzyUtil::setVal(int v)
{
	this->holdVal = v;
}

//Getter function
int FrenzyUtil::getVal() 
{
	return holdVal;
}

//Operator overloading definitions
int operator +(FrenzyUtil& T1, FrenzyUtil& T2) {
	std::cout << "Add called\n";
	FrenzyUtil T3(T1.getVal() + T2.getVal());
	return T3.getVal();
}
int operator -(FrenzyUtil& T1, FrenzyUtil& T2) {
	std::cout << "Subtract called\n";
	FrenzyUtil T3(T1.getVal() - T2.getVal());
	return T3.getVal();
}
int operator *(FrenzyUtil& T1, FrenzyUtil& T2) {
	std::cout << "Multiply called\n";
	FrenzyUtil T3(T1.getVal() * T2.getVal());
	return T3.getVal();
}