/**
 * @file main.cpp
 * @author Daniel Giedraitis (C00260331)
 * @brief Implements the dining philosophers problem using Semaphores for synchronization.
 * @date 02/11/2023
 * @copyright GPL-3.0
 */

#include "Semaphore.h"
#include <iostream>
#include <thread>
#include <vector>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <unistd.h>

const int COUNT = 5;
const int THINKTIME=3;
const int EATTIME=5;
std::vector<Semaphore> forks(COUNT);


/**
 * \brief Simulates the philosopher thinking for a random period.
 * 
 * \param myID The ID of the philosopher.
 */
void think(int myID){
  int seconds=rand() % THINKTIME + 1;
  std::cout << myID << " is thinking! "<<std::endl;
  sleep(seconds);
}

/**
 * \brief Attempts to acquire forks for the philosopher.
 * 
 * \param philID The ID of the philosopher.
 */
void get_forks(int philID){
  if(philID == COUNT - 1) {
    forks[(philID+1)%COUNT].Wait();
    forks[philID].Wait();
  } 
  else {
    forks[philID].Wait();
    forks[(philID+1)%COUNT].Wait();
  }
}

/**
 * \brief Releases the forks held by the philosopher.
 * 
 * \param philID The ID of the philosopher.
 */
void put_forks(int philID){
  if(philID == COUNT - 1) {
    forks[(philID+1)%COUNT].Signal();
    forks[philID].Signal();
  } 
  else {
    forks[philID].Signal();
    forks[(philID+1)%COUNT].Signal(); 
  }
}

/**
 * \brief Simulates the philosopher eating for a random period.
 * 
 * \param myID The ID of the philosopher.
 */
void eat(int myID){
  int seconds=rand() % EATTIME + 1;
    std::cout << myID << " is chomping! "<<std::endl;
  sleep(seconds);  
}

/**
 * \brief Simulates the activities of a philosopher.
 * 
 * \param id The ID of the philosopher.
 * \param liftFork Shared pointer to the Semaphore controlling access to the table.
 */
void philosopher(int id, std::shared_ptr<Semaphore> liftFork){
  while(true){
    think(id);
    liftFork->Wait();
    get_forks(id);
    eat(id);
    put_forks(id);
    liftFork->Signal();
  }//while  
}//philosopher


/**
 * \brief Entry point of the program.
 * 
 * Initializes resources and starts philosopher threads.
 * 
 * \return Integer 0 upon successful execution.
 */
int main(void){
  srand (time(NULL)); // initialize random seed: 
  std::shared_ptr<Semaphore> liftFork = std::make_shared<Semaphore>(4);
  std::vector<std::thread> vt(COUNT);
  for(Semaphore& s: forks) {
  // Semaphores need to be at 1 otherwise no one will ever even get a fork
    s.Signal();
  }
  int id=0;
  for(std::thread& t: vt){
    t=std::thread(philosopher,id++, liftFork);
  }
  /**< Join the philosopher threads with the main thread */
  for (auto& v :vt){
      v.join();
  }
  return 0;
}

/* main.c ends here */
