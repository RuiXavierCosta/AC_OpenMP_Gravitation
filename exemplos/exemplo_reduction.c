#include "exemplos.h"

int main(int argc, char **argv)
{
    int i, private_nloops, nloops;

    private_nloops = 0;
    nloops = 0;
#pragma omp parallel private(private_nloops) \
    reduction(+ : nloops)
    {
#pragma omp for
        for (i = 0; i < 100000; ++i)
        {
            ++private_nloops;
            ++nloops;
        }
        printf("This thread did %d iterarions\n",
               private_nloops);
    }
    printf("The total number of loop iterations is %d\n",
           nloops);
    return 0;
}