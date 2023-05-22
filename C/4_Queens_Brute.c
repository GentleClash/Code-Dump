#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int row;
    int col;
} Queen;

void n_queens_4x4() {
    Queen queens[4];
    int num_solutions = 0;

    for (int col1 = 0; col1 < 4; col1++) {
        queens[0].row = 0;
        queens[0].col = col1;

        for (int col2 = 0; col2 < 4; col2++) {
            queens[1].row = 1;
            queens[1].col = col2;

            for (int col3 = 0; col3 < 4; col3++) {
                queens[2].row = 2;
                queens[2].col = col3;

                for (int col4 = 0; col4 < 4; col4++) {
                    queens[3].row = 3;
                    queens[3].col = col4;

                    int valid = 1;
                    for (int i = 0; i < 3; i++) {
                        for (int j = i + 1; j < 4; j++) {
                            if (queens[i].row == queens[j].row ||
                                queens[i].col == queens[j].col ||
                                queens[i].row - queens[i].col == queens[j].row - queens[j].col ||
                                queens[i].row + queens[i].col == queens[j].row + queens[j].col) {
                                valid = 0;
                                break;
                            }
                        }
                        if (!valid) {
                            break;
                        }
                    }

                    if (valid) {
                        num_solutions++;
                        printf("Solution found: ");
                        for (int i = 0; i < 4; i++) {
                            printf("(%d, %d) ", queens[i].row + 1, queens[i].col + 1);
                        }
                        printf("\n");
                    }
                }
            }
        }
    }

    if (num_solutions == 0) {
        printf("No solution found.\n");
    }
}

int main() {
    n_queens_4x4();
    return 0;
}