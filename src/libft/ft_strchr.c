/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpedraza <fpedraza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 20:45:40 by fpedraza          #+#    #+#             */
/*   Updated: 2025/02/01 20:31:35 by fpedraza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Locates the first occurence of c in a string. The null character \0
**	is part of the string
** Input: const char s, int c
** Return:
**		ptr to located char
**		NULL if not in the string
*/
// char	*ft_strchr(const char *str, int c)
// {
// 	while (*str && *str != c)
// 		str++;
// 	if (*str == (char) c)
// 		return ((char *)(str));
// 	return (0);
// }

char	*ft_strchr(char const *str, int c)
{
	char	*ptr;

	ptr = (char *)str;
	while (*ptr)
	{
		if (*ptr == (char)c)
			return (ptr);
		ptr++;
	}
	if (c == 0)
		return (ptr);
	return (0);
}
// #include<stdio.h>
// int main () {
//    const char str[] = "aaaaaaaeaaaaaaa";
//    ft_strchr(str, 'e' + 256);

//    printf("%s",ft_strchr(str, 'e' + 256));
//    return(0);
// }
