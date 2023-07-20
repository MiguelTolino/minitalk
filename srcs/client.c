/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 18:23:17 by mmateo-t          #+#    #+#             */
/*   Updated: 2023/07/20 17:36:16 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void usage()
{
	write(STDOUT_FILENO, USAGE, ft_strlen(USAGE));
	exit(EXIT_FAILURE);
}

void throw_error(char *error)
{
	write(STDOUT_FILENO, RED, ft_strlen(RED));
	write(STDOUT_FILENO, "Error: ", ft_strlen("Error: "));
	write(STDOUT_FILENO, RESET, ft_strlen(RESET));
	write(STDOUT_FILENO, error, ft_strlen(error));
}

void send_char(pid_t pid, char c)
{
	printf("Char: %i\n", c);
	while (c)
	{
		kill(pid, SIGUSR1);
		printf("%i\n", c);
		c--;
		usleep(1000);
	}
	usleep(1000);
	kill(pid, SIGUSR2);
}

int main(int argc, char const *argv[])
{
	pid_t pid;
	int ret;
	int i;
	char *msg;

	if (argc != 3)
	{
		usage();
	}
	pid = ft_atoi(argv[1]);
	msg = ft_strdup(argv[2]);
	i = 0;

	while (msg[i])
	{
		send_char(pid, msg[i]);
		i++;
	}
	usleep(1000);
	ret = kill(pid, SIGUSR2);
	free(msg);
	return ret;
}
