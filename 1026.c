#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <malloc.h>

void empty(char *STR);
int calc(char *MNML, int x);
bool is_digit(char c);

int main(void)
{
    FILE* fp;
    char *STR, *MNML; // monomial
    size_t len = 0;
    int i, j, x, res;
    char sign;

    fp = fopen("input.txt", "r");

    getline(&STR, &len, fp);
    fscanf(fp, "%d\n", &x);
    fclose(fp);


    MNML = calloc(10, sizeof(char));

    for(i=0, res=0, j++;i<strlen(STR);i++){
        if(STR[i] == '+' || STR[i] == '-'){
            MNML[j] = '\0';

            if(sign == '+'){
                res = res + calc(MNML, x);
            }else{
                res = res - calc(MNML, x);
            }

            sign = STR[i];
            j=0;
            empty(MNML);

        } else {
            MNML[j] = STR[i];
            j++;

        }
    }

    // printf("%i\n", res);
    return 0;
}


void empty(char* STR)
{
    memset(STR, 0, strlen(STR) * sizeof(char));
}

int calc(char *MNML, int x){
    if(strlen(MNML) == 0){
        return 0;
    }

    int i, j, n=1, p;

    printf("%s ", MNML);
    char *N = calloc(5, sizeof(char));
    char *PWR = calloc(5, sizeof(char));
    bool flag = true;
    for(i=0, j=0; i<strlen(MNML); i++){
        if(is_digit(MNML[i])){
            if(flag == true){
                N[j]=MNML[i];    
            }else{
                PWR[j]=MNML[i];
            }
            j++;
            
        }else{
            N[j] = '\0';
            // printf("%s\n", N);
            if(flag){
                n = (int)strtol(N, (char**)NULL, 10);
            }

            flag = false;
            j=0;
        }
    }
    // if(flag==true){
    //     printf("%i\n", n);
    //     return n;
    // }
    printf("%i\n", n);
    empty(N);
    empty(PWR);
    return 1;
}

bool is_digit(char c)
{
    if (((int)c > 47) && ((int)c < 58))
    {
        return true;
    }
    return false;
}