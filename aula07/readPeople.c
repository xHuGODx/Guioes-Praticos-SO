#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

typedef struct
{
    int age;
    double height;
    char name[64];
} Person;

void printPersonInfo(Person *p)
{
    printf("Person: %s, %d, %f\n", p->name, p->age, p->height);
}

int main (int argc, char *argv[])
{
    FILE *fp = NULL;
    Person p;
    int k;
    int i;
    int feedback;

    /* Validate number of arguments */
    if(argc != 2)
    {
        printf("USAGE: %s fileName\n", argv[0]);
        return EXIT_FAILURE;
    }

    /* Open the file provided as argument */
    errno = 0;
    fp = fopen(argv[1], "rb+");
    if(fp == NULL)
    {
        perror ("Error opening file!");
        return EXIT_FAILURE;
    }

    /* read all the itens of the file */
    while(fread(&p, sizeof(Person), 1, fp) == 1)
    {
        printPersonInfo(&p);
    }

    
    printf("Do you want to add people? (0 to no , 1 to yes)");
    scanf("%d", &feedback);

    if(feedback == 1){
        /*Asks the user how many people*/
        printf("How many people do you want to write? ");
        scanf("%d", &i);

        /* Write i itens on a file */
        for(k = 0 ; k < i ; k++)
        {   
            Person p; 
            printf("Name: ");
            scanf("%s", p.name);
            printf("Age: ");
            scanf("%d", &p.age);
            printf("Height: ");
            scanf("%lf", &p.height);
            fwrite(&p, sizeof(Person), 1, fp);
        }
    }


    fclose(fp);

    return EXIT_SUCCESS;
}
