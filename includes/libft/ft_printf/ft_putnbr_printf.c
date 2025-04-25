/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafernan <vafernan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:06:40 by vafernan          #+#    #+#             */
/*   Updated: 2025/02/03 15:45:33 by vafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_printf(int nbr)
{
	int	printed_chars;

	printed_chars = 0;
	if (nbr == -2147483648)
	{
		ft_putchar_printf('-');
		ft_putchar_printf('2');
		printed_chars += 2;
		nbr = 147483648;
	}
	if (nbr < 0)
	{
		ft_putchar_printf('-');
		printed_chars++;
		nbr = -nbr;
	}
	if (nbr >= 10)
	{
		printed_chars += ft_putnbr_printf(nbr / 10);
	}
	ft_putchar_printf(nbr % 10 + '0');
	printed_chars++;
	return (printed_chars);
}
