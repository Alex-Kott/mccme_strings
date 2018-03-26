#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


char* filter_vowels(char* RAW_STR);
bool is_consonant(char s);

int main(void)
{
    FILE* fp;
    char *STR = NULL, *RAW_STR;
    size_t len = 0;
    int i, j, l;
    bool f;

    fp = fopen("input.txt", "r");

    getline(&RAW_STR, &len, fp);

    fclose(fp);
    STR = filter_vowels(RAW_STR);
    l = strlen(STR);
    for (i = 0; i <= strlen(STR); i++)
    {
        if (STR[i] != STR[l - i - 1])
        {
            printf("NO");
            return 0;
        }
    }

    free(STR);
    printf("YES");

    return 0;
}

bool is_consonant(char s)
{
    int i, len;
    int consonants[20] = { 98, 99, 100, 102, 103, 104, 106, 107, 108, 109, 110, 112, 113, 114, 115,
        116, 118, 119, 120, 122 };
    len = sizeof(consonants) / sizeof(int);
    for (i = 0; i < len; i++)
    {
        if ((int)s == consonants[i])
        {
            return true;
        }
    }
    return false;
}

char* filter_vowels(char* RAW_STR)
{
    int i, j;
    char* STR = RAW_STR;
    for (i = 0, j = 0; i < strlen(RAW_STR); i++, j++)
    {
        if (is_consonant(RAW_STR[i]))
        {
            STR[j] = RAW_STR[i];
        }
        else
        {
            j--;
        }
    }
    STR[j] = '\0';

    return STR;
}