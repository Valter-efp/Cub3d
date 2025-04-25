/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_printf.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafernan <vafernan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:06:16 by vafernan          #+#    #+#             */
/*   Updated: 2025/02/03 15:45:36 by vafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_printf(int c)
{
	int	printed_chars;

	printed_chars = 0;
	printed_chars += write(1, &c, 1);
	return (printed_chars);
}
