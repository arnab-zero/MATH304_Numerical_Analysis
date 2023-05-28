#include <stdio.h>
#include <math.h>
typedef long long int lli;

int row_a, col_a, row_b, col_b;

void matrix_product(double mat_a[][col_a], double mat_b[][col_b], double res_mat[][col_b])
{

    if(col_a != row_b){
        printf("matrix product calculation not possible. ");
        return;
    }

    for(int i=0; i<row_a; ++i){
        for(int j=0; j<col_a; ++j){
            double sum = 0.00;
            for(int p=0, q=0; p<col_a; ++p, ++q){
                sum += mat_a[i][p]*mat_b[q][j];
            }
            res_mat[i][j] = sum;
        }
    }

}

int main(void){

    printf("Enter row and column counts of matrix a: ");
    scanf("%d%d", &row_a, &col_a);

    printf("Enter row and column counts of matrix b: ");
    scanf("%d%d", &row_b, &col_b);

    double mat_a[row_a][col_a], mat_b[row_b][col_b];

    printf("Enter first matrix: \n");
    for(int i=0; i<row_a; ++i){
        for(int j=0; j<col_a; ++j){
            scanf("%lf", &mat_a[i][j]);
        }
    }

    printf("Enter first matrix: \n");
    for(int i=0; i<row_b; ++i){
        for(int j=0; j<col_b; ++j){
            scanf("%lf", &mat_b[i][j]);
        }
    }

    double res_mat[row_a][col_b];

    matrix_product (mat_a, mat_b, res_mat);

    for(int i=0; i<row_a; ++i){
        for(int j=0; j<col_b; ++j){
            printf("%lf ", res_mat[i][j]);
        }
        printf("\n");
    }

    return 0;
}