/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 18:23:14 by mmateo-t          #+#    #+#             */
/*   Updated: 2023/07/18 19:52:24 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void print_log(char *str)
{
	write(STDOUT_FILENO, LBLUE, ft_strlen(LBLUE));
	write(STDOUT_FILENO, SERVER_MSG, ft_strlen(SERVER_MSG));
	write(STDOUT_FILENO, RESET, ft_strlen(RESET));
	write(STDOUT_FILENO, str, ft_strlen(str));
	write(STDOUT_FILENO, "\n", ft_strlen("\n"));
}

int main(int argc, char const *argv[])
{
	while (1)
	{
		print_log("Waiting for messages...");
		sleep(1);
	}

	(void)argc;
	(void)argv;
	return 0;
}
