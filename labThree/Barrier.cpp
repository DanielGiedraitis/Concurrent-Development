/*!
	// Author: Daniel Giedraitis (C00260331)
	// Date Created: 10/10/2023

	// Purpose: The implementation file for the Barrier class.
*/

#include "Barrier.h"

/*! \class Barrier
    \brief An Implementation of a barrier Using Semaphores 

   Uses C++11 features such as mutex and condition variables to implement a barrier using Semaphores with N number threads

*/
/*! Barrier constructor*/
Barrier::Barrier(){

  this->count = 0;
  threadNum = 0;
  condition = false;
  mutex=std::make_shared<Semaphore>(1); // Initialize mutex Semaphore with count 1
  barrier1=std::make_shared<Semaphore>(0);  // Initialize barrier1 Semaphore with count 0
  barrier2=std::make_shared<Semaphore>(1);  // Initialize barrier2 Semaphore with count 1

}
/*! Barrier with parameter constructor*/
Barrier::Barrier(int count){

  this->count = count;
  threadNum = 0;
  condition = false;
  mutex=std::make_shared<Semaphore>(1);
  barrier1=std::make_shared<Semaphore>(0);
  barrier2=std::make_shared<Semaphore>(1);
}
/*! Barrier deconstructor*/
Barrier::~Barrier(){
  
}

/*! sets count value*/
void Barrier::setCount(int x){

  this->count = x;
}
/*! returns count value*/
int Barrier::getCount(){

  return this->count;
}

/*! waits for all the threads before starting second half of code*/ 
void Barrier::waitForAll(){

  mutex->Wait();
  threadNum++;

  if(threadNum == count){
    barrier2->Wait();
    barrier1->Signal();
  }
  
  mutex->Signal();

  barrier1->Wait();

  barrier1->Signal();

  mutex->Wait();
  threadNum--;

  if(threadNum == 0){
    barrier1->Wait();
    barrier2->Signal();
    threadNum = 0;
  }
  mutex->Signal();
  barrier2->Wait();
  barrier2->Signal();
}
