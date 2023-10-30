# Lab 1: Mutual Exclusion

---

## Description
**1. Synchronized Message Printing:**
  Synchronize two threads to ensure that one thread can print its messages before the other. This will illustrate the concept of thread synchronization and how semaphores can be used to control the order of execution.

**2. Mutual Exclusion with Shared Variables:**
  The second aspect of this lab involves demonstrating mutual exclusion among multiple threads that aim to update a shared variable. The goal is to ensure that only one thread can modify the shared variable at any given time. This showcases the importance of mutual exclusion in multi-threaded programming.

**3. Multiple Executables:**
This lab includes two different executables:
- **'helloThreads':** This executable will represent the use of mutex locks to prevent threads from running concurrently, showcasing the basic principles of synchronization.
- **'mutualEx':** This executable extends the concept further by allowing multiple threads to write to a shared variable. Regardless of which thread accesses it, the final state of the shared variable will always remain consistent, emphasizing the effectiveness of mutual exclusion

## List of Files and Contents
- **Semaphore.h -** Header file for the Semaphore class.
- **Semaphore.cpp -** Implementation file for the Semaphore class.
- **mutualEx.cpp -** Main function file for demonstrating mutual exclusion.
- **Makefile -** Project file containing compilation rules.

## License
[GNU General Public License v3.0 ](https://www.gnu.org/licenses/gpl-3.0.en.html)

## Author
- **Name:** Daniel Giedraitis
- **Email:** daniel.giedraitis@gmail.com
- **Other Projects:** https://github.com/DanielGiedraitis
- **LinkedIn:** https://www.linkedin.com/in/daniel-giedraitis

## Github Repository
Url: [Github Repository](https://github.com/DanielGiedraitis/Concurrent-Development/tree/main)
