#include <stdio.h>
#include <math.h>
#include <omp.h>

#define NSTEPS 134217728

int main(int argc, char** argv)
{
    long i;
    double dx = 1.0 / NSTEPS;
    double pi = 0.0;
    double x;

    double start_time = omp_get_wtime();

    #pragma omp parallel for private(x) reduction(+ : pi)
    for (i = 0; i < NSTEPS; i++)
    {
        x = (i + 0.5) * dx;
        pi += 1.0 / (1.0 + x * x);
    }

    pi *= 4.0 * dx;
    double run_time = omp_get_wtime() - start_time;
    double ref_pi = 4.0 * atan(1.0);
    printf("pi with %ld steps is %.10f in %.6f seconds (error=%e)\n",
           NSTEPS, pi, run_time, fabs(ref_pi - pi));

    return 0;
}