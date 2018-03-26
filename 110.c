#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


int main(void)
{
    FILE* fp;
    char* STR = NULL;
    char* SUBSTR = NULL;
    size_t len = 0;
    int i = 0, j = 0;
    bool is_substr;

    fp = fopen("input.txt", "r");

    getline(&SUBSTR, &len, fp);
    getline(&STR, &len, fp);

    fclose(fp);

    is_substr = false;
    while (STR[i] != '\0')
    {
        j = 0;
        while (SUBSTR[j] != '\n')
        {
            if (SUBSTR[j] != STR[i + j])
            {
                break;
            }

            if (SUBSTR[j + 1] == '\n')
            {
                is_substr = true;
                break;
            }
            j++;
        };

        if (is_substr == true)
        {
            break;
        }

        i++;
    }

    if (is_substr == true)
    {
        printf("yes");
    }
    else
    {
        printf("no");
    }

    free(STR);
    free(SUBSTR);

    return 0;
}