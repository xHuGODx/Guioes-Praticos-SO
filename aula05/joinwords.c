#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
    if(argc < 2){
        printf("Please provide at least one argument\n");
        return 1;
    }

    int sizeneeded = argc - 1;
    for(int i = 1; i < argc; i++) {
        sizeneeded += strlen(argv[i]);
    }
    char buffer[sizeneeded]; // Buffer to hold the joined words

    for(int i = 1; i < argc; i++) {
        strcat(buffer, argv[i]); // Append each argument to the buffer
        strcat(buffer, " "); // Add a space between words
    }

    printf("%s\n", buffer); // Print the joined words

    return 0;
}