#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <malloc.h>


char* despace(char* RAW_STR);

int main(void)
{
    FILE* fp;
    char *RAW_STR = NULL, *STR;
    size_t len = 0;
    int i, l;

    fp = fopen("input.txt", "r");

    getline(&RAW_STR, &len, fp);

    fclose(fp);
    STR = despace(RAW_STR);
    l = strlen(STR);
    for (i = 0; i <= strlen(STR) / 2 + 1; i++)
    {
        if (STR[i] != STR[l - i - 1])
        {
            printf("no");
            return 0;
        }
    }

    printf("yes");

    free(STR);

    return 0;
}

char* despace(char* RAW_STR)
{
    int i, j;
    char* STR = RAW_STR;
    for (i = 0, j = 0; i < strlen(RAW_STR); i++, j++)
    {
        if (RAW_STR[i] != ' ' && RAW_STR[i] != '\n')
        {
            STR[j] = RAW_STR[i];
        }
        else
            j--;
    }
    STR[j] = 0;

    return STR;
}