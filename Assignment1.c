#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// f(x) = c1 + c2*x + c3*(x^2) + c4*(x^3)

int n;      // number of input x's and f(x)'s

// Function to find a transpose matrix of a given matrix
void find_transpose_mat(double coefficient_mat[][4], double transpose_mat[][n]){

    for(int i=0; i<n; ++i){
        for(int j=0; j<4; ++j){
            transpose_mat[j][i] = coefficient_mat[i][j];
        }
    }
}

int main(void){

    // freopen("Assignment1_input.txt", "r", stdin);
    // freopen("Assignment1_output.txt", "w", stdout);

    printf("Enter number of values for x: ");
    scanf("%d", &n);       // how many sample x 


    // constructing the coefficient matrix and a vector from f(x)
    double coefficient_mat[n][4], fx_vector[n];

    printf("Enter input x's and f(x)'s: ");
    for(int i=0; i<n; ++i){
        double x;
        scanf("%lf%lf", &x, &fx_vector[i]);

        coefficient_mat[i][0] = 1;
        coefficient_mat[i][1] = x;
        coefficient_mat[i][2] = x*x;
        coefficient_mat[i][3] = x*x*x;
    }

    printf("\nThe co-efficient matrix: \n");
    for(int i=0; i<n; ++i){
        for(int j=0; j<4; ++j){
            printf("%lf ", coefficient_mat[i][j]);
        }
        printf("\n");
    }

    printf("\nInput vector for f(x): \n");
    for(int i=0; i<n; ++i){
        printf("%lf\n", fx_vector[i]);
    }


    // calculating transpose matrix of the coefficient matrix
    double transpose_mat[4][n];         // transpose matrix of coefficient matrix
    find_transpose_mat(coefficient_mat, transpose_mat);

    printf("\nTranspose matrix of the found coefficient matrix: \n");
    for(int i=0; i<4; ++i){
        for(int j=0; j<n; ++j){
            printf("%lf ", transpose_mat[i][j]);
        }
        printf("\n");
    }


    // Multiplying the transpose matrix with the coefficient matrix and the vector
    double res_mat[4][4], res_vector[4];
    
    for(int i=0; i<4; ++i){
        for(int j=0; j<n; ++j){
            double sum = 0.00;
            for(int p=0; p<n; ++p){
                sum += transpose_mat[i][p]*coefficient_mat[p][j];
            }
            res_mat[i][j] = sum;
        }
    }

    for(int i=0; i<4; ++i){
        double sum = 0.0;
        for(int j=0; j<n; ++j){
            sum += transpose_mat[i][j]*fx_vector[j];
        }
        res_vector[i] = sum;
    }

    printf("\nProduct of transpose and coefficient matrix: \n");
    for(int i=0; i<4; ++i){
        for(int j=0; j<4; ++j){
            printf("%lf ", res_mat[i][j]);
        }
        printf("\n");
    }

    printf("\nProduct of transpose matrix and vector: \n");
    for(int i=0; i<4; ++i){
        printf("%lf\n", res_vector[i]);
    }

    // Transforming the augmented matrix into a upper triangular matrix using gaussian elimination
    for(int i=1; i<4; ++i){
        double q = res_mat[0][0]/res_mat[i][0]; 
        for(int j=0; j<4; ++j){
            res_mat[i][j] *= q;
        }
        res_vector[i] *= q;

        for(int j=0; j<4; ++j){
            res_mat[i][j] -= res_mat[0][j];
        }
        res_vector[i] -= res_vector[0];
    }

    for(int i=2; i<4; ++i){
        double q = res_mat[1][1]/res_mat[i][1];
        for(int j=1; j<4; ++j){
            res_mat[i][j] *= q;
        }
        res_vector[i] *= q;

        for(int j=1; j<4; ++j){
            res_mat[i][j] -= res_mat[1][j];
        }
        res_vector[i] -= res_vector[1];
    }
    
    for(int i=3; i<4; ++i){
        double q = res_mat[2][2]/res_mat[i][2];
        for(int j=2; j<4; ++j){
            res_mat[i][j] *= q;
        }
        res_vector[i] *= q;
        
        for(int j=2; j<4; ++j){
            res_mat[i][j] -= res_mat[2][j];
        }
        res_vector[i] -= res_vector[2];
    }

    // printing the upper-triangular matrix
    printf("\nUpper-triangular augmented matrix: \n");
    for(int i=0; i<4; ++i){
        for(int j=0; j<4; ++j){
            printf("%lf ", res_mat[i][j]);
        }
        printf("\t");
        printf("%lf\n", res_vector[i]);
    }

    // Solution for the unknowns
    double c4 = res_vector[3]/res_mat[3][3];
    double c3 = (res_vector[2]-c4*res_mat[2][3])/res_mat[2][2];
    double c2 = (res_vector[1]-c4*res_mat[1][3]-c3*res_mat[1][2])/res_mat[1][1];
    double c1 = (res_vector[0]-c4*res_mat[0][3]-c3*res_mat[0][2]-c2*res_mat[0][1])/res_mat[0][0];

    printf("\nSolutions:\n");
    printf("c1 = %lf\nc2 = %lf\nc3 = %lf\nc4 = %lf\n", c1, c2, c3, c4);

    printf("\nThe cubic polynomial would be:: f(x) = %lf + %lf*x + %lf*(x^2) + %lf*(x^3)\n", c1, c2, c3, c4);

    return 0;
}