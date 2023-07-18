/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 16:22:27 by mmateo-t          #+#    #+#             */
/*   Updated: 2020/01/15 18:33:57 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_fill(size_t n, int i, char *str)
{
	if (n >= 10)
		ft_fill(n / 10, i - 1, str);
	str[i] = n % 10 + '0';
}

static	char	*ft_itoa_uint(unsigned int n)
{
	char			*str;
	unsigned int	nbr;
	unsigned int	len;

	len = 1;
	nbr = n;
	while (nbr /= 10)
	{
		len++;
	}
	if (!(str = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str[len] = '\0';
	ft_fill(n < 0 ? -n : n, len - 1, str);
	return (str);
}

void			print_int(t_parameters *param)
{
	int num;

	num = va_arg(param->ap, int);
	if (num < 0 && (param->zero || param->precision))
	{
		num = num * -1;
		param->negative_int_with_zeros = 1;
		param->final_str = ft_itoa(num);
	}
	else
		param->final_str = ft_itoa(num);
}

void			print_uint(t_parameters *param)
{
	param->final_str = ft_itoa_uint(va_arg(param->ap, unsigned int));
}
