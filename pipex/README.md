## **Project summary** 
* The project's objective is to code the _Pipex_ program that will establish interprocess communication and behave like Unix's _pipeline_
* It should be executed as follows:
> $> ./pipex file1 cmd1 cmd2 file2
* That should behave in a similar way as:
> $> < file1 cmd1 | cmd2 > file2
* For the main part the program should handle only two commands, while for the bonus part it should manage several commands (1) and here_doc (2)
> (1) $> ./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2
> 
> (2) $> ./pipex here_doc LIMITER cmd cmd1 file

## **Testing**
The project was tested by myself and peers

## **Attempts**
**_1st try_**: 0% (memory leaks :finnadie:)

**_2nd try_**: 125%

## **Useful resources**
* [Documentation](https://www.ibm.com/docs/en/aix/7.1?topic=accounts-path-environment-variable) on PATH env variable
* Cool videos about [_pipe()_](https://www.youtube.com/watch?v=uHH7nHkgZ4w) and [_fork()_](https://www.youtube.com/watch?v=xVSPv-9x3gk)
* Nice [video](https://www.youtube.com/watch?v=6xbLgZpOBi8) about simulating _pipe()_ in C. Good to understand how to simulate the pipe. Note that our project is a bit different. Also there are some other useful videos about this topic on this channel
* Wiki [article](https://en.wikipedia.org/wiki/Here_document) about here_doc
* This [playlist](https://www.youtube.com/playlist?list=PLBlnK6fEyqRiVhbXDGLXDk_OQAeuVcp2O) helped me to understand better basics of OS and systems calls

## **Tips**
* Ask peers
* Google
* Keep going
* Test
* Rewrite
* Test (including cases when cmd does not exist and check memory leaks)
* Don't forget to free allocated memory, including cases when cmd does not exist
* To save space, write separate functions to check whether allocation was successful (ft_split, ft_strjoin) and to check errors. Almost every function that you use for this project can return -1 as error, so it is important to track all return values
* Pay attention to the return value of your program with _echo $?_ (after the execution of your program). For example, if the last cmd does not exist, the return value should be 127. Compare other return values against the original pipe. I use right bit-shifting to get the right value (not in bonus part)
* If your program does not return prompt, then quite likely that you forgot to close fd somewhere
