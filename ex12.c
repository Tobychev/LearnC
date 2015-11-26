#include <stdio.h>

int main(int argc, char* argv[])
{
	int i = 0;
	if (argc == 1){
		printf("no argument \n");	}
	else if (argc == 2){
		printf("one argument\n");}
	else if (argc > 2 && argc < 5){
		printf("arguments:\n");
		for( i = 1; i < argc; i++ ){
			printf("%s ",argv[i]);}
		printf("\n");}
	else {
		printf("too many arguments \n");}
	return 0;
}
