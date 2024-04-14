#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int compare_asc(const void * a, const void * b) {
    return strcasecmp(*(const char**)a, *(const char**)b);
}

int compare_desc(const void * a, const void * b) {
    return strcasecmp(*(const char**)b, *(const char**)a);
}

int main(int argc, char **argv) {
    if(argc < 2){
        printf("Please provide at least one argument\n");
        return 1;
    }

    char *words[argc]; // Array to hold the valid arguments
    int count = 0; // Count of valid arguments

    for(int i = 1; i < argc; i++) {
        if(isalpha(argv[i][0])) { // Check if the argument starts with a letter
            words[count++] = argv[i];
        }
    }

    char *sortorder = getenv("SORTORDER"); // Get the SORTORDER environment variable

    if(sortorder != NULL && strcmp(sortorder, "DESC") == 0) {
        qsort(words, count, sizeof(char*), compare_desc); // Sort the words in descending order
    } else {
        qsort(words, count, sizeof(char*), compare_asc); // Sort the words in ascending order
    }

    for(int i = 0; i < count; i++) {
        printf("%s\n", words[i]); // Print each word
    }

    return 0;
}