#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
typedef long long int lli;

int main(void){

    int linearEq[3][4];

    printf("Enter values for coefficients of linear equations: \n");
    printf("(e.g. ax+by+cz = d)\n");

    for(int i=0; i<3; ++i){
        printf("Enter coefficients for equation %d: ", i+1);

        for(int j=0; j<4; ++j)
            scanf("%d", &linearEq[i][j]);
    }

    // eq1 = a*eq1 - b*eq0
    int a = linearEq[0][0], b = linearEq[1][0];
    for(int i=0; i<4; ++i){
        linearEq[1][i] = a*linearEq[1][i] - b*linearEq[0][i];
    }

    // eq2 = c*eq2 - d*eq0
    int c = linearEq[0][0], d = linearEq[2][0];
    for(int i=0; i<4; ++i){
        linearEq[2][i] = c*linearEq[2][i] - d*linearEq[0][i];
    }

    // eq2 = e*eq2 - f*eq1
    int e = linearEq[1][1], f = linearEq[2][1];
    for(int i=0; i<4; ++i){
        linearEq[2][i] = e*linearEq[2][i] - f*linearEq[1][i];
    }

    // print the upper triangular form of the augmented matrix
    printf("\nThe upper-triangular augmented matrix: \n");
    for(int i=0; i<3; ++i){
        for(int j=0; j<4; ++j){
            printf("%d ", linearEq[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    float z = linearEq[2][3]/linearEq[2][2];
    float y = (linearEq[1][3]-linearEq[1][2]*z)/linearEq[1][1];
    float x = (linearEq[0][3]-linearEq[0][1]*y-linearEq[0][2]*z)/linearEq[0][0];

    printf("Solutions: \n");
    printf("x = %f\ny = %f\nz = %f", x, y, z);

    return 0;
}