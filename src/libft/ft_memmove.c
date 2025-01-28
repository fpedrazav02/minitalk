/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpedraza <fpedraza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 20:43:09 by fpedraza          #+#    #+#             */
/*   Updated: 2022/03/22 20:43:09 by fpedraza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	char	*dst;
	char	*s;

	dst = (char *)dest;
	s = (char *)src;
	if (s < dst)
	{
		dst += len - 1;
		s += len - 1;
		while (len--)
			*dst-- = *s--;
	}
	else
		ft_memcpy(dest, (void *)src, len);
	return (dest);
}

// int main () {
//    char dest[] = "oldstring";
//    const char src[]  = "newstring";

//    printf("Before memmove dest = %s, src = %s\n", dest, src);
//    ft_memmove(dest, src, 2);
//    printf("After memmove dest = %s, src = %s\n", dest, src);
//    return(0);
// }