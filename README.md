# Simple Shell

Simple Shell is a basic UNIX command line interpreter written in C.
It mimics the core functionality of the `/bin/sh` shell.

This project was developed as part of the Holberton School curriculum
to understand how shells work internally, including process creation,
execution, and environment handling.

---

## Project Objectives
- Understand how a UNIX shell works
- Learn how processes are created and managed
- Execute programs using system calls such as `fork` and `execve`
- Handle environment variables and the `PATH`
- Work with interactive and non-interactive modes
- Follow the Betty coding style

---

## Features
- Execute commands using absolute paths
- Execute commands found in the `PATH`
- Interactive mode with a prompt
- Non-interactive mode (reading commands from standard input)
- Handle `EOF` (Ctrl + D)
- Error messages similar to `/bin/sh`

---

## Compilation
```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh


---


Usage
Interactive Mode
$ ./hsh
($) ls
($) pwd
($) exit


Non-Interactive Mode
$ echo "ls" | ./hsh

---

Files Description

main.c : Entry point of the shell

shell.c : Core shell logic

simple_shell.h : Header file

man_1_simple_shell : Manual page

AUTHORS : Contributors to the project



