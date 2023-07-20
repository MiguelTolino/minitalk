/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 18:23:14 by mmateo-t          #+#    #+#             */
/*   Updated: 2023/07/20 17:58:51 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void print_log(char *str, pid_t pid)
{
	char *process;

	process = ft_itoa(pid);
	write(STDOUT_FILENO, LBLUE, ft_strlen(LBLUE));
	write(STDOUT_FILENO, SERVER_MSG, ft_strlen(SERVER_MSG));
	write(STDOUT_FILENO, RESET, ft_strlen(RESET));
	write(STDOUT_FILENO, str, ft_strlen(str));
	write(STDOUT_FILENO, YELLOW, ft_strlen(YELLOW));
	write(STDOUT_FILENO, process, ft_strlen(process));
	write(STDOUT_FILENO, RESET, ft_strlen(RESET));
	write(STDOUT_FILENO, "\n", ft_strlen("\n"));
	free(process);
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

void sighandler(int signum)
{
	if (signum == SIGUSR1)
	{
		c++;
	}
	if (signum == SIGUSR2)
	{
		if (c == -1)
		{
			c = -2;
		}
		else
			c = -1;
	}
}

int main(int argc, char const *argv[])
{
	pid_t pid;
	char *msg;
	int i;

	msg = ft_calloc(MAX_SIZE, sizeof(char));
	pid = getpid();
	signal(SIGUSR1, sighandler);
	signal(SIGUSR2, sighandler);
	print_log("PID | ", pid);
	while (1)
	{
		i = 0;
		while (1)
		{
			c = 0;
			while (1)
			{
				pause();
				if (c >= 0)
				{
					msg[i] = (char)c;
				}
				else
					break;
				printf("Char: %c\n", c);
			}
			printf("CharLAST: %i\n", c);
			pause();
			if (c == -2)
			{
				break;
			}
			i++;
		}
		printf("STR: %s\n", msg);
		print_str(msg);
		ft_bzero(msg, ft_strlen(msg));
	}
	free(msg);
	(void)argc;
	(void)argv;
	return 0;
}
