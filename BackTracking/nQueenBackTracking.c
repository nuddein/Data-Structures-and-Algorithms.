#include <stdio.h>
#include <stdbool.h>

#define N 4

// Function to print the chessboard
void printBoard(int board[N][N]) {
	int i,j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++)
            printf("%2d ", board[i][j]);
        printf("\n");
    }
    printf("\n");
}

// Function to check if it's safe to place a queen at board[row][col]
bool isSafe(int board[N][N], int row, int col) {
    // Check this row on left side
    int i,j;
    for ( i = 0; i < col; i++)
        if (board[row][i])
            return false;

    // Check upper diagonal on left side
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    // Check lower diagonal on left side
    for (i = row, j = col; i < N && j >= 0; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

// Recursive function to solve N-Queens problem using backtracking
bool solveNQueensUtil(int board[N][N], int col) {
    // If all queens are placed, return true
    if (col >= N)
        return true;

    // Try placing this queen in all rows one by one
    int i;
    for (i = 0; i < N; i++) {
        if (isSafe(board, i, col)) {
            // Place this queen in board[i][col]
            board[i][col] = 1;

            // Recur to place rest of the queens
            if (solveNQueensUtil(board, col + 1))
                return true;

            // If placing queen in board[i][col] doesn't lead to a solution, then backtrack
            board[i][col] = 0;
        }
    }

    // If the queen can't be placed in any row in this column, return false
    return false;
}

// Function to solve N-Queens problem and print the solution
void solveNQueens() {
    int board[N][N] = {0}; // Initialize the chessboard

    if (!solveNQueensUtil(board, 0))
        printf("Solution does not exist\n");
    else
        printBoard(board);
}

int main() {
    solveNQueens();
    return 0;
}


