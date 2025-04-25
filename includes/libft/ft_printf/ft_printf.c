/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafernan <vafernan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 15:31:57 by vafernan          #+#    #+#             */
/*   Updated: 2025/02/03 15:45:42 by vafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_format(char c, va_list ap)
{
	int	printed_chars;

	printed_chars = 0;
	if (!c)
		return (0);
	else if (c == 'c')
		printed_chars += ft_putchar_printf(va_arg(ap, int));
	else if (c == 's')
		printed_chars += ft_putstr_printf(va_arg(ap, char *));
	else if (c == 'p')
		printed_chars += ft_putptr(va_arg(ap, unsigned long));
	else if (c == 'd' || c == 'i')
		printed_chars += ft_putnbr_printf(va_arg(ap, int));
	else if (c == 'u')
		printed_chars += ft_utoa(va_arg(ap, unsigned int));
	else if (c == 'x' || c == 'X')
		printed_chars += ft_putnbrhex(va_arg(ap, int), c);
	else if (c == '%')
		printed_chars += write(1, "%", 1);
	return (printed_chars);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		printed_chars;

	va_start(ap, str);
	printed_chars = 0;
	if (!str)
		return (0);
	while (*str != 0)
	{
		if (*str == '%')
			printed_chars += ft_format(*(++str), ap);
		else
			printed_chars += write(1, str, 1);
		++str;
	}
	va_end(ap);
	return (printed_chars);
}
