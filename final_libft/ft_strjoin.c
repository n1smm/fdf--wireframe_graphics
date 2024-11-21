/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <tjuvan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 15:21:34 by tjuvan            #+#    #+#             */
/*   Updated: 2024/01/24 18:33:56 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	count_later;
	size_t	count;
	char	*twin;

	count = 0;
	count_later = count;
	twin = (char *) malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!twin || !s1 || !s2)
		return (NULL);
	while (s1[count])
	{
		twin[count] = s1[count];
		count++;
	}
	while (s2[count_later])
	{
		twin[count] = s2[count_later];
		count++;
		count_later++;
	}
	twin[count] = 0;
	return (twin);
}
/*
int	main(void)
{
 	char *s1 = "where is my ";
    char *s2 = "malloc ???";
    char *s3 = "where is my malloc ???";
	char *res = ft_strjoin(s1, s2);

	if (!strcmp(res, s3))
	{
                free(res);
				puts("TEST_SUCCESS");
	}
    else
	{
		puts("TEST_FAILED");
		free(res);
	}
}*/
