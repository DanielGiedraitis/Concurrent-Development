# Lab 2: Rendezvous

---

## Description
This lab explores the concept of rendezvous, emphasizing thread synchronization using semaphores. 

## List of Files and Contents
- **Semaphore.h -** Header file for the Semaphore class.
- **Semaphore.cpp -** Implementation file for the Semaphore class.
- **main.cpp -** Main function file for demonstrating the rendezvous pattern in action using a common Semaphore. 
- **Makefile -** File containing rules that guide the system in compiling the code and generating a working executable called "rendezvous."
- **README -** Contains Lab 2 information, installation instructions, compilation, and execution guidelines.

## How to install project
To set up this project on your system, follow these steps:

1. Ensure that GCC is installed on your machine.
2. Clone this repository to your local environment.
3. Open your terminal and navigate to the project directory.
4. Once in the folder, use the following commands:

    - **Build the Executables:**
        - Run `make` or `make build` to generate the main executables.
        - For `rendezvous`:
            - Execute `make rendezvous`.
        - To create a debug version with symbols:
            - Use `make debug` to build the executables with debug symbols.
        
    - **Run the Executables:**
        - To execute the generated programs, use the shell command `./rendezvous`

## Testing Procedures

### rendezvous

- **Expected Output**:
  - first
  - first
  - first
  - first
  - first
  - second
  - second
  - second
  - second
  - second

## License
[GNU General Public License v3.0 ](https://www.gnu.org/licenses/gpl-3.0.en.html)

## Author
- **Name:** Daniel Giedraitis
- **Email:** daniel.giedraitis@gmail.com
- **Other Projects:** https://github.com/DanielGiedraitis
- **LinkedIn:** https://www.linkedin.com/in/daniel-giedraitis

## Github Repository
Url: [Github Repository](https://github.com/DanielGiedraitis/Concurrent-Development/tree/main)
