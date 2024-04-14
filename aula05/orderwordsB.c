#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 100

int compare_asc(const void * a, const void * b) {
    return strcasecmp(*(const char**)a, *(const char**)b);
}

int compare_desc(const void * a, const void * b) {
    return strcasecmp(*(const char**)b, *(const char**)a);
}

int main() {
    char words[MAX_WORDS][MAX_WORD_LENGTH]; // Array to hold the words
    int count = 0; // Count of words

    printf("Enter words (empty line to stop):\n");

    while(count < MAX_WORDS && fgets(words[count], MAX_WORD_LENGTH, stdin) != NULL) {
        if(words[count][0] == '\n') { // Stop if the line is empty
            break;
        }
        words[count][strcspn(words[count], "\n")] = '\0'; // Remove the newline character
        count++;
    }

    char *sortorder = getenv("SORTORDER"); // Get the SORTORDER environment variable

    if(sortorder != NULL && strcmp(sortorder, "DESC") == 0) {
        qsort(words, count, sizeof(words[0]), compare_desc); // Sort the words in descending order
    } else {
        qsort(words, count, sizeof(words[0]), compare_asc); // Sort the words in ascending order
    }

    printf("Sorted words:\n");
    for(int i = 0; i < count; i++) {
        printf("%s\n", words[i]); // Print each word
    }

    return 0;
}