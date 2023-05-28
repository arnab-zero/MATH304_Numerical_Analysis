
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAXROW 3
#define MAXCOL 3
#define PI   3.14159


int main (void) {
  int i, j;
  double A[MAXROW][MAXCOL], b[MAXROW], Ab[MAXROW][MAXCOL+1];
  double K, L;
 
  for (i=0; i< MAXROW; i++) {
    for (j=0; j< MAXCOL; j++) {
      printf("Enter A[%d,%d]: ",i,j);
      scanf("%lf",&A[i][j]);
    }
  }

  for (i=0; i< MAXROW-1; i++) {
    K = A[i][i];
    L = A[i+1][i];
    for (j=i; j< MAXCOL-1; j++) {
      A[i][j]  = K*A[i+1][j] - L*A[i][j] ;
    }
  }
 
 

  for (i=0; i< MAXROW; i++) {
    for (j=0; j< MAXCOL; j++) {
      printf("%9.3lf", A[i][j] );
    }
    printf("\n");
  }

  return EXIT_SUCCESS;
}