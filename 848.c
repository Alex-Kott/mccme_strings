#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <malloc.h>

// char* clear(char* STR){
//     STR[0] = '\0';
//     return STR;
// }

bool is_digit(char c){
    if(((int)c>47) && ((int)c < 58)){
        return true;
    }
    return false;
}

char* clear(char* STR){
    STR[0] = '\0';
    for(int i=0;i<strlen(STR);i++){
        STR[i]='\0';
    }

    return STR;
}

int main(void)
{
    FILE* fp;
    char* STR = NULL;
    size_t len = 0;
    int i, j;

    fp = fopen("input.txt", "r");

    getline(&STR, &len, fp);

    fclose(fp);

    char* BUFFER = calloc(strlen(STR), sizeof(char));
    for(i=0, j=0;i<=strlen(STR);i++){
        if(is_digit(STR[i])){
            // printf("%c", STR[i]);
            BUFFER[j]=STR[i];
            j++;
        }else{
            printf("%s\n", BUFFER);
            BUFFER = clear(BUFFER);
            // printf("%s\n", BUFFER);
            j=0;

        }
    }

    return 0;
}

