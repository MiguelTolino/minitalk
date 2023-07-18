/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 18:40:43 by mmateo-t          #+#    #+#             */
/*   Updated: 2020/01/15 12:34:28 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**Check if precision exist and save it
*/

void	precision(t_parameters *param)
{
	param->precision = 0;
	param->noprint = 0;
	param->pre_width = 0;
	if (*param->str == '.')
	{
		param->precision = 1;
		param->str++;
		if (*param->str == '*')
		{
			param->pre_width = va_arg(param->ap, int);
			param->str++;
		}
		while (*param->str >= '0' && *param->str <= '9')
		{
			param->pre_width = (param->pre_width * 10) + (*param->str - '0');
			param->str++;
		}
		if (param->pre_width < 0)
		{
			param->precision = 0;
			param->pre_width = 0;
		}
		if (param->precision && param->pre_width == 0)
			param->noprint = 1;
	}
}
