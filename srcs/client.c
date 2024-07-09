/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migueltolino <migueltolino@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 18:23:17 by mmateo-t          #+#    #+#             */
/*   Updated: 2024/07/09 14:51:49 by migueltolin      ###   ########.fr       */
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

void throw_error(const char *error)
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

void sighandler(int signum)
{
	printf("Signal received: %d\n", signum);
	if (signum == SIGUSR2)
	{
		ft_printf("Message was received: %sSIGUSR2%s\n", GREEN, RESET);
	}
}

int main(int argc, char const *argv[])
{
	pid_t pid;
	char *msg;
	char *binary;
	struct sigaction sa;
	int i;

	binary = NULL;
	if (argc != 3)
	{
		usage();
	}
	sa.sa_handler = sighandler; // Your signal handler
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0; // or SA_RESTART to automatically restart interrupted system calls
	i = 0;
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
		throw_error("PID must be a positive integer\n");

	// Check if the PID exists
	if (kill(pid, 0) == -1)
	{
		throw_error("Error checking PID"); // perror will print why the kill failed
		return 1;						   // Or handle the error as appropriate
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
	free(msg);
	i = 0;
	msg = ft_itoa(getpid());
	if (!msg)
		throw_error("Can't reserve memory");
	while (msg[i])
	{
		binary = charToBinary(msg[i]);
		send_char(pid, binary);
		i++;
	}
	send_char(pid, charToBinary('\0'));
	free(msg);

	if (sigaction(SIGUSR1, &sa, NULL) == -1)
	{
		throw_error("sigaction");
	}
	return 0;
}
