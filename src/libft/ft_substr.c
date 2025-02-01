/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpedraza <fpedraza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 21:39:09 by fpedraza          #+#    #+#             */
/*   Updated: 2022/03/27 21:39:09 by fpedraza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int		i;
	char	*ptr;

	if (!s)
		return (NULL);
	if (ft_strlen((char *)s) < start)
		len = 0;
	if (ft_strlen((char *)s + start) < len)
		len = ft_strlen((char *)s + start);
	i = 0;
	ptr = malloc(sizeof(char) * len + 1);
	if (!ptr)
		return (NULL);
	while (len--)
		ptr[i++] = s[start++];
	ptr[i] = 0;
	return (ptr);
}

// int main ()
// {
//   char s[]="holacaracola";
//   printf("%s\n", ft_substr(s, 0,4));
//   return (0);
// }
