#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>


void print_menu(), print_credits(), question_get();
int seeded = 0, level = 1,  run = 1;
char command[32], name[32], *filename, j25[] = "YES", j50[] = "YES";
FILE *fpointer;

int main(int argc, char **argv) {

    for (int i = 1; i <= argc - 1; i += 2) {

        if (argv[i][1] == 's') {

            srand(atoi(argv[i+1]));
            seeded = 1;

        }

        else if (argv[i][1] == 'f') {

            filename = argv[i + 1];
            fpointer = fopen(filename, "rt");

        }

    }

    if (!seeded) { srand(time(0)); }

    puts("********************************************");
    puts("***            CILLIONAIRE                 *");
    puts("********************************************");
    puts("*** n <name>     - new game                *");
    puts("*** q            - quit                    *");
    puts("*** h            - show this menu          *");
    puts("*** r <filename> - resume game             *");
    puts("*** s <filename> - save progress and quit  *");
    puts("*** j 50         - play 50:50 joker        *");
    puts("*** j 25         - play 25:75 joker        *");
    puts("*** c            - show credits            *");
    puts("********************************************");

    do {
        fgets(command, 32, stdin);

        switch(command[0]) {

        case 'n':
            level = 1;
            strcpy(j50, "YES");
            strcpy(j25, "YES");
            if (command[1] == '\0') {
                strcpy(name, "newbie");
                }
            else {
                for (int i = 2; command[i] != '\n'; i++) {
                    name[i - 2] = command[i];
                }
            }
            printf("*** Hi %s, let's get started!\n", name);
            puts("********************************************");
            printf("*** Name:  %s                           *\n", name);
            printf("*** Level: %d                               *\n", level);
            printf("*** j50:   %s                             *\n", j50);
            printf("*** j25:   %s                             *\n", j25);
            puts("********************************************");
            break;

        case 'q':
            puts(">*** Sad to see you go...");
            run = 0;
            break;

        case 'h':
            print_menu();
            break;

        case 'j':
            if (strcmp(command, "j 25") == 0) {
                strcpy(j25, "NO");
                break;
            }
            else if (strcmp(command, "j 50") == 0) {
                strcpy(j25, "NO");
                break;
            }
            else {
                puts("Unknown Joker Command");
            }
            break;

        case 'c':
            print_credits();
            break;

        default:
            puts("Unknown Command!");
            
        }

    } while (run);

    return 0;
}

void print_menu() {

    puts(">********************************************");
    puts("***            CILLIONAIRE                 *");
    puts("********************************************");
    puts("*** n <name>     - new game                *");
    puts("*** q            - quit                    *");
    puts("*** h            - show this menu          *");
    puts("*** r <filename> - resume game             *");
    puts("*** s <filename> - save progress and quit  *");
    puts("*** j 50         - play 50:50 joker        *");
    puts("*** j 25         - play 25:75 joker        *");
    puts("*** c            - show credits            *");
    puts("********************************************");

}

void print_credits() {
    puts("**********************************");
    puts("***           Autores          ***");
    puts("*** Andre Figueira - 21901435  ***");
    puts("*** Joao Matos - 21901219      ***");
    puts("*** Ruben Cerqueira - 21902961 ***");
    puts("**********************************");
}