/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpedraza <fpedraza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 21:21:57 by fpedraza          #+#    #+#             */
/*   Updated: 2022/03/29 21:21:57 by fpedraza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **node, void (*del)(void*))
{
	t_list	*aux;
	t_list	*ptr;

	ptr = *node;
	while (ptr != NULL)
	{
		aux = ptr->next;
		ft_lstdelone(ptr, del);
		ptr = aux;
	}
	*node = NULL;
}

/*
Parámetros #1. La dirección del puntero a un elemento.
#2. Un puntero a la función utilizada para eliminar
el contenido de cada elemento.
Valor devuelto Nada
Funciones autorizadas
free
Descripción Elimina y libera cada uno de los elementos de la
lista dada, utilizando la función ’del’ y free(3).
Por último, el puntero a la lista debe ponerse a
NULL.
*/
