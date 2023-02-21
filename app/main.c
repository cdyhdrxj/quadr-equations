#include <stdio.h>

#include "func.h"

int main() {
    roots res = quadr_equation(1, 1, -1);
    printf("%lf %lf\n", res.first, res.second);
	return 0;
}
