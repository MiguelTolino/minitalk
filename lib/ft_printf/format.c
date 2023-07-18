/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 17:18:06 by mmateo-t          #+#    #+#             */
/*   Updated: 2020/01/16 12:03:37 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	modify_int_negative(t_parameters *param)
{
	char *aux;

	if (param->negative_int_with_zeros)
	{
		if (*param->final_str != '-')
		{
			aux = ft_strjoin("-", param->final_str);
			free(param->final_str);
			param->final_str = aux;
		}
		if (param->precision && param->zero)
			param->width--;
	}
}

int		format(t_parameters *param)
{
	get_width(param);
	precision(param);
	if (!convert_to_char(param))
		return (0);
	no_print(param);
	if (param->precision)
	{
		modify_precision(param);
		modify_int_negative(param);
		modify_width(param);
	}
	else
	{
		modify_width(param);
		modify_int_negative(param);
	}
	print_final_str(param);
	return (1);
}
