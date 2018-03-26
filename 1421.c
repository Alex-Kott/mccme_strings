#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <malloc.h>


int main(void)
{
    FILE* fp;
    char* STR = NULL;
    size_t len = 0;
    int i, j;

    fp = fopen("input.txt", "r");

    getline(&STR, &len, fp);

    fclose(fp);

    for (i = 0, j = 0; i < strlen(STR); i++, j++)
    {
        if (!((STR[i] == ' ') && (STR[i - 1] == ' ')))
        {
            printf("%c", STR[i]);
        }
    }
    STR[j] = '\0';
    free(STR);

    return 0;
}
