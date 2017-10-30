#include "exemplos.h"

//exemplo For

int main(int argc, char **argv)
{
    int i, thread_id, nloops;
#pragma omp parallel private(thread_id, nloops)
    {
        nloops = 0;
        thread_id = omp_get_thread_num();
#pragma omp for
        for (i = 0; i < 1000; ++i)
        {
            if (nloops == 0)
                printf("Thread %d started with i=%d\n", thread_id, i);
            ++nloops;
        }
        thread_id = omp_get_thread_num();
        printf("Thread %d performed %d iterations of the loop.\n",
               thread_id, nloops);
    }
    return 0;
}