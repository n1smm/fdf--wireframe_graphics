/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:02:01 by tjuvan            #+#    #+#             */
/*   Updated: 2023/11/08 17:50:22 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <stdint.h>
# include <unistd.h>

//	-include functions for tests-
# include <stdio.h>
# include <stdlib.h>

/* main functions */
int	which_format(char specifier, va_list ap);
int	ft_printf(const char *str, ...);
/* simple functions */
int	put_char(int c);
int	put_str(char *str);
/* arithmetic functions */
int	put_nbr(long num, int base, int *count, char upcase);
int	put_address(void *ptr, int *count);
int	put_add(unsigned long long num, int base, int *count, char upcase);

#endif
