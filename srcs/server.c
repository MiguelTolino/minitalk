/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migueltolino <migueltolino@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 18:23:14 by mmateo-t          #+#    #+#             */
/*   Updated: 2024/07/09 00:18:58 by migueltolin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int buff_count = 0;

void throw_error(const char *error)
{
	ft_printf("%s%s%s%s", RED, "Error: ", RESET, error);
}

bool isStringFullOfZeros(const char *str) {
    while (*str != '\0') { // Loop until the end of the string
        if (*str != '0') {
            return false; // Found a non-'0' character
        }
        str++; // Move to the next character
    }
    return true; // String is full of '0's
}

char binaryToASCII(const char *binary)
{
	if (ft_strlen(binary) != 8)
	{
		throw_error("Binary string must be 8 characters long");
		return '\0'; // Return null character if input is invalid
	}
	if (isStringFullOfZeros(binary))
	{
		return ENDOFCHAR; // Return -1 if the binary string is all zeros
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


void print_log(pid_t pid, const char *customMessage) {
    char buffer[30];
    time_t now;
    struct tm *timeinfo;

    time(&now);
    timeinfo = localtime(&now);
    strftime(buffer, 30, "%Y-%m-%d %H:%M:%S", timeinfo);

    printf("%s%s%sTime: [%s%s%s] PID: [%s%s%s] MSG: [%s]\n",
           LBLUE, SERVER_MSG, RESET,
           YELLOW, buffer, RESET,
           YELLOW, ft_itoa(pid), RESET,
           customMessage);
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
	binary_buff[ft_strlen(binary_buff)] = c;
	if (ft_strlen(binary_buff) == 8)
	{
		ascii = binaryToASCII(binary_buff);
		if (ascii == ENDOFCHAR)
		{
			print_log(0, msg);
			ft_bzero(msg, MAX_SIZE);
		}
		else
			msg[ft_strlen(msg)] = ascii;
		ft_bzero(binary_buff, sizeof(char) * 8);
	}
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
	ft_bzero(binary_buff, sizeof(char) * 8);
	msg = (char *)calloc(MAX_SIZE, sizeof(char));
	if (!binary_buff || !msg)
	{
		throw_error("Error allocating memory\n");
		return 1;
	}
	signal(SIGUSR1, sighandler);
	signal(SIGUSR2, sighandler);
	print_log(pid, "Server started listening for connections.");
	while (1)
	{
		pause();
	}
	return 0;
}
