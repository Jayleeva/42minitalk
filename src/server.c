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

int client_pid;

void    handle_signal(int sig, siginfo_t *info, void *ucontext)
{
    //(void)info;
    (void)ucontext;
    static unsigned char    c = 0;
    static int              i = 0;
    static int              j = 0;

    if (j == 0)
        client_pid = info->si_pid;
    else
    {
        if (info->si_pid != client_pid)
        {
            j ++;
            return;
        }
        j ++;
    }
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
        //write(2, "\n", 1);
    }
    else
        c <<= 1;
    //ft_printf("%d %d \n", sig, info->si_pid);
    usleep(1000);
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

    sigaction(SIGUSR1, &server, NULL);
    sigaction(SIGUSR2, &server, NULL);
    //signal(SIGUSR1, handle_signal);
    //signal(SIGUSR2, handle_signal);
    while (1)
        usleep(100);
    return (0);
}