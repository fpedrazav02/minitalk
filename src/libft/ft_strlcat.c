/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpedraza <fpedraza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 20:54:34 by fpedraza          #+#    #+#             */
/*   Updated: 2022/03/24 15:01:29 by fpedraza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	s_len;
	size_t	d_len;

	d_len = ft_strlen(dst);
	s_len = ft_strlen((char *)src);
	i = 0;
	j = d_len;
	if (size <= d_len)
		return (s_len + size);
	while (src[i] && i < size - d_len - 1)
		dst[j++] = src[i++];
	dst[j] = '\0';
	return (d_len + s_len);
}
// int main ()
// {
//   char src[]="CARACOLA";
//   char dest[50]="HOLA";
//   ft_strlcat(dest, src, 7);
//   printf("%s\n", dest);
//   printf("%i\n", ft_strlcat(dest, src, 7));
//   return(0);
// }