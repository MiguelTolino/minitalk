/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migueltolino <migueltolino@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 19:09:19 by mmateo-t          #+#    #+#             */
/*   Updated: 2024/07/05 16:44:52 by migueltolin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
#define SERVER_H

#include <unistd.h>    // For getpid()
#include <signal.h>    // For SIGUSR1, SIGUSR2, and signal()
#include <sys/types.h> // For pid_t
#include <stdlib.h>
#include "ft_printf.h"
#include "colors.h"
#include <stdio.h>

#define SERVER_MSG "[SERVER]: "
#define MSG "[MESSAGE]: ["
#define MAX_SIZE 256
#define ENDOFCHAR -1
#define ENDOFSTR -2

char *msg;
char *binary_buff;
int buff_count;
#endif