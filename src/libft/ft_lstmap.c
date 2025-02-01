/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpedraza <fpedraza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 21:23:42 by fpedraza          #+#    #+#             */
/*   Updated: 2022/03/29 21:23:42 by fpedraza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *node, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_nodel;
	t_list	*ptr;

	if (!node)
		return (NULL);
	new_nodel = ft_lstnew(f(node->content));
	if (!new_nodel)
		return (NULL);
	ptr = new_nodel;
	node = node->next;
	while (node != NULL)
	{
		new_nodel->next = ft_lstnew(f(node->content));
		if (!new_nodel->next)
		{
			ft_lstclear(&ptr, del);
			return (NULL);
		}
		new_nodel = new_nodel->next;
		node = node->next;
	}
	new_nodel->next = NULL;
	return (ptr);
}

/*
Parámetros ------------------------------------------------------
#1. La dirección de un puntero a un elemento.
#2. La dirección a un puntero a función utilizada
para iterar la lista.
#3. La dirección a un puntero a función utilizado
para eliminar el contenido de un elemento en caso
de requerirse.
Valor devuelto--------------------------------------------------
 La nueva lista. NULL si la reserva falla.
Funciones autorizadas------------------------------------------------
malloc, free
Descripción---------------------------------------------------------
 Itera la lista ’lst’ y aplica la función ’f’ al
contenido de cada elemento. La aplicación correcta
de la función ’f’ sobre cada elemento genera
una nueva lista con estos. La función ’del’ se
utilizará para eliminar el contenido de un elemento
en caso de necesitarse.
--------------------------------------------------------------------
*/
