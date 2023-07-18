/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 18:55:53 by mmateo-t          #+#    #+#             */
/*   Updated: 2020/01/15 18:04:02 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *string, ...)
{
	t_parameters param;

	param.len = 0;
	param.str = (char *)string;
	va_start(param.ap, string);
	while (*param.str)
	{
		while (*param.str == '%')
		{
			param.str++;
			if (!format(&param))
				return (param.len);
			if (!*param.str)
				return (param.len);
		}
		write(1, param.str++, 1);
		param.len++;
	}
	va_end(param.ap);
	return (param.len);
}
