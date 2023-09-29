#include <iostream>
#include <cstring>

const int BOARD_SIZE = 3;

class TicTacToe {
public:
    TicTacToe() {
        InitializeBoard();
    }

    void PlayGame() {
        char currentPlayer = 'X';

        while (true) {
            DisplayBoard();
            std::cout << "Player " << currentPlayer << ", enter your move (e.g., A1): ";
            char input[3];
            std::cin >> input;

            if (strlen(input) != 2 || !isalpha(input[0]) || !isdigit(input[1])) {
                std::cout << "Invalid input. Please enter a valid move (e.g., A1)." << std::endl;
                continue;
            }

            int row = input[0] - 'A';
            int col = input[1] - '1';

            if (!IsLegalMove(row, col)) {
                std::cout << "Illegal move. Please choose an empty cell." << std::endl;
                continue;
            }

            board[row][col] = currentPlayer;

            if (CheckWin(currentPlayer)) {
                DisplayBoard();
                std::cout << "Player " << currentPlayer << " wins!" << std::endl;
                break;
            }

            bool isTie = true;
            for (int i = 0; i < BOARD_SIZE; i++) {
                for (int j = 0; j < BOARD_SIZE; j++) {
                    if (board[i][j] == ' ') {
                        isTie = false;
                        break;
                    }
                }
                if (!isTie) {
                    break;
                }
            }

            if (isTie) {
                DisplayBoard();
                std::cout << "It's a tie!" << std::endl;
                break;
            }

            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
    }

private:
    char board[BOARD_SIZE][BOARD_SIZE];

    void InitializeBoard() {
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                board[i][j] = ' ';
            }
        }
    }

    void DisplayBoard() const {
        std::cout << "  1 2 3" << std::endl;
        for (int i = 0; i < BOARD_SIZE; i++) {
            std::cout << char('A' + i) << " ";
            for (int j = 0; j < BOARD_SIZE; j++) {
                std::cout << board[i][j];
                if (j < BOARD_SIZE - 1) {
                    std::cout << "|";
                }
            }
            std::cout << std::endl;
            if (i < BOARD_SIZE - 1) {
                std::cout << "  -+-+-" << std::endl;
            }
        }
    }

    bool IsLegalMove(int row, int col) const {
        return row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE && board[row][col] == ' ';
    }

    bool CheckWin(char player) const {
        for (int i = 0; i < BOARD_SIZE; i++) {
            if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
                return true; // Row win
            }
            if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
                return true; // Column win
            }
        }
        if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
            return true; // Diagonal win (top-left to bottom-right)
        }
        if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
            return true; // Diagonal win (top-right to bottom-left)
        }
        return false;
    }
};

int main() {
    while (true) {
        TicTacToe game;
        game.PlayGame();
        std::cout << "Play again? (y/n): ";
        char choice;
        std::cin >> choice;
        if (choice != 'y' && choice != 'Y') {
            break;
        }
    }

    return 0;
}
