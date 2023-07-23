/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 18:23:14 by mmateo-t          #+#    #+#             */
/*   Updated: 2023/07/23 19:18:32 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void throw_error(char *error)
{
	ft_printf("%s%s%s%s", RED, "Error: ", RESET, error);
}

void print_log(pid_t pid)
{
	printf("%s%s%sPID [%s%s%s]\n", LBLUE, SERVER_MSG, RESET, YELLOW, ft_itoa(pid), RESET);
}

void print_str(char *str)
{
	printf("%s%s%sMSG [%s%s%s]\n", LBLUE, SERVER_MSG, RESET, ORANGE, str, RESET);
}

void sighandler(int signum)
{
	if (signum == SIGUSR1)
	{
		counter++;
	}
	if (signum == SIGUSR2)
	{
		if (!counter)
		{
			print_str(msg);
			ft_bzero(msg, MAX_SIZE);
			i = 0;
		}
		else
		{
			msg[i++] = counter;
		}
		counter = 0;
	}
}

int main(void)
{
	pid_t pid;

	pid = getpid();
	signal(SIGUSR1, sighandler);
	signal(SIGUSR2, sighandler);
	print_log(pid);
	counter = 0;
	i = 0;
	msg = ft_calloc(MAX_SIZE, sizeof(char));
	while (1)
	{
		pause();
	}
	return 0;
}
