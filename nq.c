#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
	printf("Usage: pass the number of queens as an argument.\n");
	return 0;
    }

    int nq = atoi(argv[1]);
    printf("solving for num queens = %d\n", nq);
    return 0;
}

