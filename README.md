# Simple Shell Project

This is the Simple Shell project, a UNIX command interpreter inspired by "The Gates of Shell" by Spencer Cheng, featuring Julien Barbier.

## Background Context

### Important Message from Julien

The Simple Shell project is one of the most anticipated projects at ALX SE. It's designed to challenge your skills in programming, C, engineering thinking, group work, and learning how to learn. It's crucial to understand and abide by the guidelines set forth in the project framework. Remember, copying code or looking at solutions is strictly prohibited. At ALX SE, the focus is on learning how to create solutions, not on finding pre-existing ones.

### Learning Objectives

At the end of this project, you should be able to:

- Understand the design of the original Unix operating system.
- Recognize key figures in Unix history, such as Ken Thompson.
- Explain how a shell works and its components.
- Manipulate the environment of the current process.
- Create and manage processes in a Unix-like environment.
- Utilize system calls and understand the difference between functions and system calls.
- Execute other programs using the `execve` system call.
- Handle process termination and end-of-file conditions.
- Understand the concept of a pid (process ID) and a ppid (parent process ID).
- Write a command-line interpreter capable of executing simple commands.

## Requirements

### General

- Allowed editors: vi, vim, emacs
- All files must be compiled on Ubuntu 20.04 LTS using `gcc` with specific compiler options.
- Files should follow the Betty style and be free of memory leaks.
- No more than 5 functions per file and all header files must be include guarded.
- Use system calls only when necessary.
- Write a `README.md` file describing the project.

## Tasks

### 0. Betty would be proud
Write a code that passes the Betty style checks.

### 1. Simple shell 0.1
Write a UNIX command-line interpreter that can execute simple commands.

### 2. Simple shell 0.2
Extend the shell to handle command lines with arguments.

### 3. Simple shell 0.3
Further extend the shell to handle the PATH and prevent unnecessary calls to `fork`.

### 4. Simple shell 0.4
Implement the `exit` built-in command that exits the shell.

### 5. Simple shell 1.0
Implement the `env` built-in command that prints the current environment.

## Compilation and Testing

- Compile the shell using `gcc` with specific options.
- Test the shell in both interactive and non-interactive modes, ensuring correct behavior and error handling.

## Contributors
- Lucy Kendi
- Ridan Hawi
