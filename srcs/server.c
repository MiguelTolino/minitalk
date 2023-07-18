/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 18:23:14 by mmateo-t          #+#    #+#             */
/*   Updated: 2023/07/18 20:47:53 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void print_log(char *str, pid_t pid)
{
	write(STDOUT_FILENO, LBLUE, ft_strlen(LBLUE));
	write(STDOUT_FILENO, SERVER_MSG, ft_strlen(SERVER_MSG));
	write(STDOUT_FILENO, RESET, ft_strlen(RESET));
	write(STDOUT_FILENO, str, ft_strlen(str));
	write(STDOUT_FILENO, YELLOW, ft_strlen(YELLOW));
	write(STDOUT_FILENO, ft_itoa(pid), sizeof(int));
	write(STDOUT_FILENO, RESET, ft_strlen(RESET));
	write(STDOUT_FILENO, "\n", ft_strlen("\n"));
}

void print_str(char *str)
{
	write(STDOUT_FILENO, LBLUE, ft_strlen(LBLUE));
	write(STDOUT_FILENO, SERVER_MSG, ft_strlen(SERVER_MSG));
	write(STDOUT_FILENO, RESET, ft_strlen(RESET));
	write(STDOUT_FILENO, MSG, ft_strlen(MSG));
	write(STDOUT_FILENO, ORANGE, ft_strlen(ORANGE));
	write(STDOUT_FILENO, str, ft_strlen(str));
	write(STDOUT_FILENO, RESET, ft_strlen(RESET));
	write(STDOUT_FILENO, "]\n", ft_strlen("]\n"));
}

void my_handler(int signum)
{
    if (signum == SIGUSR1)
    {
		print_str("Gola");
    }
}

int main(int argc, char const *argv[])
{
	pid_t pid;

	pid = getpid();
	while (1)
	{
		print_log("PID | ", pid);

		sleep(1);
	}
	signal(SIGUSR1, my_handler);

	(void)argc;
	(void)argv;
	return 0;
}
