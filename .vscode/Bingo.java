import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.util.*;

public class BingoGame extends JFrame {

    private JPanel bingoPanel;
    private JButton[][] bingoButtons;
    private ArrayList<Integer> numbers;
    private int currentNumberIndex = 0;

    public BingoGame() {
        setTitle("Bingo Game");
        setSize(500, 500);
        setDefaultCloseOperation(EXIT_ON_CLOSE);

        bingoPanel = new JPanel(new GridLayout(5, 5));
        bingoButtons = new JButton[5][5];
        numbers = new ArrayList<>();
        for (int i = 1; i <= 25; i++) numbers.add(i);
        Collections.shuffle(numbers);

        for (int row = 0; row < 5; row++) {
            for (int col = 0; col < 5; col++) {
                JButton button = new JButton();
                button.setFont(new Font("Arial", Font.PLAIN, 24));
                bingoButtons[row][col] = button;
                bingoPanel.add(button);
                final int r = row, c = col;
                button.addActionListener(e -> {
                    if (currentNumberIndex < 25) {
                        int number = numbers.get(currentNumberIndex);
                        bingoButtons[r][c].setText(number + "");
                        currentNumberIndex++;
                        checkForWin();
                    }
                });
            }
        }

        add(bingoPanel);
        setVisible(true);
    }

    private void checkForWin() {
        // Implement win-checking logic here
        // Display a message when the player wins
    }

    public static void main(String[] args) {
        new BingoGame();
    }
}
