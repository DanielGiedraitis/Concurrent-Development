# Lab 5: Dining Philosophers

---

## Description
This project revolves around solving the Dining Philosophers problem, where multiple philosophers compete for a limited number of resources (in this case, dining utensils) in a way that prevents deadlock and starvation. 

## List of Files and Contents
- **Semaphore.h -** Header file for the Semaphore class.
- **Semaphore.cpp -** Implementation file for the Semaphore class.
- **main.cpp -** The file containing the main function. This main function creates a solution to the Dining Philosophers problem.
- **Makefile -** This is the project file. It contains rules that tell the system how to compile the code and produce a working executable called philosophers.
- **README -** Contains Lab 5 information, installation instructions, compilation, and execution guidelines.

## How to install project
To set up this project on your system, follow these steps:

1. Ensure that GCC is installed on your machine.
2. Clone this repository to your local environment.
3. Open your terminal and navigate to the project directory.
4. Once in the folder, use the following commands:

    - **Build the Executables:**
        - Run `make` or `make build` to generate the main executables.
        - For `philosophers`:
            - Execute `make philosophers`.
        - To create a debug version with symbols:
            - Use `make debug` to build the executables with debug symbols.
        
    - **Run the Executables:**
        - To execute the generated programs, use the shell command `./philosophers`

## Testing Procedures

### philosophers

- **Expected Output**:
  - 1 is thinking!
  - 0 is chomping!
  - 3 is thinking!
  - 2 is chomping!
  - 0 is thinking!
  - 4 is chomping!
  - 1 is chomping!
  - 2 is thinking!
  - 4 is thinking!
  - 3 is chomping!
  - 0 is chomping!
  - 1 is thinking!
  - 3 is thinking!
  - 2 is chomping!
  - 2 is thinking!
  - 3 is chomping!
  - 3 is thinking!
  - 0 is thinking!
  - 1 is chomping!
  - 4 is chomping!
  - 1 is thinking!
  - 2 is chomping!
  - 4 is thinking!
  - 0 is chomping!
  - 2 is thinking!

The sequence continues until manually stopped.

## License
[GNU General Public License v3.0 ](https://www.gnu.org/licenses/gpl-3.0.en.html)

## Author
- **Name:** Daniel Giedraitis
- **Email:** daniel.giedraitis@gmail.com
- **Other Projects:** https://github.com/DanielGiedraitis
- **LinkedIn:** https://www.linkedin.com/in/daniel-giedraitis

## Github Repository
Url: [Github Repository](https://github.com/DanielGiedraitis/Concurrent-Development/tree/main)
