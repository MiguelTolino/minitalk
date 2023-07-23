/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 18:23:17 by mmateo-t          #+#    #+#             */
/*   Updated: 2023/07/23 12:19:50 by mmateo-t         ###   ########.fr       */
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
		printf("%i\n", c);
		c--;
		usleep(100);
	}
	sleep(1);
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
	sleep(1);
	ret = kill(pid, SIGUSR2);
	free(msg);
	return ret;
}
