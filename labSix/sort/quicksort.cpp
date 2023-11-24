/**
 * @file quicksort.cpp
 * @author Daniel Giedraitis (C00260331)
 * @brief Implementation of the Quicksort algorithm using OpenMP for parallelization.
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


const int LENGTH=2000;

/**
 * @brief Partitions the array based on a pivot element.
 * @param myArray The array to be partitioned.
 * @param low The starting index of the partition.
 * @param high The ending index of the partition.
 * @return The index of the pivot element after partitioning.
 */
int partition (vector<int>& myArray , int low , int high ){
  int pivot=myArray[high];
  int k=high;
  int i=low;
  int temp=0;
  while (i<k){
    while (myArray[i]<pivot && i<k)++i;
    while (myArray[k]>pivot && i<k)--k;
    if (i<k){
      temp=myArray[i];
      myArray[i]=myArray[k];
      myArray[k]=temp;
      i++;//do not decrement k here OR ELSE!!
    }
  }
  return i-1;
}
  
/**
 * @brief Recursive function to perform Quicksort on the array.
 * @param myArray The array to be sorted.
 * @param low The starting index of the partition.
 * @param high The ending index of the partition.
 * @return 1 indicating the completion of the sorting process.
 */
int quicksort(vector<int>& myArray , int low , int high ){
  if (low<high){
    int pivot=partition(myArray,low,high);
    //really we should only do this if each partition is above a certain size (1000 elements?)
    //otherwise the overhead outweighs any gains from using threads
    #pragma omp task shared(myArray)
    quicksort(myArray,low,pivot);
    quicksort(myArray,pivot+1,high);
    #pragma omp taskwait
  return 1;
  }
}//quicksort


/**
 * @brief Main function to test the Quicksort algorithm.
 * Generates random data, performs Quicksort, and displays the sorted array.
 */
int main(void){
  srand (time(NULL));
  vector<int> data(LENGTH);
  for(auto& value:data){
    value=rand()%1000;
  }
  for(auto& value:data){
    cout<<value<<" ";
  }
  cout << endl<<"*******************************"<<endl;
  quicksort(data,0,data.size()-1);
  for(auto& value:data){
    cout<<value<<" ";
  }
  cout << endl;
}
// 
// quicksort.cpp ends here
