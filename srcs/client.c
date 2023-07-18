/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 18:23:17 by mmateo-t          #+#    #+#             */
/*   Updated: 2023/07/18 20:50:43 by mmateo-t         ###   ########.fr       */
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

int main(int argc, char const *argv[])
{
	pid_t pid;
	int ret;

	if (argc != 3)
	{
		usage();
	}
	pid = ft_atoi(argv[1]);
	printf("%i", )

	ret = kill(pid, SIGUSR1);
	if (ret > 0)
	{
		write(STDOUT_FILENO, "OK\n", ft_strlen("OK\n"));
	}



	(void)(argc);
	(void)(argv);
	return 0;
}
