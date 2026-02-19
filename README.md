# Address Book Management System (C)

A modular command-line Contact Management System built using C and Makefile.

---

## Overview

The Address Book Management System is a menu-driven CLI application developed in C that enables users to manage contacts efficiently.

The system supports persistent storage using a CSV file and follows a modular programming approach to ensure clean architecture, maintainability, and scalability.

---

## Features

- Add new contact  
- Search contact (by Name / Phone / Email)  
- Edit existing contact  
- Delete contact  
- Load contacts from file  
- Save contacts to CSV  
- Interactive menu-driven interface  
- Modular file organization  

---

## Tech Stack

- Language: C  
- Compiler: GCC  
- Build Tool: Makefile  
- Storage: CSV File Handling  

---

## Project Structure

```
.
├── main.c
├── contact.c
├── contact.h
├── file.c
├── file.h
├── populate.c
├── populate.h
├── contacts.csv
├── makefile
```

---

## Core Concepts Implemented

### Structures
Used to define contact details:
- Name  
- Phone Number  
- Email ID  

### File Handling
- fopen()  
- fprintf()  
- fscanf()  
- Persistent CSV storage  

### Modular Programming
Functionality divided across multiple source and header files for clean and maintainable design.

### Build Automation
Makefile used to automate compilation and linking of object files.

---

## How to Run

### Using Makefile

```
make
./a.out
```

### Manual Compilation

```
gcc main.c contact.c file.c populate.c -o a.out
./a.out
```

---

## Learning Outcomes

- Real-world C project structuring  
- Practical implementation of file handling  
- Build automation using Makefile  
- CLI-based application design  

---

