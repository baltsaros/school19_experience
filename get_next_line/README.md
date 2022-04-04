## **Project summary** 
> This project is about programming a function that returns a line read from a file descriptor.

Rules:
>• Repeated calls (e.g., using a loop) to your get_next_line() function should let you read the text file pointed to by the file descriptor, one line at a time.
>• Your function should return the line that was read. If there is nothing else to read or if an error occurred, it should return NULL.
>• Because you will have to read files in get_next_line(), add this option to your compiler call: -D BUFFER_SIZE=n. It will define the buffer size for read(). The buffer size value will be modified by your peer-evaluators and the Moulinette in order to test your code.
>• You will compile your code as follows (a buffer size of 42 is used as an example): cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 <files>.c

For bonus part it is required to use only one static variable and manage multiple fds

## **Testing**
The project was tested by myself, [Tripouille tester](https://github.com/Tripouille/gnlTester) and peers

## **Attempts**
**_1st try_**: 125%

## **Useful resources**
* [Article](https://www.geeksforgeeks.org/input-output-system-calls-c-create-open-close-read-write/#:~:text=File%20descriptor%20is%20integer%20that,pointers%20to%20file%20table%20entries.) about file descriptors, open, close, read and write functions
* Valgrind start [guide](https://valgrind.org/docs/manual/quick-start.html)

## **Folders**
**gnl_with_main** - get_next_line with main functions inside

**alanorm** - submitted folder edited according to the Norm

## **Tips**
* Ask peers
* Google
* Keep going
* Test
* Rewrite
* Test
* My approach to this project: read until new line and save everyting into static string. I return all characters until a new line (including) and save the rest (if any) in the static string (only what is left after the new line)
* It is important to check for memory leaks, so install valgrind
