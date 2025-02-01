/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpedraza <fpedraza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 21:40:26 by fpedraza          #+#    #+#             */
/*   Updated: 2022/03/27 21:40:26 by fpedraza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_array(char *str, unsigned int number, long int nblength)
{
	while (number > 0)
	{
		str[nblength--] = '0' + (number % 10);
		number /= 10;
	}
	return (str);
}

static int	ft_nleght(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char			*str;
	long int		nblength;
	unsigned int	number;

	nblength = ft_nleght(n);
	str = (char *)malloc(sizeof(char) * nblength + 1);
	if (!str)
		return (NULL);
	str[nblength--] = '\0';
	if (n == 0)
		str[0] = '0';
	if (n < 0)
	{
		number = n * -1;
		str[0] = '-';
	}
	else
		number = n;
	str = ft_array(str, number, nblength);
	return (str);
}

// #include<stdio.h>
// int main ()
// {
//   int   a =0;

//   printf("%s", ft_itoa(a));
//   return (0);
// }
