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
    bool f;

    fp = fopen("input.txt", "r");

    getline(&STR, &len, fp);

    fclose(fp);

    f = false;

    for (i = 0; i < strlen(STR); i++)
    {
        if (STR[i] == '\n')
        {
            continue;
        }
        if (STR[i] == ' ')
        {

            j = i;
            f = true;
            continue;
        }
        if (f == true)
        {
            printf("%c", STR[i]);
        }
    }

    printf(" ");
    for (i = 0; i < j; i++)
    {
        printf("%c", STR[i]);
    }

    free(STR);

    return 0;
}
