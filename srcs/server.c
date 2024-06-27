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

int binaryToDecimal(const char *binary)
{
	int decimal = 0;
	int base = 1; // Start with 2^0
	int len = ft_strlen(binary);

	for (int i = len - 1; i >= 0; i--)
	{
		if (binary[i] == '1')
		{
			decimal += base;
		}
		base *= 2; // Move to the next power of 2
	}

	return decimal;
}

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
	char c = 0;

	if (signum == SIGUSR1)
	{
		c = '0';
	}
	else if (signum == SIGUSR2)
	{
		c = '1';
	}
	else
	{
		throw_error("Invalid signal\n");
	}
	ft_printf("%c", c);
}

int main(void)
{
	pid_t pid;

	pid = getpid();
	if (pid < 0)
	{
		throw_error("Error getting PID\n");
		return 1;
	}

	signal(SIGUSR1, sighandler);
	signal(SIGUSR2, sighandler);
	print_log(pid);
	msg = ft_calloc(MAX_SIZE, sizeof(char));
	buff = ft_strdup("");
	while (1)
	{
		pause();
	}
	return 0;
}
