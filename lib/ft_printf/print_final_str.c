/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_final_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 22:49:29 by mmateo-t          #+#    #+#             */
/*   Updated: 2020/01/15 18:31:07 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	special_char(t_parameters *param)
{
	if (param->minus && param->type == 'c' && param->special_char != -1)
		write(1, &param->special_char, 1);
}

void	print_final_str(t_parameters *param)
{
	special_char(param);
	while (*param->final_str)
	{
		write(1, param->final_str++, 1);
		param->len++;
	}
	if (!param->minus && param->type == 'c' && param->special_char != -1)
		write(1, &param->special_char, 1);
}
