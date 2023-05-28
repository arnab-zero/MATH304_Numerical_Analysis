#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
typedef long long int lli;

int a_row, a_col;

void transpose_mat(double mat_a[][a_col], double mat_res[][a_row]){

    for(int i=0; i<a_row; ++i){
        for(int j=0; j<a_col; ++j){
            mat_res[j][i] = mat_a[i][j];
        }
    }
}

int main(void){

    printf("Enter row and column counts for input matrix: ");
    scanf("%d%d", &a_row, &a_col);

    double mat_a[a_row][a_col];

    printf("Enter the matrix: \n");
    for(int i=0; i<a_row; ++i){
        for(int j=0; j<a_col; ++j){
            scanf("%lf", &mat_a[i][j]);
        }
    }

    double mat_res[a_col][a_row];

    transpose_mat(mat_a, mat_res);
    
    for(int i=0; i<a_col; ++i){
        for(int j=0; j<a_row; ++j){
            printf("%lf ", mat_res[i][j]);
        }
        printf("\n");
    }

    return 0;
}