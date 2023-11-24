/**
 * @file Semaphore.cpp
 * @author Daniel Giedraitis (C00260331)
 * @brief A Semaphore Implementation
 * @date 25/09/2023
 * @copyright GPL-3.0
 * GitHub URL : https://github.com/DanielGiedraitis/Concurrent-Development
 */

#include "Semaphore.h"
/*! \class Semaphore
    \brief A Semaphore Implementation

   Uses C++11 features such as mutex and condition variables to implement Semaphore

*/



//! Blocks until the semaphore's count is greater than zero, then decrements the count.
void Semaphore::Wait()
{
      std::unique_lock< std::mutex > lock(m_mutex);
      m_condition.wait(lock,[&]()->bool{ return m_uiCount>0; });
      --m_uiCount;
}

/*!
    \brief Blocks until the semaphore's count is greater than zero or the timeout duration is reached, then decrements the count.
    \param crRelTime The relative timeout duration for waiting.
    \return True if the semaphore was successfully acquired within the timeout, false otherwise.
*/
template< typename R,typename P >
bool Semaphore::Wait(const std::chrono::duration<R,P>& crRelTime)
{
      std::unique_lock< std::mutex > lock(m_mutex);
      if (!m_condition.wait_for(lock,crRelTime,[&]()->bool{ return m_uiCount>0; })){
	  return false;
      }
      --m_uiCount;
      return true;
}

//! Increments the semaphore's count and wakes up one waiting thread, if any.
void Semaphore::Signal()
{
      std::unique_lock< std::mutex > lock(m_mutex);
      ++m_uiCount;
      m_condition.notify_one();
}
