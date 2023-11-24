/**
 * @file mandelbroit.cpp
 * @author Daniel Giedraitis (C00260331)
 * @brief A program to generate the Mandelbrot set using parallel processing.
 * @date 02/11/2023
 * @copyright GPL-3.0
 */

#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <complex>      /* complex number data type */
#include <time.h>       /* time */
#include <limits>

using namespace std ;

const int ROW=1000;
const int COL=1000;
const int DEPTH=10;

/**
 * @brief Calculates the Mandelbrot iteration count for a given complex number.
 * 
 * @param c The complex number to iterate.
 * @param depth The maximum depth for iteration.
 * @return int The number of iterations until divergence.
 */
int calc(complex<int> c, int depth){
    int count=0;
    complex<int> z=0;
    for(int i=0;i<depth;++i){
	if (abs(z)>2.0){
            break;
	}
	z=z*z+c;
	count++;
    }
    return count;
}

/**
 * @brief Generates the Mandelbrot set using parallel processing and stores the result in a 2D array.
 * 
 * @param p The 2D array to store the Mandelbrot set.
 * @param depth The maximum depth for iteration.
 */
void mandel( int p[ROW][COL], int depth){
  #pragma omp parallel for collapse(2)	  
  for(int i=0;i<ROW;++i){
        for(int k=0;k<COL;++k){
	  p[i][k]=calc(complex<int>(i,k),depth);
	}
    }
}

/**
 * @brief Main function to initialize necessary variables and call the Mandelbrot generation function.
 * 
 * @return int Exit status.
 */
int main(void){

  
  int myArray[ROW][COL];
  /* initialize random seed: */
  srand (time(NULL));
  
  clock_t begin = clock();
  mandel(myArray,DEPTH);
  clock_t end = clock();
  double timeSec = (end - begin) / static_cast<double>( CLOCKS_PER_SEC );
  std::cout << timeSec << std::endl;
}


// 
// mandelbroit.cpp ends here
