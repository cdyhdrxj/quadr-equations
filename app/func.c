#include <stdio.h>
#include <math.h>
#include "func.h"

roots quadr_equation(double a, double b, double c) {
    roots result;
    if (a == 0) {
        if (b == 0) {
            if (c == 0) {
                /* Бесконечное количество решений */
                result.first = INFINITY;
                result.second = INFINITY;
            }
            else {
                /* Нет решений */
                result.first = NAN;
                result.second = NAN;
            }
        }
        else {
            if (c == 0) {
                result.first = 0;
                result.second = 0;
            }
            else {
                result.first = -c / b;
                result.second = -c / b;
            }
        }
    }
    else {
        double discr = b*b - 4*a*c;
        if (discr >= 0) {
            double sqrt_discr = sqrt(discr);
            double x1 = (-b - sqrt_discr) / (2*a);
            double x2 = (-b + sqrt_discr) / (2*a);

            if (x2 > x1) {
                result.first = x1;
                result.second = x2;
            }
            else {
                result.first = x2;
                result.second = x1;
            }
        }
        else {
            result.first = NAN;
            result.second = NAN;
        }
    }

    return result;
}
