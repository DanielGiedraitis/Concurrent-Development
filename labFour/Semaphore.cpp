/**
 * @file Semaphore.cpp
 * @author Daniel Giedraitis (C00260331)
 * @brief A Semaphore Implementation
 * @date 10/10/2023
 * @copyright GPL-3.0
 */

#include "Semaphore.h"
/*! \class Semaphore
    \brief A Semaphore Implementation

   Uses C++11 features such as mutex and condition variables to implement Semaphore

*/



/**
 * @brief Waits until the Semaphore is available, then decrements the count
 */
void Semaphore::Wait()
{
      std::unique_lock< std::mutex > lock(m_mutex);
      m_condition.wait(lock,[&]()->bool{ return m_uiCount>0; });
      --m_uiCount;
}


/**
 * @brief Waits for a specified duration of time until the Semaphore is available, then decrements the count
 * @tparam R Type of the duration's count
 * @tparam P Type of the duration's period
 * @param crRelTime The relative time duration to wait for the Semaphore
 * @return True if the Semaphore becomes available within the specified duration, otherwise False
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


/**
 * @brief Signals the availability of the Semaphore by incrementing the count
 */
void Semaphore::Signal()
{
      std::unique_lock< std::mutex > lock(m_mutex);
      ++m_uiCount;
      m_condition.notify_one();
}
