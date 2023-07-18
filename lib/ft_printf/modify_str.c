/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 18:11:13 by mmateo-t          #+#    #+#             */
/*   Updated: 2020/01/16 17:33:34 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	char	*set_space(int count, char signo)
{
	char	*ptr;
	int		i;

	if (!(ptr = (char *)malloc((count + 1) * sizeof(char))))
		return (0);
	i = 0;
	while (i < count)
	{
		ptr[i] = signo;
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

void			modify_width(t_parameters *param)
{
	char			*space;
	char			*aux;
	unsigned int	count;
	char			c;

	if (param->negative_int_with_zeros && param->zero)
		param->width--;
	if (param->width > (int)ft_strlen(param->final_str))
		count = param->width - (int)ft_strlen(param->final_str);
	else
		count = 0;
	c = (param->zero == 1) ? '0' : ' ';
	space = set_space(count, c);
	if (param->minus)
	{
		aux = ft_strjoin(param->final_str, space);
		param->final_str = aux;
	}
	else
	{
		aux = ft_strjoin(space, param->final_str);
		param->final_str = aux;
	}
	free(space);
}

void			no_print(t_parameters *param)
{
	if (param->noprint)
	{
		if (param->type == 'p' && (param->final_str[2] == ' ' ||
		param->final_str[2] == '0'))
			param->final_str = ft_strdup("0x");
		if (*param->final_str == '0' && param->type != 'p' && param->type != 'c'
		&& param->type != 's')
			param->final_str = ft_strdup("");
	}
}

void			modify_precision(t_parameters *param)
{
	char			*aux;
	char			*zeros;
	unsigned int	count;

	if (param->type == 'i' || param->type == 'u'
	|| param->type == 'd' || param->type == 'x' || param->type == 'X')
	{
		param->zero = 0;
		if (param->pre_width > (int)ft_strlen(param->final_str))
			count = param->pre_width - (int)ft_strlen(param->final_str);
		else
			count = 0;
		zeros = set_space(count, '0');
		aux = ft_strjoin(zeros, param->final_str);
		param->final_str = aux;
		free(zeros);
	}
	if (param->type == 's')
	{
		aux = ft_substr(param->final_str, 0, param->pre_width);
		param->final_str = aux;
	}
}
