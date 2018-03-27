#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <malloc.h>

void empty(char* STR);

int main(void)
{
    FILE* fp;
    char *STR, *BFR;
    size_t len = 0;
    int i, j, m, r;

    fp = fopen("input.txt", "r");

    fscanf(fp, "%d\n", &m);
    getline(&STR, &len, fp);
    fclose(fp);


    j=0;
    r=m;
    BFR = malloc(sizeof(char)*255);
    for(i=0;i<=strlen(STR);i++){
        if(STR[i] != ' ' && STR[i] != '\n'){
            BFR[j] = STR[i];
            j++;

        }else{
            BFR[j] = '\0';
            j=0;
            if(strlen(BFR) <= r){
                printf("%s ", BFR);
                r=r-strlen(BFR)-1;
                
            }else{
                printf("\n");
                printf("%s ", BFR);
                r=m-strlen(BFR)-1;
            }
            
            empty(BFR);
        }

    }


    return 0;
}


void empty(char* STR)
{
    memset(STR, 0, strlen(STR) * sizeof(char));
}