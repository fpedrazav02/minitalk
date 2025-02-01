/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpedraza <fpedraza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 21:19:46 by fpedraza          #+#    #+#             */
/*   Updated: 2022/03/29 21:19:46 by fpedraza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **root, t_list *new)
{
	t_list	*ptr;

	ptr = ft_lstlast(*root);
	if (ptr != NULL)
		ptr->next = new;
	else
		*root = new;
}

/*
Parámetros #1. La dirección de un puntero al primer elemento
de una lista.
#2. Un puntero al elemento nuevo que añadir a la
lista.
Valor devuelto Nada
Funciones autorizadas
Ninguna
Descripción Añade el elemento ’new’ al final de una lista
*/
