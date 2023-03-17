#ifndef FUNC_H
#define FUNC_H

typedef struct _roots {
    int num;        // Количество корней уравнения
    double first;   // Меньший корень.
    double second;  // Больший корень.
} roots;

roots quadr_equation(double a, double b, double c);

#endif // FUNC_H
