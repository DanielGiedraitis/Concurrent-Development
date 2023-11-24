/**
 * @file Semaphore.h
 * @author Daniel Giedraitis (C00260331)
 * @brief A Semaphore Implementation
 * @date 10/10/2023
 * @copyright GPL-3.0
 */

#include <mutex>
#include <condition_variable>

/*! \class Semaphore
    \brief A Semaphore Implementation

   Uses C++11 features such as mutex and condition variables to implement Semaphore

*/
class Semaphore
{
private:
    unsigned int m_uiCount; /*!< Holds the Semaphore count */
    std::mutex m_mutex;
    std::condition_variable m_condition;

public:
    Semaphore(unsigned int uiCount=0)
      : m_uiCount(uiCount) { };
    void Wait();
    void Signal();

};
