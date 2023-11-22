/*!
	// Author: Daniel Giedraitis (C00260331)
	// Date Created: 05/10/2023

	// Purpose: Demonstrating the rendezvous pattern using semaphores.
*/

#include "Semaphore.h"
#include <thread>
#include <vector>
#include <iostream>

/*! displays the first function in the barrier being executed */
void task(std::shared_ptr<Semaphore> mutexSem,std::shared_ptr<Semaphore> barrierSem, std::shared_ptr<int> threadCount, std::shared_ptr<int> firstArrived){  
  
  std::cout << "first " << std::endl;
  //put barrier code here

  // Each thread increments firstArrived to track its arrival
  mutexSem->Wait(); // Lock the mutex for synchronization
  *firstArrived += 1; // Increment the count of arrived threads
  
  // If all threads have arrived, signal the barrierSemaphore to proceed
  if (*firstArrived == *threadCount){
    barrierSem->Signal(); // Signal that all threads have arrived
  }
  mutexSem->Signal(); // Release the mutex

  barrierSem->Wait(); // Wait for the signal to proceed from the barrier
  barrierSem->Signal(); // Signal the next thread to proceed
  
  std::cout << "second" << std::endl;
}

int main(void){
  std::shared_ptr<Semaphore> mutexSem;  // Semaphore to control mutex
  std::shared_ptr<Semaphore> barrierSem;  // Semaphore for rendezvous point

  std::shared_ptr<int> firstArrived;  // Tracks the number of threads that have arrived
  std::shared_ptr<int> threadCount; // Total number of threads for rendezvous
  
  mutexSem=std::make_shared<Semaphore>(1);  // Initialize mutex semaphore with initial count 1
  barrierSem=std::make_shared<Semaphore>(0);  // Initialize barrier semaphore with initial count 0
  firstArrived=std::make_shared<int>(0);  // Initialize counter for arrived threads
  
  threadCount=std::make_shared<int>(5); // Total number of threads for rendezvous
  /*!< An array of threads*/
  std::vector<std::thread> threadArray(*threadCount); 
  /*!< Pointer to barrier object*/

  for(int i=0; i < threadArray.size(); i++){
    threadArray[i]=std::thread(task,mutexSem,barrierSem,threadCount, firstArrived);
  }

  for(int i=0; i < threadArray.size(); i++){
    threadArray[i].join();
  }
  
  return 0;
}
