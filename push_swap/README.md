## **Project summary** 
> This project will make you sort data on a stack, with a limited set of instructions, using the lowest possible number of actions. To succeed you’ll have to manipulate various types of algorithms and choose the most appropriate solution (out of many) for an optimized data sorting.

Rules:
>• You have 2 stacks named a and b.
>
>• The stack a contains a random amount of negative and/or positive numbers which cannot be duplicated. The stack b is empty.
>
>• The goal is to sort in ascending order numbers into stack a.

Instructions:
>• sa (swap a): Swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements.
>
>• sb (swap b): Swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements.
>	
>• ss : sa and sb at the same time.
>	
>• pa (push a): Take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
>	
>• pb (push b): Take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
>	
>• ra (rotate a): Shift up all elements of stack a by 1. The first element becomes the last one.
>	
>• rb (rotate b): Shift up all elements of stack b by 1. The first element becomes the last one.
>	
>• rr : ra and rb at the same time.
>	
>• rra (reverse rotate a): Shift down all elements of stack a by 1. The last element becomes the first one.
>	
>• rrb (reverse rotate b): Shift down all elements of stack b by 1. The last element becomes the first one.
>	
>• rrr : rra and rrb at the same time.

* Bonus part is about writing _checker_ program that will check whether the data was properly sorted or not

## **Testing**
The project was tested by myself, [tester](https://github.com/LeoFu9487/push_swap_tester) and peers

## **Attempts**
**_1st try_**: 0% (forgot to manage INT_MIN and INT_MAX :full_moon_with_face:)

**_2nd try_**: 73% (other parsing problems :new_moon_with_face:)

**_3rd try_**: 115% (not the most efficient algo)

## **Useful resources**
* [Video](https://www.youtube.com/watch?v=7KW59UO55TQ) about one sorting algorithm (looks like quicksort)
* Random numbers [generator](https://www.calculatorsoup.com/calculators/statistics/random-number-generator.php)
* [Playlist](https://www.youtube.com/playlist?list=PLBlnK6fEyqRj9lld8sWIUNwlKfdUoPd1Y) on various types of linked lists


## **Tips**
* Ask peers
* Google
* Keep going
* Test
* Rewrite
* Some of my peers recommended to use existing algorithms rather than creating your own
* The project can be divided into three parts: (1) parsing, (2) sorting and (3) free + exit. For the bonus you just need to replace sorting part with a function that will check instructions, execute them and check sorting
* In parsing you check your input: whether it is appropriate or not. I addressed only two types: 
	(1) argc > 2, i.e.: ./pipex 3 4 1 5 6
	(2) argc == 2, i.e.: ./pipex "3 4 1 5 6"
* Dublicates, non-numeric characters, too big/small integers should not be accepted. Note that if you want to use ft_atoi from libft, you need to modify it to handle cases such as "12aa", "2147483648", etc.
* I used doubly circular linked lists, but I believe that linked lists are a better option for this project, since they are simpler
* I used two algos: one for a small dataset (less than 7, hard coding) and another one for a bigger dataset
