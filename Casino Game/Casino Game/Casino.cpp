#include "Casino.h"

/******************************************
Initializing flags to indicate when to call 
each Help function (begin vs. request).

Convenience for player to want to consult 
help whenever they request or forget inputs.
*******************************************/
bool Casino::instructFlags[] = {true, true, true, true};
/******************************************
State to check if the flag is active.
After entering an option for the first time,
the flag becomes inactive and the rules will
need to be requested with "Help" in order to
temporarily access that option's ruleset.
*******************************************/
bool Casino::checkFlags(int ID)
{
	return instructFlags[ID];
}

/******************************************
After initial entry into an option, the
instruction flag set for that option is
marked as false so that it may no repeat
the instructions to acknowledged patrons
unless they choose to call it with "Help".
*******************************************/
void Casino::updateFlags(int ID)
{
	instructFlags[ID] = false;
}