/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 01:52:31 by mmateo-t          #+#    #+#             */
/*   Updated: 2020/01/16 19:43:32 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_hex(t_parameters *param)
{
	unsigned int hex;

	hex = va_arg(param->ap, unsigned int);
	param->final_str = ft_putnbr_base_x(hex, *param->str);
}

void	print_pointer(t_parameters *param)
{
	char *str;

	str = ft_putnbr_base_x(va_arg(param->ap, unsigned long int), 'x');
	param->final_str = ft_strjoin("0x", str);
}
