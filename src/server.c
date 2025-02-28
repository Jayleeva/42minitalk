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

#include "libft.h"
#include "minitalk.h"

void    handle_signal(int sig, siginfo_t *info, void *ucontext)
{
    static unsigned char    c = 0;
    static int              i = 0;

    (void)ucontext;
    //(void)info;
    usleep(5);
    kill(info->si_pid, SIGUSR2);
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

int    main(void)
{
    sigset_t            set;
    struct sigaction    server;
    sigemptyset(&set);
    sigaddset(&set, SIGUSR1);
    sigaddset(&set, SIGUSR2);
    server.sa_flags = SA_SIGINFO | SA_RESTART;
    server.sa_mask = set;
    server.sa_sigaction = &handle_signal;
    ft_printf("%d\n", getpid());
    while (1)
    {
        sigaction(SIGUSR1, &server, NULL);
        sigaction(SIGUSR2, &server, NULL);
        pause();
    }
    return (0);
}
