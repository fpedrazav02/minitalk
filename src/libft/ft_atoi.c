/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpedraza <fpedraza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:50:17 by fpedraza          #+#    #+#             */
/*   Updated: 2022/03/24 15:25:26 by fpedraza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	long int	num;
	long int	sign;

	num = 0;
	sign = 1;
	while (*nptr == ' ' || (*nptr >= '\t' && *nptr <= '\r'))
		nptr++;
	if (*nptr == '-' && (ft_isdigit(*(nptr + 1))))
	{
		if (*nptr == '-')
			sign *= -1;
		nptr++;
	}
	if (*nptr == '+' && (ft_isdigit(*(nptr + 1))))
		nptr++;
	while (ft_isdigit(*nptr))
	{
		num = num * 10 + *nptr - '0';
		if (num * sign < -2147483648)
			return (0);
		else if (num * sign > 2147483647)
			return (-1);
		nptr++;
	}
	return (num * sign);
}

// int main ()
// {
//   printf("%i\n", ft_atoi(" 12342342ab567"));
//   printf("%i\n", atoi(" 12342342ab567"));
//   return(0);
// }