/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafernan <vafernan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:07:51 by vafernan          #+#    #+#             */
/*   Updated: 2025/02/03 15:45:27 by vafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putptr_recursive(unsigned long n);
static int	ft_count_hexa(unsigned long n);

static void	ft_putptr_recursive(unsigned long n)
{
	if (n > 0 && n <= 15)
	{
		write(1, &"0123456789abcdef"[n], 1);
	}
	else
	{
		ft_putptr_recursive(n / 16);
		ft_putptr_recursive(n % 16);
	}
}

static int	ft_count_hexa(unsigned long n)
{
	int	printed_chars;

	printed_chars = 0;
	while (n > 0)
	{
		n = n / 16;
		printed_chars++;
	}
	return (printed_chars);
}

int	ft_putptr(unsigned long n)
{
	int	printed_chars;

	printed_chars = 0;
	if (n == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	else
	{
		write(1, "0x", 2);
		printed_chars = 2 + ft_count_hexa(n);
		ft_putptr_recursive(n);
	}
	return (printed_chars);
}
