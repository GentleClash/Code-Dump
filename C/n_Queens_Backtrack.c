#include <stdio.h>
#include <stdlib.h>

int is_valid(int *board, int row, int col, int n) {
    for (int i= 0; i < row; i++) {
        if (board[i] == col || abs(board[i] - col) == abs(i - row)) {
            return 0;
        }
    }
    return 1;
}

void print_board(int *board, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i]==j) {
                printf("Q ");
            }
            else {
                printf(". ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

void solve_n_queens(int *board, int row, int n) {
    if (row == n) {
        print_board(board, n);
        return;
    }

    for (int col = 0; col < n; col++) {
        if (is_valid(board, row, col, n)) {
            board[row] = col;
            solve_n_queens(board, row + 1, n);
            board[row] = -1;
        }
    }
}

int main() {
    int n;
    printf("Enter the dimension of the board: ");
    scanf("%d", &n);
    int *board = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        board[i] = -1;
    }
    solve_n_queens(board, 0, n);
    return 0;
}
