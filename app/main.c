#include <stdio.h>
#include <float.h>
#include "func.h"

int main() {
    roots res = quadr_equation(1, 1, 1);
    if (res.num == -1)
        printf("Overflow\n");
    else {
        if (res.num == 0)
            printf("No solutions\n");
        else
            printf("%lf %lf\n", res.first, res.second);
    }
    return 0;
}
