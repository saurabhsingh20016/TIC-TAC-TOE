#include <stdio.h>

void displayBoard(char board[3][3]) {
    int i, j;
    printf("\nTic-Tac-Toe Board:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);
            if (j < 2)
                printf("|");
        }
        printf("\n");
        if (i < 2)
            printf("---|---|---\n");
    }
    printf("\n");
}

int checkWinner(char board[3][3]) {
    int i;
    for (i = 0; i < 3; i++) {
        // Check rows
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
            return 1;
        // Check columns
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
            return 1;
    }
    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
        return 1;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
        return 1;

    return 0;
}

int main() {
    char board[3][3] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };
    char currentPlayer = 'X';
    int row, col;
    int moves = 0;

    while (1) {
        displayBoard(board);
        printf("Player %c, enter row and column (1-3): ", currentPlayer);
        if (scanf("%d %d", &row, &col) != 2) {
            printf("Invalid input. Exiting.\n");
            return 1;
        }

        row--;
        col--;

        if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
            printf("Invalid move. Try again.\n");
            continue;
        }

        board[row][col] = currentPlayer;
        moves++;

        if (checkWinner(board)) {
            displayBoard(board);
            printf("🎉 Player %c wins!\n", currentPlayer);
            break;
        }

        if (moves == 9) {
            displayBoard(board);
            printf("🤝 It's a draw!\n");
            break;
        }

        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    return 0;
}
