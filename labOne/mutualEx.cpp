/*!
	// Author: Daniel Giedraitis (C00260331)
	// Date Created: 25/09/2023

  // Purpose: To demonstrate the implementation of Mutual Exclusion using Semaphores, allowing multiple threads to safely update a shared variable.
*/

#include "Semaphore.h"
#include <iostream>
#include <thread>
#include <vector>


static const int num_threads = 100; // Define a constant for the number of threads to be created.
int sharedVariable=0; // Initialize a shared integer variable.


/*! \fn updateTask
    \brief An Implementation of Mutual Exclusion using Semaphores

   Uses C++11 features such as mutex and condition variables to implement an example of a rendezvous for threads

*/
/*! displays a message that is split in to 2 sections to show how a rendezvous works*/
void updateTask(std::shared_ptr<Semaphore> firstSem, int numUpdates)
{

  for(int i=0; i < numUpdates; i++)
  {
    firstSem->Wait(); // Acquire a semaphore lock (Wait blocks if the semaphore is not available).

    //UPDATE SHARED VARIABLE HERE!
    sharedVariable++;

    firstSem->Signal(); // Release the semaphore lock to allow other threads to access the shared variable.
  }
}


int main(void)
{
  std::vector<std::thread> vt(num_threads); // Create a vector of threads to store the thread objects.

  std::shared_ptr<Semaphore> aSemaphore( new Semaphore);  // Create a shared pointer to a Semaphore object.

  /**< Launch the threads  */
  int i=0;
  for(std::thread& t: vt)
  {
    t=std::thread(updateTask,aSemaphore,1000);  // Launch multiple threads, each executing the `updateTask` function.
    if(i == (num_threads - 1)) 
    {
      aSemaphore->Signal(); // Signal the semaphore for the last thread to start.
    }
    i++;
  }

  std::cout << "Launched from the main\n";

  /**< Join the threads with the main thread */
  for (auto& v :vt)
  {
      v.join(); // Wait for all the launched threads to finish their execution.
  }

  std::cout << sharedVariable << std::endl;
  return 0;
}
