/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpedraza <fpedraza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 21:23:08 by fpedraza          #+#    #+#             */
/*   Updated: 2022/03/29 21:23:08 by fpedraza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *root)
{
	if (root == NULL)
		return (NULL);
	while (root != NULL)
	{
		if (root->next == NULL)
			return (root);
		root = root->next;
	}
	return (root);
}

/*
Parámetros #1. El principio de una lista.
Valor devuelto Último elemento de una lista.
Funciones autorizadas
Ninguna
Descripción Devuelve el último elemento de una lista.
*/
