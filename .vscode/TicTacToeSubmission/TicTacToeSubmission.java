// Nicholas Manoharan
// Tic Tac Toe
// This is the classic game of Tic Tac Toe that players play in the console
package TicTacToeSubmission;
import java.util.Scanner;
public class TicTacToeSubmission {
//This section starts the board and also sets up how each player operates
int[][] board = new int[3][3];
final int BLANK = 0;
final int X_MOVE = 1;
final int O_MOVE = 2;
final int X_TURN = 0;
final int O_TURN = 1;
public static int X_TALLY = 0;
public static int O_TALLY = 0;
public static int TIE_TALLY = 0;
public boolean continuePlaying = true;
int turn = X_TURN;
Scanner scanner;
static String input = "";
public TicTacToeSubmission() {
//This is where you check if the player would like to continue playing
scanner = new Scanner(System.in);
boolean stillPlaying = true;
while (stillPlaying == true) {
//This is where input by the user is checked
while (checkWin(X_MOVE) == false && checkWin(O_MOVE) == false &&
checkTie() == false) {
printBoard();
input = scanner.nextLine();
if (input.length() != 2) {
System.out.println("Enter a letter followed by a number");
}
else if (input.charAt(0) != 'a' && input.charAt(0) != 'b' &&
input.charAt(0) != 'c') {
System.out.println("Row must be an a, b, or c");
}
else if (input.charAt(1) != '1' && input.charAt(1) != '2' &&
input.charAt(1) != '3') {
System.out.println("Column must be a 1, 2, or 3");
}
else {
int row = input.charAt(0) - 'a';
int column = input.charAt(1) - '1';
if (board[row][column] == BLANK) {
if (turn == X_TURN) {
board[row][column] = X_MOVE;
turn = O_TURN;
}
else {
board[row][column] = O_MOVE;
turn = X_TURN;
}
}
else {
System.out.println("There is a piece there!");
}
}
}
//This is where the program checks to see which player has won and
//displays the win count
if (checkWin(X_MOVE) == true) {
System.out.println("X Wins!");
X_TALLY++;
System.out.println("X has won: " + X_TALLY);
System.out.println("O has won: " + O_TALLY);
break;
}
else if (checkWin(O_MOVE) == true) {
System.out.println("O wins!");
O_TALLY++;
System.out.println("O has won: " + O_TALLY);
System.out.println("X has won: " + X_TALLY);
}
break;
}
}
//Once the game ends, this section will question if the users wants to play
//again
public static void main(String[] args) {
Scanner scanner1;
boolean continuePlaying = true;
while(continuePlaying == true) {
new TicTacToeSubmission();
boolean continueResponseQuestion = true;
while(continueResponseQuestion == true) {
System.out.println("Would you like to play again? Y/N");
scanner1 = new Scanner(System.in);
input = scanner1.nextLine();
if ((input.charAt(0) == 'Y') || (input.charAt(0) == 'y')) {
continuePlaying = true;
continueResponseQuestion = false;
}
else if (input.charAt(0) == 'N' || (input.charAt(0) == 'n')){
System.out.println("The game is ending");
continuePlaying = false;
continueResponseQuestion = false;
}
else {
System.out.println("Enter a valid response");
continueResponseQuestion = true;
}
}
}
}
//This is where the setup of the board is. When the user inputs X or Y, this
//is how it outputs to the user
public void printBoard() {
System.out.println(" \t1\t2\t3");
for (int row = 0; row < board.length; row++) {
String output = (char)('a' + row) + "\t";
for (int column = 0; column < board[0].length; column ++) {
if (board[row][column] == BLANK) {
output += " \t";
}
else if (board[row][column] == X_MOVE) {
output += "X\t";
}
else if (board[row][column] == O_MOVE) {
output += "O\t";
}
}
System.out.println(output);
}
}
//When coming to this section, the program will check to see if the user has
//3 of their characters in a row.
public boolean checkWin(int player) {
if(board[0][0] == player && board[0][1] == player && board[0][2]==
player) {
return true;
}
if (board[0][0] == player && board[1][1] == player && board[2][2] ==
player) {
return true;
}
if (board[0][2] == player && board[1][2] == player && board[2][2] ==
player) {
return true;
}
if (board[2][0] == player && board[1][1] == player && board[0][2] ==
player) {
return true;
}
if (board[0][1] == player && board [1][1] == player && board[2][1] ==
player) {
return true;
}
if (board[2][0] == player && board[2][1] == player && board[2][2] ==
player) {
return true;
}
if (board[1][0] == player && board [1][1] == player && board[1][2] ==
player) {
return true;
}
return false;
}
//If the game were to end in a tie, the program will run this and output the
//win counter as well as the tie
public boolean checkTie() {
for (int row = 0; row < board.length; row++) {
for (int column = 0; column < board[0].length; column++) {
if (board[row][column] == BLANK) {
return false;
}
}
}
System.out.println("The Game has ended in a tie");
TIE_TALLY++;
System.out.println("Ties: " + TIE_TALLY);
System.out.println("X has won: " + X_TALLY);
System.out.println("O has won: " + O_TALLY);
return true;
}
}