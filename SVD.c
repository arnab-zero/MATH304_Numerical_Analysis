#include <stdio.h>
#include <math.h>

#define M 1000  // maximum number of rows
#define N 1000  // maximum number of columns

void svd_jacobi(double A[][N], int m, int n, double U[][N], double S[], double V[][N]) {
    int i, j, k, p, q;
    double c, s, t, r, f, g, h;

    // Initialize U and V to identity matrices
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (i == j) {
                U[i][j] = 1.0;
                V[i][j] = 1.0;
            } else {
                U[i][j] = 0.0;
                V[i][j] = 0.0;
            }
        }
    }

    // Initialize S to the diagonal of A'A
    double AtA[N][N];
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            AtA[i][j] = 0.0;
            for (k = 0; k < m; k++) {
                AtA[i][j] += A[k][i] * A[k][j];
            }
        }
        S[i] = AtA[i][i];
    }

    // Perform Jacobi iteration until convergence
    int iter, max_iter = 1000;
    double eps = 1e-10;
    for (iter = 0; iter < max_iter; iter++) {
        double max_offdiag = 0.0;
        for (p = 0; p < n-1; p++) {
            for (q = p+1; q < n; q++) {
                if (fabs(AtA[p][q]) > max_offdiag) {
                    max_offdiag = fabs(AtA[p][q]);
                }
            }
        }
        if (max_offdiag < eps) {
            break;
        }
        for (p = 0; p < n-1; p++) {
            for (q = p+1; q < n; q++) {
                if (fabs(AtA[p][q]) > eps * max_offdiag) {
                    double theta = (AtA[q][q] - AtA[p][p]) / (2.0 * AtA[p][q]);
                    double t = 1.0 / (fabs(theta) + sqrt(1.0 + theta * theta));
                    if (theta < 0.0) {
                        t = -t;
                    }
                    c = 1.0 / sqrt(1.0 + t * t);
                    s = t * c;
                    r = s / (1.0 + c);
                    for (i = 0; i < n; i++) {
                        if (i != p && i != q) {
                            f = AtA[p][i];
                            g = AtA[q][i];
                            AtA[p][i] = f - s * (g + f * r);
                            AtA[q][i] = g + s * (f - g * r);
                        }
                    }
                    for (j = 0; j < n; j++) {
                        if (j != p && j != q) {
                            f = AtA[j][p];
                            g = AtA[j][q];
                            AtA[j][p] = f - s * (g + f * r);
                            AtA[j][q] = g + s * (f - g * r);
                        }
                    }
                    for (i = 0; i < m; i++) {
                        f = A[i][p];
                        g = A[i][q];
                        A[i][p] = f - s * (g + f * r);
                        A[i][q] = g + s * (f - g * r);
                    }
                    for (i = 0; i < m; i++) {
                        f = U[i][p];
                        g = U[i][q];
                        U[i][p] = f - s * (g + f * r);
                        U[i][q] = g + s * (f - g * r);
                    }
                }
            }
        }
    }

    // Sort singular values and adjust signs of corresponding columns of U and V
    for (i = 0; i < n-1; i++) {
        int max_idx = i;
        double max_val = S[i];
        for (j = i+1; j < n; j++) {
            if (S[j] > max_val) {
                max_idx = j;
                max_val = S[j];
            }
        }
        if (max_idx != i) {
            S[max_idx] = S[i];
            S[i] = max_val;
            for (k = 0; k < m; k++) {
                t = U[k][i];
                U[k][i] = U[k][max_idx];
                U[k][max_idx] = t;
            }
            for (k = 0; k < n; k++) {
                t = V[k][i];
                V[k][i] = V[k][max_idx];
                V[k][max_idx] = t;
            }
        }
        if (S[i] < 0.0) {
            S[i] = -S[i];
            for (j = 0; j < n; j++) {
                V[j][i] = -V[j][i];
            }
        }
    }
    if (S[n-1] < 0.0) {
        S[n-1] = -S[n-1];
        for (j = 0; j < n; j++) {
            V[j][n-1] = -V[j][n-1];
        }
    }
}


int main() {

    freopen("SVD_input.txt", "r", stdin);
    freopen("SVD_output.txt", "w", stdout);

    int m, n, i, j;
    double A[M][N], U[M][N], S[N], V[N][N];
    
    // Read matrix dimensions from user input
    printf("Enter number of rows: ");
    scanf("%d", &m);
    printf("Enter number of columns: ");
    scanf("%d", &n);

    if(m <= n){
        printf("The given matrix isn't a tall matrix.\n");
        return 0;
    }

    // Read matrix values from user input
    printf("Enter matrix values:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%lf", &A[i][j]);
        }
    }

    // Compute SVD using Jacobi iteration method
    svd_jacobi(A, m, n, U, S, V);

    // Print results
    printf("Singular values:\n");
    for (i = 0; i < n; i++) {
        printf("%f\n", S[i]);
    }

    printf("Matrix U:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("%f ", U[i][j]);
        }
        printf("\n");
    }

    printf("Matrix V:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%f ", V[i][j]);
        }
        printf("\n");
    }

    return 0;
}


