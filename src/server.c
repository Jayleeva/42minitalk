/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   server.c                                            :+:    :+:           */
/*                                                      +:+                   */
/*   By: cyglardo <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/02/26 10:38:11 by cyglardo       #+#    #+#                */
/*   Updated: 2025/02/26 10:38:12 by cyglardo       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/inc/libft.h"
#include "minitalk.h"

void    handle_signal(int sig, siginfo_t *info, void *ucontext)
{
    (void)info;
    (void)ucontext;
    static unsigned char    c = 0;
    static int              i = 0;

    c |= (sig == SIGUSR2);
    i ++;

    if (sig == SIGUSR2)
        write(2, "1", 1);
    else
        write(2, "0", 1);
    //ft_printf("%d %d ", sig, info->si_pid);

    if (i == 8)
    {
        if (c == END_OF_MESSAGE)
            write(1, "\n", 1);
        else
            write(1, &c, 1);
        i = 0;
        c = 0;
        write(2, "\n", 1);
    }
    else
        c <<= 1;
    usleep(1000);
}

int    main(void)
{
    sigset_t            set;
    struct sigaction    act1;
    // struct sigaction    act2;

    sigemptyset(&set);
    sigaddset(&set, SIGUSR1);
    sigaddset(&set, SIGUSR2);

    act1.sa_flags = SA_SIGINFO | SA_RESTART;
    act1.sa_mask = set;
    act1.sa_sigaction = &handle_signal;
    // act2.sa_flags = SA_SIGINFO | SA_RESTART;
    // act2.sa_mask = set;
    // act2.sa_sigaction = &handle_signal;

    ft_printf("%d\n", getpid());

    sigaction(SIGUSR1, &act1, NULL);
    sigaction(SIGUSR2, &act1, NULL);
    // signal(SIGUSR1, handle_signal);
    // signal(SIGUSR2, handle_signal);
    while (1)
        usleep(100);
    return (0);
}