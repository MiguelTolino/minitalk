/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migueltolino <migueltolino@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 18:23:14 by mmateo-t          #+#    #+#             */
/*   Updated: 2024/07/05 16:56:09 by migueltolin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int buff_count = 0;

void throw_error(const char *error)
{
	ft_printf("%s%s%s%s", RED, "Error: ", RESET, error);
}

char binaryToASCII(const char *binary)
{
	if (ft_strlen(binary) != 8)
	{
		throw_error("Binary string must be 8 characters long");
		return '\0'; // Return null character if input is invalid
	}

	char result = 0;
	for (int i = 0; i < 8; i++)
	{
		result <<= 1; // Shift result to the left by 1
		if (binary[i] == '1')
		{
			result |= 1; // Set the least significant bit to 1
		}
		else if (binary[i] != '0')
		{
			throw_error("Binary string must contain only 0 or 1");
			return '\0'; // Return null character if input is invalid
		}
	}
	return result;
}

void print_log(pid_t pid)
{
	printf("%s%s%sPID [%s%s%s]\n", LBLUE, SERVER_MSG, RESET, YELLOW, ft_itoa(pid), RESET);
}

void print_str(const char *str)
{
	ft_printf("%s%s%sMSG [%s%s%s]\n", LBLUE, SERVER_MSG, RESET, ORANGE, str, RESET);
}

void sighandler(int signum)
{
	char c = 0;
	char ascii = 0;

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
	if (buff_count == 8)
	{
		buff_count = 0;
		ascii = binaryToASCII(binary_buff);
		msg[ft_strlen(msg)] = ascii;
		if (ascii == '\0')
		{
			ft_printf("%s\n", msg);
			//ft_bzero(msg, MAX_SIZE);
		}
	}
	binary_buff[buff_count++] = c;
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
	buff_count = 0;
	binary_buff = (char *)malloc(sizeof(char) * 8);
	msg = (char *)calloc(MAX_SIZE, sizeof(char));
	if (!binary_buff || !msg)
	{
		throw_error("Error allocating memory\n");
		return 1;
	}

	signal(SIGUSR1, sighandler);
	signal(SIGUSR2, sighandler);
	print_log(pid);
	while (1)
	{
		pause();
	}
	return 0;
}
