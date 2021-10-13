#include "mathlib.h"

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>
#define OPTIONS "asctl"

void print_header(char *function) {
    printf("  x            %s           Library        Difference\n", function);
    printf("  -            ------           -------        ----------\n");
}

int main(int argc, char **argv) {
    int opt = 0;
    bool got_s = false;
    bool got_c = false;
    bool got_t = false;
    bool got_l = false;

    while ((opt = getopt(argc, argv, OPTIONS)) != -1) {
        switch (opt) {
        case 'a': got_s = got_c = got_t = got_l = true; break;
        case 's': got_s = true; break;
        case 'c': got_c = true; break;
        case 't': got_t = true; break;
        case 'l': got_l = true; break;
        default: return 1;
        }
    }

    if (got_s) {
        print_header("arcSin");
        for (double i = -1.0; i <= 1.0; i += 0.1) {
            printf(" %7.4lf % 16.8lf % 16.8lf % 16.10lf\n", i, arcSin(i), asin(i),
                (arcSin(i) - asin(i)));
        }
    }
    if (got_c) {
        print_header("arcCos");
        for (double i = -1.0; i <= 1.0; i += 0.1) {
            printf(" %7.4lf % 16.8lf % 16.8lf % 16.10lf\n", i, arcCos(i), acos(i),
                (arcCos(i) - acos(i)));
        }
    }
    if (got_t) {
        print_header("arcTan");
        for (double i = 1.0; i <= 10.0; i += 0.1) {
            printf(" %7.4lf % 16.8lf % 16.8lf % 16.10lf\n", i, arcTan(i), atan(i),
                (arcTan(i) - atan(i)));
        }
    }
    if (got_l) {
        printf("  x            Log              Library        Difference\n");
        printf("  -            ------           -------        ----------\n");
        for (double i = 1.0; i <= 10.0; i += 0.1) {
            printf(" %7.4lf % 16.8lf % 16.8lf % 16.10lf\n", i, Log(i), log(i), (Log(i) - log(i)));
        }
    }

    return 0;
}
