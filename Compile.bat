set prgrm=cillionaire
gcc -c -g -Wall -Wpedantic -Wextra -std=c99 %prgrm%.c -o %prgrm%.o
gcc %prgrm%.o -o %prgrm%
pause