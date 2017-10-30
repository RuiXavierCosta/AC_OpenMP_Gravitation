#include "exemplos.h"

// Exemplo Section

int main(int argc, char **argv)
{
    int nthreads, thread_id, nloops;
    int max_loops = 1000;
    int j;
    printf("I am the main thread.\n");


    j= 0;
    do{
        #pragma omp parallel private(j) reduction(+: nloops)
        {
            nloops = 0 * (max_loops/4);
            do //Start horizontal loop
            {
                nloops++;
            } while (nloops < 1 * (max_loops/4)); //End horizontal loop
        }
    j++;
    }while(j < max_loops);

    printf("The total number of iterations is %d\n",
    nloops);
    printf("Here I am, back to the main thread.\n");

    return 0;
}