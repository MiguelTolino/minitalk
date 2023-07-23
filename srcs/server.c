/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 18:23:14 by mmateo-t          #+#    #+#             */
/*   Updated: 2023/07/23 12:23:27 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void throw_error(char *error)
{
	ft_printf("%s%s%s%s", RED, "Error: ", RESET, error);
}

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
	// ft_printf("%s%s%s%s%s%i%s ]\n", LBLUE, SERVER_MSG, RESET, str, YELLOW, pid, RESET);
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

	// ft_printf("%s%s%s%s%s%i%s]\n", LBLUE, SERVER_MSG, RESET, MSG, ORANGE, str, RESET);
}

void sighandler(int signum)
{
	if (signum == SIGUSR1)
	{
		counter++;
	}
	if (signum == SIGUSR2)
	{
		if (counter == ENDOFCHAR)
		{
			counter = ENDOFSTR;
		}
		else
			counter = ENDOFCHAR;
	}
}

int main(int argc, char const *argv[])
{
	pid_t pid;
	char *msg;
	int i;
	char c;

	msg = ft_calloc(MAX_SIZE, sizeof(char));
	if (!msg)
		throw_error("Can't reserve memory");

	pid = getpid();
	c = 0;
	signal(SIGUSR1, sighandler);
	signal(SIGUSR2, sighandler);
	print_log("PID | ", pid);
	while (1)
	{
		i = 0;
		while (1)
		{
			counter = 0;
			while (counter >= 0)
			{
				c = (char)counter;
				printf("Char: %c\n", c);
				pause();
			}
			msg[i++] = c;
			pause();
			ft_printf("Msg: %s\n", msg);
			if (counter == ENDOFSTR)
			{
				break;
			}
		}
		ft_printf("STR: %s\n", msg);
		print_str(msg);
		ft_bzero(msg, ft_strlen(msg));
	}
	free(msg);
	(void)argc;
	(void)argv;
	return 0;
}
