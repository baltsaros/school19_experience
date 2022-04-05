## **Project summary** 
The project's goal is to recode _printf()_

Requirements:
>• Don’t implement the buffer management of the original printf()
>• Your function has to handle the following conversions: cspdiuxX%
>• Your function will be compared against the original printf()
>• You must use the command ar to create your library. Using the libtool command is forbidden
>• Allowed functions: malloc, free, write, va_start, va_arg, va_copy, va_end
>• Your libftprintf.a has to be created at the root of your repository

For bonus part it is required to use only one static variable and manage multiple fds

## **Testing**
The project was tested by myself, [Tripouille tester](https://github.com/Tripouille/printfTester), [Paulo-Santana](https://github.com/paulo-santana/ft_printf_tester)(really good one to test the bonus part) and peers

## **Attempts**
**_1st try_**: 120% (for some reasons Moulinette could not compile test executable with my library; i might have some issues with my Makefil)

## **Useful resources**
* [Article](https://www.geeksforgeeks.org/variadic-functions-in-c/) about variadic functions

## **Folders**
**libft** - libft library

**no_bonus** - version without the bonus part, where I didn't use structures

## **Tips**
* Ask peers
* Google
* Keep going
* Test
* Rewrite
* Test against the orinigal printf(). Write as many tests as possible, this will help to better understand how printf works
* Main part is pretty straightforward, but for the bonus assignment you need to use a structure to hande various flags
* My approach to this project: read until new line and save everyting into static string. Then I return all characters until a new line (including; in a new string) and save the rest (if any) in the static string (only what is left after the new line)
* It is important to check for memory leaks, so install [valgrind](https://github.com/LouisBrunner/valgrind-macos)
