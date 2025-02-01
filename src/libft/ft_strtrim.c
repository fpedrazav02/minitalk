/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpedraza <fpedraza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 20:43:20 by fpedraza          #+#    #+#             */
/*   Updated: 2025/02/01 20:43:20 by fpedraza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_char(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	int		i;
	int		start;
	int		end;

	if (!s1)
		return (NULL);
	start = 0;
	while (s1[start] && ft_check_char(s1[start], set))
		start++;
	end = ft_strlen((char *)s1);
	while (end > start && ft_check_char(s1[end - 1], set))
		end--;
	ptr = (char *)malloc(sizeof(char) * end - start + 1);
	if (!ptr)
		return (NULL);
	i = 0;
	while (start < end)
		ptr[i++] = s1[start++];
	ptr[i] = '\0';
	return (ptr);
}

// int main ()
// {
//   char s[]=" 1holacaracola1 ";
//   char set[]=" 1";
//   printf("%s\n", ft_strtrim(s,set));
//   return (0);
// }
