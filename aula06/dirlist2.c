#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

void listDir(char dirname[])
{
    DIR *dp; 
    struct dirent *dent;
    struct stat st;
    char path[1024];

    dp = opendir(dirname); 
    if(dp == NULL)
    {
        perror("Error opening directory");
        return;
    }

    dent = readdir(dp);
    while(dent!=NULL) 
    {
        if(dent->d_name[0] != '.') /* do not list hidden dirs/files */
        {
            snprintf(path, sizeof(path), "%s/%s", dirname, dent->d_name);
            if (stat(path, &st) == 0 && S_ISDIR(st.st_mode))
                printf("d %s\n", path);
            else
                printf("  %s\n", path);
        }

        dent = readdir(dp);
    }
}

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        fprintf(stderr,"Usage: %s base_directory\n",argv[0]);
        return EXIT_FAILURE;
    }

    listDir(argv[1]);
    
    return EXIT_SUCCESS;
}