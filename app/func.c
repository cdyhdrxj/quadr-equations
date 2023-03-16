#include <stdio.h>
#include <math.h>
#include <float.h>
#include "func.h"

roots quadr_equation(double a, double b, double c) {
    roots result;
    result.first = NAN;
    result.second = NAN;

    if (a == 0) {
        if (b == 0) {
            if (c == 0)
                result.num = 3; // Бесконечное количество решений: num > 2.
            else
                result.num = 0;
        }
        else {
            result.num = 1;
            result.first = -c / b;
            result.second = -c / b;
        }

        return result;
    }

    result.num = -1; // Переполнение: num == -1.

    if (fabs(b) > DBL_MAX / fabs(b))
        return result;

    if (fabs(a) > DBL_MAX / fabs(c))
        return result;

    if (fabs(a*c) > DBL_MAX / 4)
        return result;

    if ((4*a*c < 0) && (b*b > DBL_MAX + 4*a*c))
        return result;

    if (b*b < 4*a*c) {
        result.num = 0;
        return result;
    }

    double sqrt_discr = sqrt(b*b - 4*a*c);

    if (fabs(a) < 1 && fabs((-b - sqrt_discr) / 2) > DBL_MAX*fabs(a))
        return result;

    if (fabs(a) < 1 && fabs((-b + sqrt_discr) / 2) > DBL_MAX*fabs(a))
        return result;

    double x1 = (-b - sqrt_discr) / (2*a);
    double x2 = (-b + sqrt_discr) / (2*a);

    if (sqrt_discr == 0)
        result.num = 1;
    else
        result.num = 2;

    if (x2 > x1) {
        result.first = x1;
        result.second = x2;
    }
    else {
        result.first = x2;
        result.second = x1;
    }

    return result;
}
