/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migueltolino <migueltolino@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 19:09:46 by mmateo-t          #+#    #+#             */
/*   Updated: 2024/07/01 23:27:05 by migueltolin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
#define CLIENT_H

#include <stdlib.h>
#include "ft_printf.h"
#include "colors.h"
#include <sys/types.h> // For pid_t
#include <signal.h>    // For SIGUSR1, SIGUSR2, and signal()
#include <unistd.h>    // For getpid()

#define USAGE "Usage: ./client <PID> <STRING>\n\nArguments:\n  PID          The Process ID (PID) of the target server. It must be a positive integer representing a running server process.\n  STRING       The string input to be sent to the server. It can be any sequence of characters, words, or numbers.\n\nExample:\n./client 12345 \"Hello, server!\"\n\n"

// Errors
#define ERR_ARGS "Number of arguments invalid\n"

// Prototypes
#define MAX_SIZE 256
#define END_OF_STRING_SIGNAL_COUNT 8
#endif