/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpedraza <fpedraza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 20:39:56 by fpedraza          #+#    #+#             */
/*   Updated: 2022/03/22 20:39:56 by fpedraza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (*(unsigned char *)(str + i) == (unsigned char)c)
			return ((void *)(str + i));
		i++;
	}
	return (NULL);
}
// if (!str)         // NO SEGFAULT WHEN ENTERED A NULL PARAMETER //
// 	return (NULL);
// int main () {
//    const char str[] = "http://www.tutorialspoint.com";
//    const char c = 'w';
//    printf("%p\n", ft_memchr(str, c, 2));
//    return(0);
// }
