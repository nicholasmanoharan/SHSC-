board = [" " for _ in range(9)]

def print_board():
    for row in [board[i:i+3] for i in range(0, 9, 3)]:
        print(" | ".join(row))
        print("-" * 9)

def check_win():
    win_conditions = [(0, 1, 2), (3, 4, 5), (6, 7, 8), (0, 3, 6), (1, 4, 7), (2, 5, 8), (0, 4, 8), (2, 4, 6)]
    for condition in win_conditions:
        if board[condition[0]] == board[condition[1]] == board[condition[2]] != " ":
            return True
    return False

player = "X"
while True:
    print_board()
    try:
        move = int(input(f"Player {player}, enter your move (1-9): ")) - 1
        if board[move] == " ":
            board[move] = player
            if check_win():
                print_board()
                print(f"Player {player} wins!")
                break
            elif " " not in board:
                print_board()
                print("It's a draw!")
                break
            player = "O" if player == "X" else "X"
    except (ValueError, IndexError):
        print("Invalid move. Please try again.")