/**
 * @file Semaphore.cpp
 * @author Daniel Giedraitis (C00260331)
 * @brief A Semaphore Implementation
 * @date 05/10/2023
 * @copyright GPL-3.0
 */

#include "Semaphore.h"

/*! \class Semaphore
    \brief A Semaphore Implementation

   Uses C++11 features such as mutex and condition variables to implement Semaphore

*/


//! Blocks until the semaphore's count is greater than zero.
void Semaphore::Wait()
{
      std::unique_lock< std::mutex > lock(m_mutex);
      m_condition.wait(lock,[&]()->bool{ return m_uiCount>0; });
      --m_uiCount;
}


/*!
    \brief Blocks until the semaphore's count is greater than zero or until a specified relative time has elapsed.

    \tparam R The type of the duration's tick count.
    \tparam P The type of the duration's tick period.

    \param crRelTime The relative time duration to wait for.
    \return true if the semaphore was acquired within the specified time, false otherwise.
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

//! Increments the semaphore's count and wakes up one waiting thread.
void Semaphore::Signal()
{
      std::unique_lock< std::mutex > lock(m_mutex);
      ++m_uiCount;
      m_condition.notify_one();
}
