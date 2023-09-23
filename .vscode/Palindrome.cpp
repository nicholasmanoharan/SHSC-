#include <iostream>
#include <cstring>
#include <cctype>

int main() {
    char input[81], clean[81], rev[81];
    bool shouldQuit = false;

    while (!shouldQuit) {

        std::cout << "Enter a series of characters (max 80 characters, or 'q' to quit): ";
        std::cin.getline(input, 81);

        if (strcmp(input, "q") == 0)

            shouldQuit = true;

        else {

            for (int i = 0, ci = 0; input[i]; ++i) {
                
                if (isalnum(input[i]))
                    clean[ci++] = tolower(input[i]);
            }

            for (int i = strlen(clean) - 1, ri = 0; i >= 0; --i) {
                rev[ri++] = clean[i];
            }

            rev[strlen(clean)] = '\0';

            std::cout << (strcmp(clean, rev) == 0 ? "Palindrome" : "Not a palindrome") << std::endl;
        }
    }

    return 0;
}