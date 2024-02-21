/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dprades <dprades@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 19:37:57 by dprades           #+#    #+#             */
/*   Updated: 2024/02/21 20:40:15 by dprades          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_checks(char const type, va_list args)
{
	int	len;

	len = 0;
	if (type == 'c')
		len = ft_putchar(va_arg(args, int));
	else if (type == 's')
		len = ft_putstr(va_arg(args, char *));
	else if (type == 'p')
		len = ft_puthex(va_arg(args, unsigned long), "0123456789abcdef", 1);
	else if (type == 'd' || type == 'i')
		len = ft_putnbr(va_arg(args, int));
	else if (type == 'u')
		len = ft_putnbr(va_arg(args, unsigned int));
	else if (type == 'x')
		len = ft_puthex(va_arg(args, unsigned int), "0123456789abcdef", 0);
	else if (type == 'X')
		len = ft_puthex(va_arg(args, unsigned int), "0123456789ABCDEF", 0);
	else if (type == '%')
		len = ft_putchar('%');
	if (len == -1)
		return (-1);
	return (len);
}

int	ft_printf(char const *str, ...)
{
	int		i;
	int		len;
	va_list	args;

	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
			len += ft_checks(str[++i], args);
		else
			len += write (1, &str[i], 1);
		if (len == -1)
			return (-1);
		i++;
	}
	va_end(args);
	return (len);
}
/*int	main(void)
{
	char	c = 'H';
	char	str[17] = "Hola soy David, ";
	int	i = 123;
	int	*ptr_i = &i;
	int	x = 0x123;

	//printf(" NULL %s NULL\n", NULL);
	//ft_printf(" NULL %s NULL\n", NULL);
	printf(" %c, %sLa direccion de i usando printf es:  %p .Ahora me he encontrado un hexadecimal: %x\n", c, str, (void *)ptr_i, x);
	ft_printf(" %c, %sLa direccion de i usando ft_printf es: %p .Ahora me he encontrado un hexadecimal: %x \n", c, str, (void *)ptr_i, x);
	//print(" %p %p ", LONG_MIN, LONG_MAX);
	//ft_printf(" %p %p ", LONG_MIN, LONG_MAX);
	return (0);
}*/
