/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_space.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 17:52:50 by mmateo-t          #+#    #+#             */
/*   Updated: 2020/01/14 12:37:03 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**Check if flag zero exist
*/

void	is_zero(t_parameters *param)
{
	param->zero = 0;
	while (*param->str == '0')
	{
		param->zero = 1;
		param->str++;
	}
}

/*
**Check if flag minus exist
*/

void	is_minus(t_parameters *param)
{
	param->minus = 0;
	if (*param->str == '-')
	{
		param->minus = 1;
		param->str++;
	}
}

/*
**Check if there is width and save it
*/

void	get_width(t_parameters *param)
{
	is_zero(param);
	is_minus(param);
	param->width = 0;
	if (*param->str == '*')
	{
		param->width = va_arg(param->ap, int);
		if (param->width < 0)
		{
			param->width = param->width * -1;
			param->minus = 1;
		}
		param->str++;
	}
	while (*param->str >= '0' && *param->str <= '9')
	{
		param->width = (param->width * 10) + (*param->str - '0');
		param->str++;
	}
	if (param->zero && param->minus)
		param->zero = 0;
}
