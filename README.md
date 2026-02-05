# Multithreaded Progress Bar (Windows, C)

A Windows console application written in C that demonstrates **multithreading with synchronization** by displaying four animated progress bars running concurrently.

Each progress bar runs in its own thread and updates the console safely using a **Critical Section** to prevent race conditions.

---

## Features

- 4 progress bars running **simultaneously**
- Different execution speeds per task
- Thread synchronization using `CRITICAL_SECTION`
- Console cursor positioning with `SetConsoleCursorPosition`
- Windows-specific implementation

---

## Technologies Used

- C (MSVC-compatible)
- Windows API (`windows.h`)
- Multithreading (`_beginthread`)
- Console manipulation

---

## How It Works

- Each task runs in its own thread
- A global `CRITICAL_SECTION` ensures that only one thread writes to the console at a time
- Cursor positioning (`gotoxy`) allows progress bars to update independently
- Sleep delays simulate different task speeds

---

## Compilation (Windows)

Compile using MSVC or a compatible compiler:

```sh
cl progress_bar.c
```
Or with MinGW:
```sh
gcc progress_bar.c -o progress_bar
```

Output Preview
```sh
Task 1: [====================              ] 40%
Task 2: [==============                    ] 28%
Task 3: [==========                        ] 50%
Task 4: [========                          ] 32%
```
## Learning Purpose

-This project is intended for educational use to demonstrate:

-Basic multithreading in C

-Thread synchronization

-Console output control


