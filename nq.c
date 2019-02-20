#include <stdio.h>
#include <stdlib.h>

#define SOLUTION_REJECTED 		0
#define SOLUTION_NOT_REJECTED	1

int nq;	// Number of queens in problem.
int solutions = 0; // Total number of solutions.

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void display(int q[]) {
	for (int i = 0; i < nq; i++) {
		for (int j = 0; j < nq; j++) {
			// Checkerboard.
			char ch = ((i + j) % 2 == 0) ? ' ' : '.';
			// Queen.
			if (q[i] == j) { ch = 'Q'; }
			// Display square.
			printf("%c", ch);
		}
		printf("\n");
	}
	printf("\n");
}

int evaluate(int q[]) {
	// This is an n-rooks solution but we still
	// need to check the diagonals.
	int viable = SOLUTION_NOT_REJECTED;
	int i = -1;

	while (viable && ++i < nq) {
		for (int j = 0; j < nq; j++) {
			int dx = abs(j - i);
			int dy = abs(q[j] - q[i]);
			// Same offset on x and y axis implies a diagonal.
			if (dx == dy && dx > 0) { viable = SOLUTION_REJECTED; break; }
		}
	}

	return viable;
}

// Use Heap's algorithm to compute permutations.
void heaps(int q[], int n) {
	if (n == 1 && evaluate(q)) {
		solutions++; // Increment solution total.
		display(q); // Show the solution.
	} else {
		for (int i = 0; i < n; i++) {
			heaps(q, n - 1);
			if (n % 2 == 0) {
				swap(&q[i], &q[n - 1]);
			} else {
				swap(&q[0], &q[n - 1]);
			}
		}
	}
}

int main(int argc, char *argv[]) {
	if (argc < 2) {
		// Argument required to specify the magnitude of the problem.
		printf("Usage: pass the number of queens as an argument.\n");
    }
    else {
    	// Get problem magnitude.
		nq = atoi(argv[1]);
    	printf("Solving for %d queens\n\n", nq);

    	// Load initial array to permute.
    	int q[nq];
    	for (int i = 0; i < nq; i++) { q[i] = i; }

    	// Generate permutations.
    	// Permuting solves the n rooks problem, ensuring that no
    	// two queens share the same column or file.
    	heaps(q, nq);

    	// Report total solutions.
    	printf("Total solutions found = %d \n", solutions);
	}

    return 0;
}

