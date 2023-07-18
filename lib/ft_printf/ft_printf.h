/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 18:55:49 by mmateo-t          #+#    #+#             */
/*   Updated: 2020/01/16 17:40:05 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_PRINTF_H
# define _FT_PRINTF_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"

typedef	struct	s_parameters
{
	unsigned int	len;
	unsigned int	precision;
	int				width;
	unsigned int	minus;
	unsigned int	zero;
	char			*str;
	va_list			ap;
	char			*final_str;
	char			type;
	unsigned int	noprint;
	int				pre_width;
	unsigned int	negative_int_with_zeros;
	char			special_char;
}				t_parameters;

int				convert_to_char(t_parameters *param);
size_t			ft_strlen(const char *str);
char			*ft_itoa(int n);
void			print_int(t_parameters *param);
void			print_string(t_parameters *param);
void			print_char(t_parameters *param);
void			print_percent(t_parameters *param);
void			print_uint(t_parameters *param);
void			get_width(t_parameters *param);
void			precision(t_parameters *param);
char			*ft_putnbr_base_x(unsigned long int num, char xcase);
int				format(t_parameters *param);
void			print_final_str(t_parameters *param);
void			modify_width(t_parameters *param);
void			modify_precision(t_parameters *param);
void			modify_adress(t_parameters *param);
void			print_hex(t_parameters *param);
void			print_pointer(t_parameters *param);
int				ft_printf(const char *string, ...);
void			no_print(t_parameters *param);

#endif
