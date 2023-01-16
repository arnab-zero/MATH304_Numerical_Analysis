#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define F(x) (x*x - 5*x + 6)
#define dF(x) (2*x - 5)
#define initialGuess 1.0
#define tol 1e-20

int main(void){
    double x1 = initialGuess, fx1 = F(x1), x2;

    for(int i=0; i<10; ++i){
        x2 = x1 - F(x1)/dF(x1);
        double fx2 = F(x2);

        printf("itr: %d\t\tprevx: %lf\t\tnewx: %lf\t\tprevF: %lf\t\tnewF: %lf\t\tdifference: %lf\t\t", i+1, x1, x2, F(x1), F(x2), fabs(fx1-fx2));
        printf("\n");

        if(fabs(fx1-fx2) < tol)
        {
            printf("Root to the equation: %lf", x2);
            return 0;
        }

        x1 = x2, fx1 = fx2;
    }

    return 0;
}

