//C Program that imitates the Unix "ls" command.
//Written by Samer Madieh.

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <dirent.h>
#include <unistd.h>

//Function that lists all files in a given directory.

int listFiles(const char *dir, int testing){

    struct dirent *dr;
    DIR *directory = opendir(dir);

    if(!directory){
        return 0;
    }
    if(testing) {
        return 1;
    }
    else {
        while((dr = readdir(directory)) != NULL){
            if(dr->d_name[0] == '.') continue;
            printf("%s ",dr->d_name);
            printf("\n");
        }
        return 1;
    }
}

//Main function

int main(int argc, char *argv[]){

    char cwd[1024];
    getcwd(cwd, sizeof(cwd));
    printf("\n");

    //Checking the number of arguments to know if we need to print the contents of one or more files.

    if(argc == 1){
        printf("%s\n", cwd);
        listFiles(".", 0);
        printf("\n");
    }

    else if(argc == 2){
        if(listFiles(argv[1], 1) == 0) {
            printf("Cannot access %s\n", argv[1]);
        }
        else {
            printf("%s\n", argv[1]);
            listFiles(argv[1], 0);
        }
        printf("\n");
    }

    else if(argc >= 3){
        for(int i = 1; i < argc; i++) {
            if(listFiles(argv[i], 1) == 1){
                printf("%s\n", argv[i]);
                listFiles(argv[i], 0);
            }
            else {
                printf("Cannot access %s\n", argv[i]);
            }
            printf("\n");
        }
    }

    return 0;
}