# 🐚 Simple Shell
A simple UNIX command-line interpreter written in C as part of the Holberton School curriculum.  

This project recreates the core behavior of /bin/sh, including command parsing, process creation, environment handling, and PATH resolution.

---

## Table of Contents
- [Description](#description)
- [Learning Objectives](#learning-objectives)
- [Features](#features)
- [Requirements](#requirements)
- [Compilation](#compilation)
- [Usage](#usage)
  - [Interactive Mode](#interactive-mode)
  - [Non-Interactive Mode](#non-interactive-mode)
- [Project Structure](#project-structure)
- [Authors](#authors)

---

## Description
This project implements a minimal shell capable of:

- Reading user input
- Tokenizing commands
- Resolving executable paths using the PATH environment variable
- Creating child processes with fork
- Executing commands with execve
- Handling interactive and non-interactive modes
- Printing environment variables
- Handling the exit built-in

It provides a foundational understanding of how real shells work internally

---

# Learning Objectives
This project helped us understand how the OS interacts with user programs by:
- Explain what a shell is and how it works
- Use system calls: fork, execve, wait, stat, getline
- Parse and tokenize user input
- Manage memory and avoid leaks
- Handle environment variables
- Implement basic built-in commands
- Work in both interactive and non-interactive modes
- Follow the Betty coding style

---

## Features

- Execute commands using absolute or relative paths
- Search for commands in the PATH
- Interactive prompt (#cisfun$)
- Non-interactive mode (e.g., echo "ls" | ./hsh)
- Built-in commands:
    - exit
    - env
- Basic error messages inspired by /bin/sh
- Graceful handling of EOF (Ctrl + D)

---

## Requirements
- Ubuntu 20.04 LTS
- GCC compiler
- Betty style compliance
- No memory leaks

---

## Compilation

Compile using:
```Bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

---

## Usage

### Interactive Mode
```Bash
$ ./hsh
#cisfun$ ls
#cisfun$ pwd
#cisfun$ exit
```

### Non-Interactive Mode
```Bash
$ echo "ls -l" | ./hsh
$ cat commands.txt | ./hsh
```

---

## Project Structure

```
holbertonschool-binary_trees/
│
├── main.c               # Entry point, input loop, tokenization
├── shell.c              # Execution logic, forking, execve
├── fork.c               # PATH resolution and command lookup
├── free_array.c         # Memory cleanup helper
├── string_helpers.c     # Custom string functions
├── simple_shell.h       # Header file
├── README.md            # Project documentation
└── man_1_simple_shell   # Manual page
```

---

## Authors
- Badriah Barakat
- Ebtihal Alomari

**This project is part of the Holberton School curriculum**