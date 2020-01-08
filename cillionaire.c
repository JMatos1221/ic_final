#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>


void print_menu();
int seeded = 0, score = 0;
FILE *fpointer;

int main(int argc, char **argv) {

    for (int i = 1; i <= argc; i += 2) {

        if (strcmp(argv[i],"-s") == 1) {

            srand(atoi(argv[i+1]));
            seeded = 1;

        }

        else if (strcmp(argv[i],"-f") == 1) {

            fpointer = fopen(argv[i+1], "rw");

        }

    }

    if (!seeded) { srand(time(0)); }

    return 0;
}

void print_menu() {

    puts("********************************************");
    puts("***             CILLIONAIRE                *");
    puts("********************************************");
    puts("*** n <name> - new game                    *");
    puts("*** q - quit                               *");
    puts("*** h - show this menu                     *");
    puts("*** r <filename> - resume game             *");
    puts("*** s <filename> - save progress and quit  *");
    puts("*** j 50 - play 50:50 joker                *");
    puts("*** j 25 - play 25:75 joker                *");
    puts("*** c - show credits                       *");
    puts("********************************************");

}