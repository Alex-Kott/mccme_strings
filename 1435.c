#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <malloc.h>


bool is_digit_or_point(char c);
void empty(char* STR);

int main(void)
{
    FILE* fp;
    char *STR = NULL, *OCTET;
    size_t len = 0;
    int i, j, n;

    fp = fopen("input.txt", "r");

    getline(&STR, &len, fp);
    fclose(fp);

    OCTET = calloc(strlen(STR), sizeof(char));
    for (i = 0, j = 0; i < strlen(STR); i++)
    {
        if (!is_digit_or_point(STR[i]))
        {
            printf("0");
            return 0;
        }
        if (STR[i] == '\n')
        {

            break;
        }
        if (STR[i] == '.')
        {
            if (strlen(OCTET) == 0)
            {
                printf("0");
                return 0;
            }
            OCTET[j + 1] = '\0';
            n = (int)strtol(OCTET, (char**)NULL, 10);
            if (n > 255)
            {
                printf("0");
                return 0;
            }
            j = 0;
            empty(OCTET);
        }
        else
        {
            OCTET[j] = STR[i];
            j++;
        }
    }

    if (strlen(OCTET) == 0)
    {
        printf("0");
        return 0;
    }


    printf("1");

    return 0;
}

bool is_digit_or_point(char c)
{
    if (c == '.')
    {
        return true;
    }
    if (c == '\n')
    {
        return true;
    }
    if (c == '\0')
    {
        return true;
    }
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