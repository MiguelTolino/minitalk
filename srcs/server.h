/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 19:09:19 by mmateo-t          #+#    #+#             */
/*   Updated: 2023/07/23 18:38:47 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
#define SERVER_H

#include <unistd.h>    // For getpid()
#include <signal.h>    // For SIGUSR1, SIGUSR2, and signal()
#include <sys/types.h> // For pid_t
#include <stdlib.h>
#include "../lib/ft_printf/ft_printf.h"
#include "colors.h"
#include <stdio.h>

#define SERVER_MSG "[SERVER]: "
#define MSG "[MESSAGE]: ["
#define MAX_SIZE 256
#define ENDOFCHAR -1
#define ENDOFSTR -2

int counter;
static char *msg;
int i;

#endif