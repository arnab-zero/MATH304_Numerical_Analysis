#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
typedef long long int lli;

int main(void){

    FILE* fp;

    fp = fopen("CSVoutput.csv", "w");

    if(fp == NULL){
        printf("File not found.");
        exit(1);
    }

    fprintf(fp, "a,b,a*b\n");

    for(int i=0; i<10; ++i){
        fprintf(fp, "%d,%d,%d\n", i, 2, i*2);
    }

    fclose(fp);

    return 0;
}