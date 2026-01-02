In this commit I re-uploaded the full project with the complete implementation of the assignment. The project:

This repository contains a full implementation of Laboratory Work №3: “Thread Synchronization Using Critical Sections and Events. Deadlock Handling”.

Project overview
The project demonstrates synchronization of multiple threads within a single process using critical sections and events.
The solution consists of a main thread and multiple worker threads (marker), which concurrently modify a shared array.
The implementation is written in C++ using WinAPI, strictly following the laboratory assignment requirements.

Project structure
The program consists of:

Main thread
Allocates a shared integer array with a size provided from the console.
Initializes the array with zeros.
Creates and starts multiple marker threads.
Controls the execution of worker threads using events.
Handles situations where threads cannot continue their work.
Terminates selected threads and resumes remaining ones.
Finishes execution after all marker threads have terminated.

Marker threads
Start execution after receiving a signal from the main thread.
Generate pseudo-random numbers using rand() initialized with their thread index.
Attempt to mark elements of the shared array with their own thread number.
Use critical sections to ensure exclusive access to the array.
Detect situations where an array element cannot be marked.
Notify the main thread when further execution is impossible.
Wait for a signal to either continue or terminate.
On termination, clear all array elements previously marked by the thread.

Synchronization mechanisms
Critical sections are used to protect shared array access.
Events are used to:
Start all marker threads simultaneously.
Notify the main thread about blocking situations.
Control continuation or termination of marker threads.

Key features

Multithreading within a single process.
Thread synchronization via WinAPI primitives.
Controlled handling of blocking situations.
Console-based interaction.
Full compliance with the original laboratory assignment.

How to run

Build the project in Visual Studio.
Run the application.
Enter the array size and the number of marker threads.
Observe thread behavior and synchronization in the console.
Terminate threads according to the program prompts.
