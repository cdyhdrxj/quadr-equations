#include <stdio.h>
#include <float.h>
#include "func.h"

int main() {
    roots res = quadr_equation(1, 1, 1);
    return res.num;
}
