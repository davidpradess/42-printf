/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dprades <dprades@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 19:44:10 by dprades           #+#    #+#             */
/*   Updated: 2024/02/21 18:52:51 by dprades          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>

int		ft_printf(char const *str, ...);
int		ft_checks(char const type, va_list args);
int		ft_putchar(int c);
int		ft_putstr(char *str);
long	ft_putnbr(long nb);
long	ft_puthex(unsigned long nb, char *base, int itsptr);

#endif
