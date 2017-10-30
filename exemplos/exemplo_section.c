#include "exemplos.h"

// Exemplo Section

void times_table(int n)
{
    int i, i_times_n, thread_id;
    thread_id = omp_get_thread_num();
    for (i = 1; i <= n; ++i)
    {
        i_times_n = i * n;
        printf("Thread %d says %d times %d equals %d.\n",
               thread_id, i, n, i_times_n);
        sleep(1);
    }
}

void countdown()
{
    int i, thread_id;
    thread_id = omp_get_thread_num();
    for (i = 10; i >= 1; --i)
    {
        printf("Thread %d says %d...\n", thread_id, i);
        sleep(1);
    }
    printf("Thread %d says \"Lift off!\"\n", thread_id);
}

void long_loop()
{
    int i, thread_id;
    double sum = 0;
    thread_id = omp_get_thread_num();
    for (i = 1; i <= 10; ++i)
    {
        sum += (i * i);
        sleep(1);
    }
    printf("Thread %d says the sum of the long loop is %f\n",
           thread_id, sum);
}

int main(int argc, char **argv)
{
    int nthreads, thread_id;

    printf("I am the main thread.\n");

#pragma omp parallel
    {
#pragma omp sections
        {
#pragma omp section
            {
                times_table(12);
            }
#pragma omp section
            {
                countdown();
            }
#pragma omp section
            {
                long_loop();
            }
        }
    }

    printf("Here I am, back to the main thread.\n");

    return 0;
}