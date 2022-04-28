## **Project description** 
This project is about threading and thread management (mutex). It represents the classical problem of synchronization (_the dining philosopher's problem_).

>Rules:
* >Global variables are forbidden!
* >Each philosopher has a number ranging from 1 to *number_of_philosophers*.
* >Philosopher number 1 sits next to philosopher number *number_of_philosophers*. Any other philosopher number N sits between philosopher number N - 1 and philosopher number N + 1.
* >Any state change of a philosopher must be formatted as follows:
	* >timestamp_in_ms X has taken a fork ◦ timestamp_in_ms X is eating
	* >timestamp_in_ms X is sleeping
	* >timestamp_in_ms X is thinking
	* >timestamp_in_ms X died
>Replace timestamp_in_ms with the current timestamp in milliseconds and X with the philosopher number.
* >A displayed state message should not be mixed up with another message.
* >A message announcing a philosopher died should be displayed no more than 10 ms after the actual death of the philosopher.
* >Your program must not have any data races.
* >Each philosopher should be a thread.
* >There is one fork between each pair of philosophers. Therefore, if there are several philosophers, each philosopher has a fork on their left side and a fork on their right side. If there is only one philosopher, there should be only one fork on the table.
* >To prevent philosophers from duplicating forks, you should protect the forks state with a mutex for each of them.

>Bonus part:
>The program of the bonus part takes the same arguments as the mandatory program. It has to comply with the requirements of the Global rules chapter.
>The specific rules for the bonus part are:
* >All the forks are put in the middle of the table.
* >They have no states in memory but the number of available forks is represented by a semaphore.
* >Each philosopher should be a process. But the main process should not be a philosopher.

## **How to use**
* *make* - to compile the obligatory part
* *make bonus* - to compile the bonus part

The program take the following arguments:
* *_number_of_philosophers_*: The number of philosophers and also the number of forks.
* *time_to_die* (in milliseconds): If a philosopher didn’t start eating time_to_die milliseconds since the beginning of their last meal or the beginning of the sim- ulation, they die.
* *time_to_eat* (in milliseconds): The time it takes for a philosopher to eat. During that time, they will need to hold two forks.
* *time_to_sleep* (in milliseconds): The time a philosopher will spend sleeping.
* *number_of_times_each_philosopher_must_eat* (optional argument): If all philosophers have eaten at least number_of_times_each_philosopher_must_eat times, the simulation stops. If not specified, the simulation stops when a philosopher dies.


## **Testing**
The project was tested by myself and peers

## **Attempts**
**_1st try_**: 0% (there was an issue with my ft_usleep that led to the CPU overload when a big number of philosophers was too big)
**_2nd try_**: 125% 

## **Folders**
**srcs** - source files

**include** - header

**philo_b** - bonus part (each philo is a process)

**philo_b_thread** - bonus part (incorrect one, each philo is a thread)

## **Useful resources**
* [Introduction](https://www.youtube.com/watch?v=NbwbQQB7xNQ) to the dining philosopher's problem
* Another [video](https://www.youtube.com/watch?v=dOVdsd31WNg) about the problem with a solution. It provides a great starting point
* Videos [one](https://www.youtube.com/watch?v=uA8X5zNOGw8) and [two](https://youtu.be/9axu8CUvOKY) about threads
* [Video](https://youtu.be/FY9livorrJI) about data race
* A useful [tool](https://nafuka11.github.io/philosophers-visualizer/) to visualize the program's output
* Videos [one](https://www.youtube.com/watch?v=YSn8_XdGH7c) and [two](https://www.youtube.com/watch?v=FYUi-u7UWgw) about semaphors
* [Manual](https://www.ibm.com/docs/en/i/7.2?topic=ssw_ibm_i_72/apis/sigkill.htm) on _kill()_
* [Signals](https://unix.superglobalmegacorp.com/Net2/newsrc/sys/signal.h.html) for _kill()_
* [Video](https://youtu.be/IKG1P4rgm54) explaining difference between threads and processes
* [Thread](https://stackoverflow.com/questions/37015775/what-is-different-between-join-and-detach-for-multi-threading-in-c#:~:text=When%20thread%3A%3Ajoin()%20returns%2C%20the%20OS%20thread%20of,they%20are%20two%20independent%20things.) about the difference between *pthread_join* and *pthread_detach*

## **Tips**
* Ask peers
* Google
* Keep going
* Test
* Rewrite
* Test
* Create your own _usleep()_ to optimize the program
* Don't put too small values for _usleep()_ in your analogue of this function
* Don't use signal _9_ in _kill()_ :upside_down_face:
* Protect with _mutex_ not only forks, but also printing and check_death function. I also protected _gettimeofday_ for the last meal, but it seems to be an overkill
* Bonus part is not that difficult. It requires to replace mutex with semaphore and threads with processes. But you will also need to think how you can check wether a philo is alive or not
