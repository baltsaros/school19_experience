#include "micro_paint.h"

void	error_msg_arg()
{
	write(1, "Error: argument\n", 16);
}

void	error_msg_of()
{
	write(1, "Error: Operation file corrupted\n", 32);
}