#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <malloc.h>

int count_symbol(char* STR, char s);

int main(void)
{
    FILE* fp;
    char* STR = NULL;
    size_t len = 0;
    int i, l;

    fp = fopen("input.txt", "r");

    getline(&STR, &len, fp);

    fclose(fp);

    for (i = 0; i < strlen(STR); i++)
    {
        if (count_symbol(STR, STR[i]) > 1)
        {
            printf("%c", STR[i]);
            free(STR);
            return 0;
        }
    }

    return 0;
}

int count_symbol(char* STR, char s)
{
    int count = 0, i;
    for (i = 0; i < strlen(STR); i++)
    {
        if (STR[i] == s)
        {
            count++;
        }
    }

    return count;
}