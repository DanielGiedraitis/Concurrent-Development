/**
 * @file saxpy.cpp
 * @author Daniel Giedraitis (C00260331)
 * @brief Perform SAXPY operation and measure execution time.
 * @date 02/11/2023
 * @copyright GPL-3.0
 */

#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <limits>

/**
 * @brief Performs the SAXPY operation.
 * @param n The size of the arrays.
 * @param a The scalar value.
 * @param y The output array.
 * @param x The input array.
 */
void saxpy(unsigned long n, float a,float y[], float x[])
{
#pragma omp parallel for
	for (unsigned long i=0; i < n; ++i)
	{
		y[i]=a * x[i] + y[i];
	}
}

/**
 * @brief The main function, initializes arrays and measures execution time of SAXPY operation.
 * @return Integer indicating the exit status.
 */
int main(void)
{
  const unsigned long size=1000000;
  const float A=1.234;
  
  float y[size];
  float x[size];
  /* initialize random seed: */
  srand (time(NULL));
  


  for(unsigned long long int i=0;i<size;++i){
    y[i]=i*i;
    /* generate secret number between 1 and 1000000: */
    x[i] = rand() % 1000000 + 1;
  }
  clock_t begin = clock();
  saxpy(size,A,y,x);
  clock_t end = clock();
  double timeSec = (end - begin) / static_cast<double>( CLOCKS_PER_SEC );
  std::cout << timeSec << std::endl;
}

// 
// saxpy.cpp ends here
