/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 19:09:46 by mmateo-t          #+#    #+#             */
/*   Updated: 2023/07/20 15:57:47 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
#define CLIENT_H

#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include "../lib/ft_printf/ft_printf.h"
#include "colors.h"

#define USAGE "Usage: ./client <PID> <STRING>\n\nArguments:\n  PID          The Process ID (PID) of the target server. It must be a positive integer representing a running server process.\n  STRING       The string input to be sent to the server. It can be any sequence of characters, words, or numbers.\n\nExample:\n./client 12345 \"Hello, server!\"\n\n"

// Errors
#define ERR_ARGS "Number of arguments invalid\n"

#define MAX_SIZE 256

#endif