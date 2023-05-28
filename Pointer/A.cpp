#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
typedef long long int lli;

int main(void){

    int* p, q;
    int r;

    *p = 1;
    r = 1;

    printf("Value: %d\n", *p);
    printf("Value: %d\n", &r);

    p = &r;

    printf("Value: %d\n", *p);

}