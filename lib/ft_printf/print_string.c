/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 11:46:45 by mmateo-t          #+#    #+#             */
/*   Updated: 2023/07/18 20:53:52 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_string(t_parameters *param)
{
	param->final_str = va_arg(param->ap, char *);
	if (param->final_str == NULL)
		param->final_str = "(null)";
}

void	print_char(t_parameters *param)
{
	char *c;

	param->special_char = -1;
	c = (char *)malloc(sizeof(char) * 2);
	c[0] = (char)va_arg(param->ap, int);
	c[1] = '\0';
	if (c[0])
		param->final_str = c;
	else
	{
		param->final_str = ft_strdup("");
		param->special_char = c[0];
		param->width--;
		param->len++;
	}
}
