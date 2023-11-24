/**
 * @file helloThreads.cpp
 * @author Daniel Giedraitis (C00260331)
 * @brief A Semaphore Implementation to demonstrate serialization, where task A must occur before task B.
 * @date 25/09/2023
 * @copyright GPL-3.0
 * GitHub URL : https://github.com/DanielGiedraitis/Concurrent-Development
 */

#include "Semaphore.h"
#include <iostream>
#include <thread>
#include <unistd.h>

/*! displays a message first */
void taskOne(std::shared_ptr<Semaphore> theSemaphore, int delay)
{
  // Sleep for a specified amount of time.
  sleep(delay); 

  std::cout <<"I ";
  std::cout << "must ";
  std::cout << "print ";
  std::cout << "first"<<std::endl;

  // Signal the semaphore to allow taskTwo to start
  theSemaphore->Signal();
}

/*! displays a message second */
void taskTwo(std::shared_ptr<Semaphore> theSemaphore)
{
  // Wait for the semaphore to be signaled by taskOne
  theSemaphore->Wait(); 
  
  std::cout <<"This ";
  std::cout << "will ";
  sleep(5); // Pauses execution of the current thread for 5 seconds
  std::cout << "appear ";
  std::cout << "second"<<std::endl;
}


int main(void)
{
  // Declare two thread objects
  std::thread threadOne, threadTwo;

  // Create a shared pointer to a Semaphore object and initialize it
  std::shared_ptr<Semaphore> sem( new Semaphore);

  /**< Launch the threads  */
  int taskOneDelay=5;
  threadOne=std::thread(taskTwo,sem);
  threadTwo=std::thread(taskOne,sem,taskOneDelay);
  std::cout << "Launched from the main\n";

   /**< Wait for the threads to finish */
  threadOne.join();
  threadTwo.join();
  return 0;
}
