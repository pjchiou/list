#include "list.h"

#define CMDSIZE 512

void TrimCMD(char *str)
{
    int i = -1;
    while (str[++i] != '\n')
        ;
    str[i] = '\0';
}

int main(){
    record *root = NULL;
    char CMD[CMDSIZE] = {};
    int bContinue = 1;

    do {
        printf(
            "usage:\n"
            "\ta add word to list\n"
            "\td delete word in list\n"
            "\ts search word in list\n"
            "\tq quit\n");

        fgets(CMD, CMDSIZE, stdin);

        switch (*CMD) {
        case ('a'):
            printf("Insert the word:");
            fgets(CMD, CMDSIZE, stdin);
            TrimCMD(CMD);
            insert_sorted(&root, CMD);
            break;
        case ('d'):
            printf("Delete the word:");
            fgets(CMD, CMDSIZE, stdin);
            TrimCMD(CMD);
            delete_node(&root, CMD);
            break;
        case ('s'):
            printf("Search the word:");
            fgets(CMD, CMDSIZE, stdin);
            TrimCMD(CMD);
            search_node(root, CMD);
            break;
        case ('q'):
            bContinue = 0;
            break;
        default:
            printf("Unknown command.");
        }
        output_list(root);
    } while (bContinue);

    free_list(root);
    return(0);
}
