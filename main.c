#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - Entry Point
 *
 * Return: Always 0
 */

int main(void) {
    const char *BACKUP_DIRECTORY = "/home/briane/Backup";
    time_t current;
    time(&current);

    char file_name[50];
    sprintf(file_name, "archive-%ld.tar", current);

    char command_str[100];
    sprintf(command_str, "tar -cvf %s /home/briane/Downloads/*", file_name);

    int status = system(command_str);
    if(status == 1){
        printf("something went wrong with zipping files \n");
        return 1;
    }

    char command_move[100];
    sprintf(command_move, "mv ./%s %s", file_name, BACKUP_DIRECTORY);

    int move_status = system(command_move);
    if(move_status == 1){
        printf("something went wrong with moving file \n");
        return 1;
    }

    int delete_status = system("rm -r /home/briane/Downloads/*");
    if(delete_status == 1){ 
        printf("something went wrong with clearing directory \n");
        return 1;
    }

    printf("Backup Complete");
    return 0;
}
