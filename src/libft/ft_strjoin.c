/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpedraza <fpedraza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 21:33:14 by fpedraza          #+#    #+#             */
/*   Updated: 2022/03/27 21:33:14 by fpedraza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	j;
	size_t	len;

	if (!s1 || !s2)
		return (NULL);
	len = (ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1);
	str = (char *)malloc(sizeof(char) * len);
	if (!str)
		return (NULL);
	i = -1;
	j = 0;
	while (++i, s1[i])
		str[j++] = s1[i];
	i = 0;
	while (s2[i])
	{
		str[j++] = s2[i];
		i++;
	}
	str[j] = 0;
	return (str);
}

// #include<stdio.h>
// int main ()
// {
// 	system("leaks a.out");
// 	char s1[]="hola";
// 	char s2[]="caracola";
// 	printf("%s\n", ft_strjoin(s1, s2));
// 	return (0);
// }
