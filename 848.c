#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <malloc.h>


bool is_digit(char c);
void empty(char* STR);

int main(void)
{
    FILE* fp;
    char *STR = NULL, *BFR;
    size_t len = 0;
    int i, j, n;

    fp = fopen("input.txt", "r");

    getline(&STR, &len, fp);

    fclose(fp);

    BFR = calloc(strlen(STR), sizeof(char));

    for (i = 0, j = 0; i <= strlen(STR); i++)
    {
        if (is_digit(STR[i]))
        {
            BFR[j] = STR[i];
            j++;
        }
        else
        {
            n = (int)strtol(BFR, (char**)NULL, 10);
            if (n > 5)
            {
                printf("NO");
                return 0;
            }

            empty(BFR);
            j = 0;
        }
    }

    printf("YES");

    return 0;
}

bool is_digit(char c)
{
    if (((int)c > 47) && ((int)c < 58))
    {
        return true;
    }
    return false;
}


void empty(char* STR)
{
    memset(STR, 0, strlen(STR) * sizeof(char));
}