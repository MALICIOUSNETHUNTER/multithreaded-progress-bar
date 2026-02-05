/*
 * Progress Bar Program
 * Displays 4 animated progress bars running simultaneously
 * Uses threading with synchronization for concurrent execution
 * Windows-specific console positioning
 */

#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <process.h>

#define BAR_WIDTH 50  // Width of each progress bar
#define START_POS 8   // Starting position for progress bars

// Global critical section for thread synchronization
CRITICAL_SECTION cs;

/*
 * Sets cursor position in console
 * x: column position
 * y: row position
 */
void gotoxy(int x, int y)
{
    COORD coord = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// Thread function for Task 1: Fast progress bar
void task1_thread(void* arg)
{
    int percent = 0;
    int pos = START_POS;
    
    for (int i = 0; i < BAR_WIDTH; i++)
    {
        percent += 2;
        
        // Lock critical section to prevent console race conditions
        EnterCriticalSection(&cs);
        
        gotoxy(pos + i, 2);
        printf("=");
        gotoxy(pos + BAR_WIDTH + 2, 2);
        printf("%3d%%", percent);
        
        LeaveCriticalSection(&cs);
        Sleep(100);
    }
    _endthread();
}

// Thread function for Task 2: Fast progress bar
void task2_thread(void* arg)
{
    int percent = 0;
    int pos = START_POS;
    
    for (int i = 0; i < BAR_WIDTH; i++)
    {
        percent += 2;
        
        // Lock critical section to prevent console race conditions
        EnterCriticalSection(&cs);
        
        gotoxy(pos + i, 4);
        printf("=");
        gotoxy(pos + BAR_WIDTH + 2, 4);
        printf("%3d%%", percent);
        
        LeaveCriticalSection(&cs);
        Sleep(100);
    }
    _endthread();
}

// Thread function for Task 3: Moderate progress bar
void task3_thread(void* arg)
{
    int percent = 0;
    int pos = START_POS;
    
    for (int i = 0; i < 10; i++)
    {
        percent += 10;
        
        // Lock critical section to prevent console race conditions
        EnterCriticalSection(&cs);
        
        gotoxy(pos + i * 5, 6);
        printf("=====");
        gotoxy(pos + BAR_WIDTH + 2, 6);
        printf("%3d%%", percent);
        
        LeaveCriticalSection(&cs);
        Sleep(100);
    }
    _endthread();
}

// Thread function for Task 4: Slow progress bar
void task4_thread(void* arg)
{
    int percent = 0;
    int pos = START_POS;
    
    for (int i = 0; i < 25; i++)
    {
        percent += 4;
        
        // Lock critical section to prevent console race conditions
        EnterCriticalSection(&cs);
        
        gotoxy(pos + i * 2, 8);
        printf("==");
        gotoxy(pos + BAR_WIDTH + 2, 8);
        printf("%3d%%", percent);
        
        LeaveCriticalSection(&cs);
        Sleep(100);
    }
    _endthread();
}

int main()
{
    // Initialize critical section for thread synchronization
    InitializeCriticalSection(&cs);
    
    // Display progress bar frames
    printf("Task 1:[");
    gotoxy(START_POS + BAR_WIDTH, 2);
    printf("]");

    printf("\n\nTask 2:[");
    gotoxy(START_POS + BAR_WIDTH, 4);
    printf("]");

    printf("\n\nTask 3:[");
    gotoxy(START_POS + BAR_WIDTH, 6);
    printf("]");

    printf("\n\nTask 4:[");
    gotoxy(START_POS + BAR_WIDTH, 8);
    printf("]");

    // Create threads for each task to run simultaneously
    _beginthread(task1_thread, 0, NULL);
    _beginthread(task2_thread, 0, NULL);
    _beginthread(task3_thread, 0, NULL);
    _beginthread(task4_thread, 0, NULL);

    // Wait for all threads to complete (longest task takes ~5 seconds)
    Sleep(6000);

    // Delete critical section
    DeleteCriticalSection(&cs);

    // Exit prompt
    printf("\n\n\n\n\n\n\nPress any key to close the screen...\n");
    _getch();
    return 0;
}
