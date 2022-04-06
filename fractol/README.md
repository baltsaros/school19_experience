## **Project description** 
> This project’s goal is to create a small fractal exploration program
>The constraints are as follows:
>
>• Your software should offer the Julia set and the Mandelbrot set.
>
>• The mouse wheel zooms in and out, almost infinitely (within the limits of the computer). This is the very principle of fractals.
>
>• You must use at least a few colors to show the depth of each fractal. It’s even better if you hack away on psychedelic effects.
>
>• A parameter is passed on the command line to define what type of fractal will be viewed. If no parameter is provided, or if the parameter is invalid, the program displays a list of available parameters and exits properly.
>
>• More parameters must be used for fractal parameters or ignored.
>
>• You must be able to create different Julia set with the parameters of the program.
>
>As for the graphic representation:
>
>• ESC will exit the program.
>
>• The use of images of the minilibX is strongly recommended.
>

## **How to use**
* The program works only on Mac OS. Linux version require some minor modifications
* Execute in the following way:
> ./fractol <set name: Mandelbrot, Julia, Ship> <number for color from 1 to 3> <number for c; from 1 to 3, works only for Julia Set>
* Move position with arrows, left and right mouse buttons
* Zome with _-_ and _=_ or mouse wheel
* For Julia Set it is possible to change value for c with _q_ and _w_ or _a_ and _s_
* If you want to run more than 150 iteration, you should change the function for color (it is under comments inside fractol_utils.c)

## **Testing**
The project was tested by myself and peers

## **Attempts**
**_1st try_**: 123% (one peer found colors not good enough for max score)

## **Folders**
**srcs** - source files

**libft** - libft with ft_printf

**minilibx** - _minilibX_ library (already compiled)

**include** - header

**pics** - pics

## **Useful resources**
* [Tutorial](https://harm-smits.github.io/42docs/libs/minilibx/introduction.html) on _minilibX_
* Another [one](https://aurelienbrabant.fr/blog/pixel-drawing-with-the-minilibx#)
* And another [one](https://qst0.github.io/ft_libgfx/), but with more info about the project itself and useful links
* For better [understanding](https://www.wikihow.com/Plot-the-Mandelbrot-Set-By-Hand) on how to plot Mandelbrot set. Really useful
* Mandelbrot and Julia sets [tutorial](https://lodev.org/cgtutor/juliamandelbrot.html). Really handy, but with spolilers
* Just cool videos about Mandelbrot set: [one](https://youtu.be/p2jeFDjdJ-s) and [two](https://www.youtube.com/watch?v=JbN1vRmhox0)
* Nice [video](https://www.youtube.com/watch?v=mjqswwqE1RQ) about bit-shifting and colors

## **Tips**
* Ask peers
* Learn maths and google
* Keep going
* Test (especially for colors)
* Rewrite
* Test
* Read about complex numbers. It is really important to understand them for this project. [Here](https://www.youtube.com/watch?v=xiEFKyjmlfo) is a nice video, but in Russian. I am pretty sure there are nice videos in English as well
* Everything that goes after _mlx-loop_ function is ignored
* It is possible to trace operation with the window by using _mlx-hook_. Read more [here](https://harm-smits.github.io/42docs/libs/minilibx/events.html) about X11 events and [masks](https://tronche.com/gui/x/xlib/events/mask.html)
* Julia and Burning ship are highly similar to Mandelbrot, so just some minor adjustments are required to get them
* The bigger is your _max-iteration_, more laggy is your program. I think 100-150 is the best number. Same for the window size

## **Pics**
![alt text](https://github.com/baltsaros/school19_experience/blob/main/fractol/pics/1.jpeg)
![alt text](https://github.com/baltsaros/school19_experience/blob/main/fractol/pics/2.jpeg)
![alt text](https://github.com/baltsaros/school19_experience/blob/main/fractol/pics/3.jpeg)
![alt text](https://github.com/baltsaros/school19_experience/blob/main/fractol/pics/4.png)
![alt text](https://github.com/baltsaros/school19_experience/blob/main/fractol/pics/5.png)
