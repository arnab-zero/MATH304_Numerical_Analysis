// infinite loop, why?

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define F(x) (cos(x) - 3*x + 5)     // measure x in degree.
#define tol 1e-10


int main(void){
    double a, b, c;
    printf("Enter values of a & b: ");
    scanf("%lf%lf", &a, &b);

    double fa = F(a), fb = F(b);

    if(F(a)*F(b) >= 0){
        printf("Can't initialize false position in the given interval.");
        return 0;
    }

    while(1){
        c = (a*fb-b*fa)/(fb-fa);
        
        double fc = F(c);
        if(b-c < tol)
        {
            printf("Root to the solution: %lf", c);
            return 0;
        }

        if(fa*fc < 0){
            b = c;
            fb = fc;
        }
        else if(fc*fb < 0){
            a = c;
            fa = fc;
        }
    }

}

