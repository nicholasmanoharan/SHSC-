/*
Nicholas Manoharan
Mr. Galbraith
C++ 

Palindrome Project - Determine if the user input is a palindrome or not
*/


#include <iostream>
#include <cstring>
#include <cctype>
#include <limits> // Include the <limits> header for clearing the input buffer

int main() {

    //Setting up variables
    const int maxInputLength = 80;
    char* input = new char[maxInputLength + 2]; // +2 for the null terminator and an extra character
    char* clean = new char[maxInputLength + 1];
    char* rev = new char[maxInputLength + 1];
    bool shouldQuit = false;

    std::cout << "Enter a series of characters (max 80 characters. Type 'q' to quit): ";

    while (!shouldQuit) {
        std::cin.getline(input, maxInputLength);

        if (strcmp(input, "q") == 0) {
            shouldQuit = true;
        } else {
            if (std::cin.fail()) {
                // Input exceeds max length, clear the buffer
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Input exceeded 80 characters. Try again." << std::endl;
                continue; // Skip the processing and ask for input again
            }

            memset(clean, 0, maxInputLength + 1);
            memset(rev, 0, maxInputLength + 1);

            // Remove spaces, punctuation, and convert to lowercase
            int ci = 0;
            for (int i = 0; input[i]; ++i) {
                if (isalnum(input[i])) {
                    clean[ci++] = tolower(input[i]);
                }
            }

            int len = strlen(clean);
            bool isPalindrome = true;

            for (int i = 0; i < len / 2; ++i) {
                if (clean[i] != clean[len - 1 - i]) {
                    isPalindrome = false;
                    break;
                }
            }
            
            //Displaying if the user input is a palindrome or not
            std::cout << (isPalindrome ? "Palindrome" : "Not a palindrome") << std::endl;
        }
    }

    delete[] input;
    delete[] clean;
    delete[] rev;

    return 0;
}
