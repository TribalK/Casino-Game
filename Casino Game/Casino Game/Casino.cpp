#include "Casino.h"

void Casino::initializeFlags()
{
	for (int i = 0; i < 3; i++) {
		instructFlags[i] = true;
	}
}

bool Casino::checkFlags(int ID)
{
	return instructFlags[ID];
}

void Casino::updateFlags(int ID)
{
	instructFlags[ID] = false;
}