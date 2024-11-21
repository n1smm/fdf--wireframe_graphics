/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:26:25 by tjuvan            #+#    #+#             */
/*   Updated: 2023/11/08 17:51:12 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	which_format(char specifier, va_list ap)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count += put_char(va_arg(ap, int));
	else if (specifier == 's')
		count += put_str(va_arg(ap, char *));
	else if (specifier == 'i' || specifier == 'd')
		count = put_nbr(va_arg(ap, int), 10, &count, 'i');
	else if (specifier == 'u')
		count = put_nbr(va_arg(ap, unsigned int), 10, &count, 'u');
	else if (specifier == 'x')
		count = put_nbr(va_arg(ap, unsigned int), 16, &count, 'x');
	else if (specifier == 'X')
		count = put_nbr(va_arg(ap, unsigned int), 16, &count, 'X');
	else if (specifier == 'p')
		count = put_address(va_arg(ap, void *), &count);
	else if (specifier == '%')
		count += put_char('%');
	else
		count += write(1, &specifier, 1);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		count;

	count = 0;
	va_start(ap, str);
	while (*str != 0)
	{
		if (*str == '%')
			count += which_format(*(++str), ap);
		else
		{
			write(1, str, 1);
			count++;
		}
		str++;
	}
	va_end(ap);
	return (count);
}

/*
int	main(void)
{
	printf("%p\t%p\t%p\t%p\n", LONG_MIN, LONG_MAX, ULONG_MAX, -ULONG_MAX);
	ft_printf("%p\t%p\t%p\t%p\n", LONG_MIN, LONG_MAX, ULONG_MAX, -ULONG_MAX);

	printf("%X\t%X\t%i\t%i\n", 123456,1234567890, -1234, -1234);
	ft_printf("%X\t%X\t%i\t%i\n", 123456,1234567890, -1234, -1234);

	int	count;
	int	num = 0;
	int	num2 = 0;
	char	*str = NULL;

	count = printf("%i\n", num2);
	printf("writte the number of chars orig i: %i\n", count);
	count = printf("\n");
	printf("writte the number of chars orig no: %i\n", count);
	count = ft_printf("%i\n", num2);
	ft_printf("writte the number of chars my i: %i\n", count);
	count = ft_printf("\n");
	ft_printf("writte the number of chars my no: %i\n", count);
	printf("writte the number of chars: %i\n", count);

	printf("total len: %d\n\n", ft_printf("char %c\tstring %s\tadress
			%p\tdecimal %d\tint %i\tunsigned %u\t hexsmall %x\thexbig
			%X\t modulo %%\n", 'c', str, NULL, num, num, num, num, num));
	printf("total len: %d\n\n", printf("char %c\tstring %s\tadress %p\tdecimal
			%d\tint %i\tunsigned %u\t hexsmall %x\thexbig %X\t modulo %%\n",
			'c', str, NULL, num, num, num, num, num));
//	num = 12345;
	ft_printf("total len: %d\n\n", ft_printf("char %c\tstring %s\tadress
			%p\tdecimal %d\tint %i\tunsigned %u\t hexsmall %x\thexbig
			%X\t modulo %%\n", 'c', "string", &num, num, num, num, num, num));
	ft_printf("total len: %d\n\n", printf("char %c\tstring %s\tadress
			%p\tdecimal %d\tint %i\tunsigned %u\t hexsmall %x\thexbig
			%X\t modulo %%\n", 'c', "string", &num, num, num, num, num, num));

}*/
