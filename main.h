#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdio.h>

#ifdef _OPENMP
	#include <omp.h>
#else
	#define omp_get_num_threads() 0
	#define omp_get_thread_num() 0
#endif

#define G 0      // G = 6.67408 * 10^-11
