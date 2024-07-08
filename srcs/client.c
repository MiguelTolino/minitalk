/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migueltolino <migueltolino@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 18:23:17 by mmateo-t          #+#    #+#             */
/*   Updated: 2024/07/09 00:21:27 by migueltolin      ###   ########.fr       */
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
	ft_printf("%s", USAGE);
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
		usleep(500);
		c++;
	}
}

int main(int argc, char const *argv[])
{
	pid_t pid;
	char *msg;
	char *binary;
	int i;

	binary = NULL;
	if (argc != 3)
	{
		usage();
	}
	i = 0;
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
		throw_error("PID must be a positive integer\n");

	// Check if the PID exists
	if (kill(pid, 0) == -1)
	{
		perror("Error checking PID"); // perror will print why the kill failed
		return 1;					  // Or handle the error as appropriate
	}
	msg = ft_strdup(argv[2]);
	if (!msg)
		throw_error("Can't reserve memory");
	while (msg[i])
	{
		binary = charToBinary(msg[i]);
		send_char(pid, binary);
		i++;
	}
	send_char(pid, charToBinary('\0'));
	// Log after the message is fully sent
	ft_printf("Message sent successfully.\n");
	free(msg);
	return 0;
}
