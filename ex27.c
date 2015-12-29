#define NDEBUG
#include "dbg.h"
#include <stdio.h>
#include <assert.h>

void copy(char to[], char from[])
{
	int i = 0;
	while ((to[i] = from[i]) != '\0') {
		++i;}
}

int safercopy(int fromlen, char* from, int tolen, char* to)
{
	assert(from != NULL && to != NULL && "From and to can't be NULL");
	int i = 0;
	int max = fromlen > tolen -1  ? tolen-1 : fromlen;

	if(fromlen < 0 || tolen <=0 ) {
		return -1;}

	for (i = 0; i < max; i++) {
		to[i] = from[i];}
	
	to[tolen-1] = '\0';
	return i;  
}

int main(int argc, char* argv[])
{
	char from[]  = "0123456789";
	int  fromlen = sizeof(from);

	char to[]  = "0123456";
	int  tolen = sizeof(to);

    debug("Copying '%s':%d to '%s':%d", from, fromlen, to, tolen);

    int rc = safercopy(fromlen, from, tolen, to);
    check(rc > 0, "Failed to safercopy.");
    check(to[tolen - 1] == '\0', "String not terminated.");

    debug("Result is: '%s':%d", to, tolen);

    // now try to break it
    rc = safercopy(-1*fromlen , from, tolen, to);
    check(rc == -1, "safercopy should fail #1");
    check(to[tolen - 1] == '\0', "String not terminated.");

    rc = safercopy(fromlen, from, 0, to);
    check(rc == -1, "safercopy should fail #2");
    check(to[tolen - 1] == '\0', "String not terminated.");

    return 0;

error:

    return 1;
}
