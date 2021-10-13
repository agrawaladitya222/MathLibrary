#include "mathlib.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

const double epsilon = 1E-10;

double Abs(double x) { //Absolute value function
    if (x > 0) {
        return x;
    } else {
        return -x;
    }
}

double Sqrt(double x) { //Square root function from Prof. Long posted on Piazza
    double new = 1.0;
    double old = 0.0;
    while (Abs(new - old) > epsilon) {
        old = new;
        new = 0.5 * (new + x / new);
    }
    return new;
}

double Exp(double x) { //exp() function from piazza
    double term = 1, sum = 1;
    for (int k = 1; Abs(term) > epsilon; k += 1) {
        term *= x / k;
        sum += term;
    }
    return sum;
}

double arcSin(double x) {
    double old = -5.0;
    double new = x;
    while (Abs(new - old) > epsilon) {
        old = new;
        new = old - ((sin(old) - x) / cos(old));
    }
    return new;
}

double arcCos(double x) {
    double output = M_PI_2;
    output -= arcSin(x);
    return output;
}

double arcTan(double x) {
    double output = x;
    output /= Sqrt(x * x + 1);
    return arcSin(output);
}

double Log(double x) {
    double old = 0.0;
    double new = 1.0;
    while (Abs(new - old) > epsilon) {
        old = new;
        new = old + ((x - Exp(old)) / Exp(old));
    }
    return new;
}
