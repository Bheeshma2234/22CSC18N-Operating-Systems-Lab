# 22CSC18N – Operating Systems Lab

![Language](https://img.shields.io/badge/Language-C-blue)
![Platform](https://img.shields.io/badge/Platform-Linux-green)
![Course](https://img.shields.io/badge/Course-Operating%20Systems-orange)

## 📌 About

This repository contains the **Operating Systems Lab** programs implemented in **C Programming Language** as part of the **22CSC18N – Operating Systems Lab** course.

The experiments focus on Linux/Unix system calls, shell programming, CPU scheduling, page replacement, threads, Inter-Process Communication (IPC), process synchronization, deadlock avoidance, and file allocation techniques.

## 🎯 Course Objectives

* Explore the **Unix/Linux operating system** environment.
* Analyze various **system calls** available in Linux/Unix.
* Understand process and file management.
* Implement shell programs.
* Simulate CPU scheduling and memory management techniques.
* Study process synchronization and Inter-Process Communication.
* Implement deadlock avoidance and file allocation methods.

## 📚 Experiments

| No. | Experiment                   | Topics                                                                                                                             |
| --- | ---------------------------- | ---------------------------------------------------------------------------------------------------------------------------------- |
| 01  | File-Related System Calls    | `mkdir`, `link`, `unlink`, `mount`, `umount`, `users`, `chown`, `chmod`, `open`, `close`, `read`, `write`, `lseek`, `stat`, `sync` |
| 02  | Process-Related System Calls | `fork`, `wait`, `exec`, `exit`, `getpid`, `getuid`, `setuid`, `brk`, `nice`, `sleep`                                               |
| 03  | Shell Programming            | Shell scripts and Linux commands                                                                                                   |
| 04  | CPU Scheduling               | FCFS, SJF, Round Robin                                                                                                             |
| 05  | Page Replacement             | FIFO, LRU                                                                                                                          |
| 06  | Threads                      | Thread creation and execution                                                                                                      |
| 07  | IPC Mechanisms               | Pipes, Semaphores, Shared Memory, Message Queues                                                                                   |
| 08  | Synchronization Problems     | Dining Philosophers, Producer-Consumer                                                                                             |
| 09  | Deadlock                     | Banker's Algorithm                                                                                                                 |
| 10  | File Allocation              | Contiguous, Linked, Indexed                                                                                                        |

## 🗂️ Repository Structure

```text
22CSC18N-Operating-Systems-Lab/
│
├── 01_File_System_Calls/
├── 02_Process_System_Calls/
├── 03_Shell_Programming/
├── 04_CPU_Scheduling/
├── 05_Page_Replacement/
├── 06_Threads/
├── 07_IPC/
├── 08_Synchronization/
├── 09_Bankers_Algorithm/
├── 10_File_Allocation/
│
└── README.md
```

## 💻 Technologies Used

* **Programming Language:** C
* **Operating System:** Linux/Unix
* **Shell:** Bash
* **Compiler:** GCC
* **Version Control:** Git & GitHub

## ▶️ How to Run

### Compile a C program

```bash
gcc program.c -o program
```

### Execute the program

```bash
./program
```

### Example

```bash
gcc FCFS.c -o FCFS
./FCFS
```

### Run a Shell Program

Give execution permission:

```bash
chmod +x program.sh
```

Then execute:

```bash
./program.sh
```

## 🎓 Course Outcomes

After completing the laboratory experiments, the student will be able to:

* Understand the **Linux/Unix environment**.
* Identify and interpret various **system programs and system calls**.
* Implement **shell programming**.
* Simulate **memory management, file allocation, and process scheduling**.
* Analyze and implement **process and file management system calls**.
* Develop programs involving **concurrency and synchronization**.
* Understand **IPC mechanisms and deadlock management**.

## 📖 Key Concepts Covered

### System Calls

* File management
* Process management
* User and permission management
* File descriptors

### CPU Scheduling

* First Come First Serve (FCFS)
* Shortest Job First (SJF)
* Round Robin (RR)

### Memory Management

* FIFO Page Replacement
* LRU Page Replacement

### Process Management

* Process creation
* Process termination
* Process synchronization
* Threads

### Inter-Process Communication

* Pipes
* Semaphores
* Shared Memory
* Message Queues

### Deadlocks

* Banker's Algorithm
* Deadlock detection
* Deadlock avoidance

### File Allocation

* Contiguous Allocation
* Linked Allocation
* Indexed Allocation

## 👨‍💻 Author

**A. Bheeshma Shankar**

B.E. Computer Science and Engineering
(Artificial Intelligence & Machine Learning)

**Chaitanya Bharathi Institute of Technology (CBIT), Hyderabad**

## ⭐ Repository

This repository is created for **academic learning, laboratory practice, and reference** for the Operating Systems course.

---

### 📌 Note

All programs in this repository are implemented for educational purposes as part of the **22CSC18N – Operating Systems Lab** curriculum.

