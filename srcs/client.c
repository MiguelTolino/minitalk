/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 18:23:17 by mmateo-t          #+#    #+#             */
/*   Updated: 2023/07/23 18:37:29 by mmateo-t         ###   ########.fr       */
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
	ft_printf("%s%s%s%s", RED, "Error: ", RESET, error);
}

void send_char(pid_t pid, char c)
{
	while (c)
	{
		if (kill(pid, SIGUSR1) < 0)
			throw_error("An unexpected signal error occurs [SIGUSR1]");
		c--;
		usleep(100);
	}
	if (kill(pid, SIGUSR2))
		throw_error("An unexpected signal error occurs [SIGUSR2]");
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
	if (!msg)
		throw_error("Can't reserve memory");

	while (msg[i])
	{
		send_char(pid, msg[i]);
		i++;
	}
	usleep(100);
	ret = kill(pid, SIGUSR2);
	free(msg);
	return ret;
}
