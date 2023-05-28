/*

## Algorithm:
1. Given f(x) = 0, transform it to the form x = g(x).
2. Pick a x(sub(1)) and plug it into right side of equation.
3. Repeat x(sub(i+1)) = g(x(sub(i))) until converges.

## Convergence: Means the decreasing of error e. If |g'(root)| < 1, then the x = g(x) converges with every
iteration. 

## Error tolerance: e = |x(sub(i+1)) - x(sub(i))|

## Newton's Method is a special case of fixed-point iteration.

** Watch fixed-point method related videos from StudySession on YouTube.

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define F(x) (exp(x) - 3*x)
#define g(x) ((1/3)*exp(x))
#define N 100
#define tol 1e-10

int main(void){
    double initialGuess = 0.5, x1 = initialGuess;
    double gx1 = g(x1), x2 = gx1, gx2 = g(x2);

    if(abs((gx2-gx1)/(x2-x1)) >= 1){
        printf("The function is not converging.");
        return 0;
    }

    for(int i=0; i<N; ++i)
    {
        if(abs(x2-x1) < tol){
            printf("Root to the equation: %lf", x2);
            return 0;
        }

        x1 = x2;
        x2 = g(x1);
    }

}
