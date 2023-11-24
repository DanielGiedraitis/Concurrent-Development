/**
 * @file Semaphore.cpp
 * @author Daniel Giedraitis (C00260331)
 * @brief A Semaphore Implementation
 * @date 02/11/2023
 * @copyright GPL-3.0
 */

#include "Semaphore.h"
/*! \class Semaphore
    \brief A Semaphore Implementation

   Uses C++11 features such as mutex and condition variables to implement Semaphore

*/



/*! \fn void Semaphore::Wait()
    \brief Blocks until the semaphore's count is greater than 0 and then decrements it.

    Uses a mutex and condition variable to wait until the semaphore count is greater than 0. Once the count is greater than 0, it decrements the count.
*/
void Semaphore::Wait()
{
      std::unique_lock< std::mutex > lock(m_mutex);
      m_condition.wait(lock,[&]()->bool{ return m_uiCount>0; });
      --m_uiCount;
}

/*! \fn template<typename R, typename P> bool Semaphore::Wait(const std::chrono::duration<R,P>& crRelTime)
    \brief Blocks until the semaphore's count is greater than 0 or until a timeout occurs.

    \param crRelTime The maximum duration to wait for the semaphore.
    \return true if the semaphore was acquired within the given duration, false if a timeout occurred.

    Uses a mutex and condition variable to wait until the semaphore count is greater than 0 or until the specified timeout duration elapses. If the semaphore is acquired within the duration, it decrements the count and returns true. If a timeout occurs, it returns false.
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

/*! \fn void Semaphore::Signal()
    \brief Increments the semaphore's count and unblocks one waiting thread, if any.

    Increases the count of the semaphore and notifies one waiting thread, if any, that the count has been incremented.
*/
void Semaphore::Signal()
{
      std::unique_lock< std::mutex > lock(m_mutex);
      ++m_uiCount;
      m_condition.notify_one();
}

/*! \fn int Semaphore::getCount()
    \brief Retrieves the current count of the semaphore.

    \return The current count of the semaphore.
*/
int Semaphore::getCount() 
{
      return m_uiCount;
}
