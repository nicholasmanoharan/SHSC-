def print_board():
    for row in [board[i:i + 3] for i in range(0, 9, 3)]:
        print(" | ".join(row))
        print("-" * 9)

def check_win():
    win_conditions = [(0, 1, 2), (3, 4, 5), (6, 7, 8), (0, 3, 6), (1, 4, 7), (2, 5, 8), (0, 4, 8), (2, 4, 6)]
    for condition in win_conditions:
        if board[condition[0]] == board[condition[1]] == board[condition[2]] != " ":
            return True
    return False

def place_player(player, move):
    board[move] = player

def minimax(board, depth, is_maximizing):
    if check_win():
        if is_maximizing:
            return -1  # Opponent wins
        else:
            return 1  # Computer wins
    elif " " not in board:
        return 0  # It's a draw

    if is_maximizing:
        best = -10000
        for move in range(9):
            if board[move] == " ":
                place_player("O", move)  # Computer's move
                evaluation = minimax(board, depth - 1, False)
                board[move] = " "  # Undo the move
                best = max(best, evaluation)
        return best
    else:
        worst = 10000
        for move in range(9):
            if board[move] == " ":
                place_player("X", move)  # Player's move
                evaluation = minimax(board, depth - 1, True)
                board[move] = " "  # Undo the move
                worst = min(worst, evaluation)
        return worst

def find_best_move():
    best_move = -1
    best_eval = float('-inf')
    for move in range(9):
        if board[move] == " ":
            place_player("O", move)  # Computer's move
            eval = minimax(board, 0, False)
            board[move] = " "  # Undo the move
            if eval > best_eval:
                best_eval = eval
                best_move = move
    return best_move

board = [" " for _ in range(9)]
player = "X"
while True:
    print_board()
    if player == "X":
        try:
            move = int(input(f"Player {player}, enter your move (1-9): ")) - 1
            if board[move] == " ":
                place_player("X", move)
                if check_win():
                    print_board()
                    print(f"Player {player} wins!")
                    break
                elif " " not in board:
                    print_board()
                    print("It's a draw!")
                    break
                player = "O"
            else:
                print("Invalid move. Please try again.")
        except (ValueError, IndexError):
            print("Invalid input. Please enter a number between 1 and 9.")
    else:
        computer_move = find_best_move()
        place_player("O", computer_move)
        if check_win():
            print_board()
            print("Computer wins!")
            break
        elif " " not in board:
            print_board()
            print("It's a draw!")
            break
        player = "X"
