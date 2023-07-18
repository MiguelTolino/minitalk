/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_to_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 18:55:03 by mmateo-t          #+#    #+#             */
/*   Updated: 2020/01/15 18:19:56 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		convert_to_char(t_parameters *param)
{
	param->type = *param->str;
	param->negative_int_with_zeros = 0;
	if (*param->str == '%')
		print_percent(param);
	if (*param->str == 'c')
		print_char(param);
	if (*param->str == 'd' || *param->str == 'i')
		print_int(param);
	if (*param->str == 's')
		print_string(param);
	if (*param->str == 'p')
		print_pointer(param);
	if (*param->str == 'u')
		print_uint(param);
	if (*param->str == 'x' || *param->str == 'X')
		print_hex(param);
	if ((param->type != '%' && param->type != 'c' && param->type != 's'
		&& param->type != 'i' && param->type != 'd' &&
		param->type != 'p' && param->type != 'u' && param->type != 'x' &&
		param->type != 'X'))
	{
		return (0);
	}
	param->str++;
	return (1);
}
