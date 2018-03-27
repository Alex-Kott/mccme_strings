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
    int i, j, max_count;

    fp = fopen("input.txt", "r");

    getline(&STR, &len, fp);
    fclose(fp);

    max_count = 0;
    for (i = 0, j = 0; i < strlen(STR); i++)
    {
        if (STR[i] == '\n')
        {
            break;
        }
        if (STR[i] != ' ')
        {
            j++;
        }
        else
        {

            j = 0;
        }
        if (j > max_count)
        {
            max_count = j;
        }
    }

    printf("%i", max_count);

    return 0;
}
