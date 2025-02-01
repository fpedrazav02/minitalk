/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpedraza <fpedraza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 20:32:45 by fpedraza          #+#    #+#             */
/*   Updated: 2025/02/01 20:43:54 by fpedraza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include<stdio.h>
#include "libft.h"

// void	ft_bzero(void *s, size_t n)
// {
// 	int	i;

// 	i = 0;
// 	while (n--)
// 		((unsigned char *)s)[i++] = '0';
// }
void	*ft_calloc(size_t nitems, size_t size)
{
	unsigned char	*p;
	size_t			i;

	p = malloc(nitems * size);
	if (p != NULL)
	{
		i = 0;
		while (i < nitems * size)
			*(p + i++) = '\0';
	}
	return (p);
}
/*Dont need to cast back*/
// void	*ft_calloc(size_t nitems, size_t size)
// {
// 	void	*ptr;

// 	ptr = (void *)malloc(nitems * size);
// 	if (ptr != NULL)
// 		ft_bzero(ptr, nitems);
// 	return (ptr);
// }

// int main ()
// {
// 	printf("%s", ft_calloc(4,1));
// 	return (0);
// }
