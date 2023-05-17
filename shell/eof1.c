#include <stdio.h>

int main() {
    int c;

    while (1) {
        printf("$ ");

        // Read a character from the user
        c = getchar();
        // Check if the character is EOF
        if (c == EOF) {
            break; // Exit the loop if EOF is encountered
        }
    }

    return 0;
}
