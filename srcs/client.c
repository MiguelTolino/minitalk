/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migueltolino <migueltolino@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 18:23:17 by mmateo-t          #+#    #+#             */
/*   Updated: 2024/07/01 23:28:40 by migueltolin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

char *charToBinary(char c)
{
	char *binary = (char *)malloc(9); // Each char is 8 bits + 1 for '\0'
	if (!binary)
		return NULL; // Check for malloc failure

	binary[8] = '\0'; // Null-terminate the string
	for (int i = 7; i >= 0; --i)
	{
		binary[i] = (c & 1) + '0'; // Convert bit to '0' or '1'
		c >>= 1;				   // Move to the next bit
	}

	return binary;
}

void usage()
{
	write(STDOUT_FILENO, USAGE, ft_strlen(USAGE));
	exit(EXIT_FAILURE);
}

void throw_error(char *error)
{
	ft_printf("%s%s%s%s", RED, "Error: ", RESET, error);
}

void send_char(pid_t pid, char *c)
{
	while (c)
	{
		if (*c == '0')
		{
			if (kill(pid, SIGUSR1) < 0)
				throw_error("An unexpected signal error occurs [SIGUSR1]");
		}
		else if (*c == '1')
		{
			if (kill(pid, SIGUSR2) < 0)
				throw_error("An unexpected signal error occurs [SIGUSR2]");
		}
		else
		{
			break;
		}
		 usleep(1000);
		c++;
	}
}

int main(int argc, char const *argv[])
{
	pid_t pid;
	char *msg;
	int i;

	if (argc != 3)
	{
		usage();
	}
	i = 0;
	pid = ft_atoi(argv[1]);
	if (pid < 0)
		throw_error("PID must be a positive integer\n");
	msg = ft_strdup(argv[2]);
	if (!msg)
		throw_error("Can't reserve memory");
	while (msg[i])
	{
		printf("Sending %s\n", charToBinary(msg[i]));
		send_char(pid, charToBinary(msg[i]));
		i++;
	}
	send_char(pid, charToBinary('\0'));
	free(msg);
	return 0;
}
