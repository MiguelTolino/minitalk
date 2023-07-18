/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 17:31:02 by mangarci          #+#    #+#             */
/*   Updated: 2020/01/16 12:34:26 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_putnbr_base_x(unsigned long int nb, char xcase)
{
	char				*hex;
	char				*base;
	unsigned long int	nbr;
	unsigned long int	len;

	base = (xcase == 'X') ? "0123456789ABCDEF" : "0123456789abcdef";
	len = 0;
	nbr = (nb < 0) ? nb * -1 : nb;
	while (nb != 0)
	{
		len++;
		nb = nb / 16;
	}
	if (nbr == 0)
		len++;
	hex = (char *)malloc(sizeof(char) * (len + 1));
	hex[len] = '\0';
	while (nbr != 0 || len > 0)
	{
		hex[--len] = base[nbr % 16];
		nbr = nbr / 16;
	}
	return (hex);
}
