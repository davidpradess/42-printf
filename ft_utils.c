/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dprades <dprades@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 19:38:15 by dprades           #+#    #+#             */
/*   Updated: 2024/02/21 19:50:39 by dprades          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	if (write (1, &c, 1) == -1)
		return (-1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		str = "(null)";
	while (str[i] != '\0')
	{
		if (ft_putchar(str[i]) == -1)
			return (-1);
		i++;
	}
	return (i);
}

long	ft_putnbr(long nb)
{
	long	len;

	len = 0;
	if (nb < 0)
	{
		if (ft_putchar('-') == -1)
			return (-1);
		nb = nb * -1;
		len++;
	}
	if (nb > 9)
	{
		len += ft_putnbr(nb / 10);
		if (len == -1)
			return (-1);
	}
	if (ft_putchar(nb % 10 + 48) == -1)
		return (-1);
	else
		len++;
	return (len);
}

long	ft_puthex(unsigned long nb, char *base, int itsptr)
{
	long	len;

	len = 0;
	if (itsptr == 1)
	{
		if (ft_putstr("0x") == -1)
			return (-1);
		len += 2;
	}
	if (nb >= 16)
	{
		len += ft_puthex(nb / 16, base, 0);
		if (len == -1)
			return (-1);
	}
	if (ft_putchar(base[nb % 16]) == -1)
		return (-1);
	else
		len++;
	return (len);
}
