#include "libft/inc/libft.h"
#include <signal.h>

#define END_OF_MESSAGE '\0'

void    handle_signal(int sig)
{
    static unsigned char	c;
    static int 		        i;

    c |= (sig == SIGUSR2);
    i ++;
    if (i == 8)
    {
        if (c == END_OF_MESSAGE)
            write(1, "\n", 1);			
        else
            write(1, &c, 1);
        i = 0;
        c = 0;
    }
    else
        c <<= 1;
}

int  main(void)
{
    ft_printf("%d\n", getpid());
    signal(SIGUSR1, handle_signal);
    signal(SIGUSR2, handle_signal);
    while (1)
        usleep(100);
    return (0);
}