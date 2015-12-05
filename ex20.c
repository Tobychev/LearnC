#include "dbg.h"
#include <stdlib.h>
#include <stdio.h>

void test_debug()
{
	debug("Test_debug: bown hare.");
	debug("Test_debug: Years old %d.",31);
}

void test_log_err()
{
	log_err("test_log_err: everything is broken");
	log_err("test_log_err: bah, %d of 10 are %s",0,"sellout");
}

void test_log_warn()
{
	log_warn("You can ignore this");
	log_warn("Maybe look at %s","/some/path");
}

void test_log_info()
{
    log_info("Well I did something mundane.");
    log_info("It happened %f times today.", 1.3f);
}

int test_check(char* filename)
{
	FILE* input = NULL;
	char* block = NULL;

	block = malloc(100);
	check_mem(block);

	input = fopen(filename,"r"); 
	check(input,"Failed to open %s", filename);

	free(block);
	fclose(input);
	return 0;
error:
	if (block) {
		free(block);}
	if (input) {
		fclose(input);}
	return -1;
}

int test_sentinel(int code)
{
	char* temp = malloc(100);
	check_mem(temp);
	
	switch(code) {
		case 1:
			log_info("All is well");
			break;
		default:
			sentinel("This should be unreachable");}

	free(temp);
	return 0;

error:
	if (temp) {
		free(temp);}
	return -1;
}		

int test_check_mem()
{
	char* test = NULL;
	check_mem(test);

	free(test);
	return 1;

error:
	return -1;
}

int test_check_debug()
{
	int i = 0;
	check_debug(i != 0, "It was 0");
	
	return 0;

error:
	return -1;
}

int main(int argc, char* argv[])
{
	check(argc == 2, "Need exactly one argument");

    test_debug();
    test_log_err();
    test_log_warn();
    test_log_info();

	check(test_check("ex20.c") == 0, "failed with ex20.c");
    check(test_check(argv[1]) == -1, "failed with argv");
    check(test_sentinel(1) == 0, "test_sentinel failed.");
    check(test_sentinel(100) == -1, "test_sentinel failed.");
    check(test_check_mem() == -1, "test_check_mem failed.");
    check(test_check_debug() == -1, "test_check_debug failed.");

    return 0;

error:
    return 1;	
}
