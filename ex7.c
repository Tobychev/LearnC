#include <stdio.h>

int main(int argc, char *argv[])
{
    int    bugs = 100;
    double bug_rate = 1.2;
    long   universe_of_defects =  1L * 1024L * 1024L * 1024L;
    double expected_bugs = bugs*bug_rate;
    double part_of_universe = expected_bugs / universe_of_defects;
    char   nul_byte ='\0';
    int    care_percentage = bugs * nul_byte;

    printf("You have %d bugs at a rate of %f.\n",
           bugs,bug_rate);
    printf("The entire universe has %ld bugs\n",
            universe_of_defects);
    printf("You are expected to have %f bugs\n",
            expected_bugs);
    printf("That is only a %e portion of the universe\n",
            part_of_universe);
    printf("Which means you should care %d%%.\n",
            care_percentage);
    printf("Lastly, here is the null byte: %c\n",
            nul_byte);
    return 0;
}
