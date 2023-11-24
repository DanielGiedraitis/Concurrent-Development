# Lab 3: Reusable Barrier Class

---

## Description
This lab will revolve around creating a reusable barrier class using semaphores. 

## List of Files and Contents
- **Semaphore.h -** Header file for the Semaphore class.
- **Semaphore.cpp -** Implementation file for the Semaphore class.
- **Barrier.cpp -** The implementation file for the Barrier class.
- **Barrier.h -** The header file for the Barrier class.
- **main.cpp -** The file containing the main function. This main function will create at least two threads demonstrating a reusable barrier in action.
- **Makefile -** This is the project file. It contains rules that tell the system how to compile the code and produce a working executable called barrier.
- **README -** Contains Lab 3 information, installation instructions, compilation, and execution guidelines.

## How to install project
To set up this project on your system, follow these steps:

1. Ensure that GCC is installed on your machine.
2. Clone this repository to your local environment.
3. Open your terminal and navigate to the project directory.
4. Once in the folder, use the following commands:

    - **Build the Executables:**
        - Run `make` or `make build` to generate the main executables.
        - For `barrier`:
            - Execute `make barrier`.
        - To create a debug version with symbols:
            - Use `make debug` to build the executables with debug symbols.
        
    - **Run the Executables:**
        - To execute the generated programs, use the shell command `./barrier`

## Testing Procedures

### barrier

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
