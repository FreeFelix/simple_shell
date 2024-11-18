# Simple Shell Project

## **Introduction**
The **Simple Shell** project is one of the most challenging and rewarding tasks in the ALX SE program. It tests your understanding of:
- Programming fundamentals
- C language basics
- Engineering problem-solving skills
- Group collaboration
- Learning how to learn effectively

This project is designed to help you understand the internal workings of a UNIX shell and solidify your problem-solving approach.

---

## **Important Notes**
### **Learning Framework**
Before starting, ensure you are familiar with the [Learning Framework](https://intranet.alxswe.com/concepts/559). Key takeaways include:
- Never copy code or solutions.
- Write code from scratch to demonstrate understanding.
- Use AI tools like ChatGPT appropriately, avoiding reliance on them for solutions.

### **Group Work Guidelines**
This is a group project, requiring collaboration and accountability:
- Both partners must contribute equally.
- Review and understand all code pushed to the repository.
- Report any inability to contribute promptly to staff and your partner.

### **Plagiarism**
Plagiarism will result in removal from the program. This includes:
- Copying code from others.
- Sharing solutions with peers.
- Publishing project content.

---

## **Resources**
- [Unix Shell Overview](https://intranet.alxswe.com/concepts/64)
- [Ken Thompson and the Thompson Shell](https://intranet.alxswe.com/concepts/121)
- Command documentation (`man` pages): 
  - `sh`, `access`, `execve`, `fork`, `wait`, `exit`, etc.

---

## **Learning Objectives**
By completing this project, you should be able to explain:
- The origins of the UNIX operating system and shell.
- The roles of Ken Thompson and the B programming language.
- How a shell works, including processes, system calls, and PATH resolution.
- How to implement key shell functionalities (e.g., `execve`, `fork`, `wait`).

---

## **Requirements**
### General
- All files will be compiled on **Ubuntu 20.04 LTS** with `gcc`:
  ```bash
  gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh


Use the Betty coding style.
No memory leaks allowed.
Include guards in all header files.ompilation
To compile the shell:

gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

Usage
Interactive Mode

$ ./hsh

($) /bin/ls

hsh main.c shell.c

($) exit

$

Non-Interactive Mode

$ echo "/bin/ls" | ./hsh
hsh main.c shell.c

$
$ cat test_ls | ./hsh

hsh main.c shell.c

hsh main.c shell.c
$

Tasks
Mandatory Tasks
Betty Checks: Ensure code passes the Betty linter.
Simple Shell 0.1:

Implement a simple UNIX command-line interpreter.
Display a prompt and execute commands using execve.
Simple Shell 0.2:

Enhance the shell to support argument parsing.
Additional tasks: Incrementally improve the shell to handle advanced features.
Allowed Functions
Key functions and system calls include:

execve, fork, wait, exit, _exit, malloc, free, getline, isatty, write, etc.
Testing
Run the shell in various modes and scenarios, including edge cases:

Use interactive and non-interactive modes.
Test built-in commands and error handling.
Functions are limited to 5 per file.

