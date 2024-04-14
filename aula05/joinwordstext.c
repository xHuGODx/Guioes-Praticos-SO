#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char **argv) {
    if(argc < 2){
        printf("Please provide at least one argument\n");
        return 1;
    }

    int sizeneeded = argc - 1;
    for(int i = 1; i < argc; i++) {
        if(isalpha(argv[i][0])) { // Check if the argument starts with a letter
            sizeneeded += strlen(argv[i]);
        }
    }
    char buffer[sizeneeded]; // Buffer to hold the joined words
    buffer[0] = '\0'; // Initialize the buffer

    for(int i = 1; i < argc; i++) {
        if(isalpha(argv[i][0])) { // Check if the argument starts with a letter
            strcat(buffer, argv[i]); // Append each argument to the buffer
            strcat(buffer, " "); // Add a space between words
        }
    }

    printf("%s\n", buffer); // Print the joined words

    return 0;
}