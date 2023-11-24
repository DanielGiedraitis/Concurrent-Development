/**
 * @file stencil.cpp
 * @author Daniel Giedraitis (C00260331)
 * @brief A program to perform a stencil operation on a vector using parallel processing.
 * @date 02/11/2023
 * @copyright GPL-3.0
 */

#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <complex>      /* complex number data type */
#include <time.h>       /* time */
#include <functional>  /* function type */
#include <limits>
#include <vector>      /* vectors used instead of arrays */

using namespace std ;

//array dimension
const int DIM=1000;
const int SIZE=4;

/**
 * @brief Calculates neighbors around a specified index in a vector.
 * 
 * @param in Input vector.
 * @param index Index for which neighbors need to be calculated.
 * @param out Vector to store the calculated neighbors.
 * @return int Returns 1 indicating successful calculation.
 */
int calcNeighbours(vector<float> const  &in, int index, vector<float>& out){
  int amount=out.size();
  for(int i=0;i<out.size();++i){//put neighbours of in[i] into out vector
    int k=i-amount/2;
    if (k<0){//wrap k around size of in vector
      k=in.size()+k;
    }else if (k>=in.size()){
      k=k-in.size();
    }
    out[i]=in[k];
  }
  return 1;
}

/**
 * @brief Performs a stencil operation on a vector.
 * 
 * @param in Input vector.
 * @param out Output vector.
 * @param f Function to apply on the neighborhood of each element.
 * @param size Size of the stencil.
 */
void stencil(vector<float> const &in, vector<float> &out,
	     function <float(vector<float>) > f,int size){
#pragma openmp parallel for
  for (int i=0; i < in.size(); ++i){
    vector<float> neighbours(size);
    calcNeighbours(in,i,neighbours);
    out[i]=f(neighbours);
  }
}

/**
 * @brief Calculates the average of values in a vector.
 * 
 * @param currentValues Vector containing values to calculate the average.
 * @return float Returns the calculated average.
 */
float getNewValue(vector<float> currentValues){
  float average=0.0;
  float total=0.0;
  for(auto const& value: currentValues){
    total+=value;
  }
  return total/currentValues.size();
}

/**
 * @brief Main function to demonstrate the stencil operation.
 * 
 * @return int Returns 0 upon successful execution.
 */
int main(void){
  vector<float> first(DIM), second(DIM);
  //initilise vectors
  srand (time(NULL));
   
  for(auto& value: first) {
    value=(float)rand() / ((float)(RAND_MAX)+(float)(1));
  }
  for(auto it=second.begin(); it<second.end();++it){
    *it=0.0f;
  }
  //
  float sum=0.0f;
  for(auto const&value: first){
    sum+=value;
  }
  cout << sum <<endl;
  stencil(first,second,getNewValue,SIZE);
  sum=0.0f;
  for(auto const&value: second){
    sum+=value;
  }
  cout << sum <<endl;
  return 0;
}
// 
// stencil.cpp ends here
