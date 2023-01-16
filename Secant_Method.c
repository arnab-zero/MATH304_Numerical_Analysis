#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define F(x) x*x -8*x + 14
#define point1 2.0
#define point2 3.0
#define tol 1e-25
#define maxIteration 15

int main(void){
    double x1 = point1, fx1 = F(x1), x2 = point2, fx2 = F(x2), x3, fx3;

    for(int i=1; i<maxIteration; ++i){
        x3 = ((fx2*x1-fx1*x2)/(fx2-fx1)); 
        fx3 = F(x3);

        printf("itr-%d\t\tx1=%lf\t\tf(x1)=%lf\t\tx2=%lf\t\tf(x2)=%lf\t\tx3=%lf\t\tx3-x2=%lf\n", i, x1, fx1, x2, fx2, x3, fabs(fx2-fx3));

        if(fabs(fx2-fx3) < tol)
        {
            printf("Root of the equation is %.20lf", x3);
            return 0;
        }

        x1 = x2, fx1 = fx2, x2 = x3, fx2 = fx3;
    }

    printf("\nThis equation may not have a real solution.");
    
    return 0;
}

