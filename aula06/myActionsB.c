#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, char *argv[])
{
    char text[1024];
    FILE *file;
    time_t rawtime;
    struct tm * timeinfo;
    char buffer[80];

    file = fopen("command.log", "a");
    if (file == NULL) {
        printf("Could not open file command.log\n");
        return EXIT_FAILURE;
    }

    do
    {
        printf("Command: ");
        scanf("%1023[^\n]%*c", text);

        time(&rawtime);
        timeinfo = localtime(&rawtime);
        strftime(buffer, sizeof(buffer),"%d-%m-%Y %H:%M:%S", timeinfo);
        fprintf(file, "%s: %s\n", buffer, text);

        if(strcmp(text, "end")) {
           printf("\n * Command to be executed: %s\n", text);
           printf("---------------------------------\n");
           system(text);
           printf("---------------------------------\n");
        }
    } while(strcmp(text, "end"));

    fclose(file);

    printf("-----------The End---------------\n");

    return EXIT_SUCCESS;
}