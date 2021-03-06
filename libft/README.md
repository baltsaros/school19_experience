## **Project summary** 
> This project aims to code a C library regrouping usual functions that you’ll be use for all your next projects

## **Testing**
The project was tested by myself, peers and three testers ([libft-war-machine](https://github.com/y3ll0w42/libft-war-machine), [libft-unit-tests](https://github.com/alelievr/libft-unit-test) and [libft-Tripouille](https://github.com/Tripouille/libftTester))

## **Attempts**
**_1st try_**: 0% (memory leaks in ft_split)

**_2nd try_**: 97% overal/125% Moulinette (ft_atoi didn't address extreme cases, insufficient protection in some bonus functions)

**_3rd try_**: 125%

## **Folders**
**libft_main** - libft with main functions inside

**libft_norminette** - submitted folder

## **Useful resources**
* Google
* Peers
* Neso Academy - great [videos](https://www.youtube.com/playlist?list=PLBlnK6fEyqRj9lld8sWIUNwlKfdUoPd1Y) about linked lists
* [GeeksForGeeks](https://www.geeksforgeeks.org/) - some useful articles (Google will lead you there anyway)
* [Manual](https://www.gnu.org/software/make/manual/make.html#Suffix-Rules) on _make_ (enjoy)
* Morning [exercises](https://youtu.be/ECxYJcnvyMw) to warm-up

## **Tips**
* Ask peers
* Google
* Keep going
* Test
* Rewrite
* Test against original functions. Try to write as many tests as possible. Only after this use testers
* Protect functions in part 2 and bonus part
* For part 1 copy prototypes from _man_
* Add _ft_free_ in your ft_split to free every created string (including an array for strings) in case of error
* More specific comments are inside **_libft_main_**
