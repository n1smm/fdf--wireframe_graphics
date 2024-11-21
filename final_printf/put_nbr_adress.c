/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_nbr_adress.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:48:27 by tjuvan            #+#    #+#             */
/*   Updated: 2023/11/08 17:50:53 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_nbr(long num, int base, int *count, char upcase)
{
	int		digit;
	char	*symbols;

	if (upcase == 'X')
		symbols = "0123456789ABCDEF";
	else
		symbols = "0123456789abcdef";
	if (num < 0)
	{
		*count += write(1, "-", 1);
		num = -num;
	}
	if (num >= base)
		put_nbr(num / base, base, count, upcase);
	digit = num % base;
	*count += write(1, &symbols[digit], 1);
	return (*count);
}

int	put_add(unsigned long long num, int base, int *count, char upcase)
{
	int		digit;
	char	*symbols;

	symbols = "0123456789abcdef";
	if (num < 0)
	{
		*count += write(1, "-", 1);
		num = -num;
	}
	if (num >= base)
		put_nbr(num / base, base, count, upcase);
	digit = num % base;
	*count += write(1, &symbols[digit], 1);
	return (*count);
}

int	put_address(void *ptr, int *count)
{
	uintptr_t	adress;

	adress = (uintptr_t)ptr;
	if (!ptr)
	{
		*count += write(1, "(nil)", 5);
		return (*count);
	}
	*count += write(1, "0x", 2);
	put_add(adress, 16, count, 'p');
	return (*count);
}
