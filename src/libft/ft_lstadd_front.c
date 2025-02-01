/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpedraza <fpedraza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 21:21:13 by fpedraza          #+#    #+#             */
/*   Updated: 2022/03/29 21:21:13 by fpedraza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **root, t_list *new)
{
	new->next = *root;
	*root = new;
}

/*
Parámetros #1. La dirección de un puntero al primer elemento
de una lista.
#2. La dirección de un puntero al elemento a añadir
a la lista.
Valor devuelto Nada
Funciones autorizadas
Ninguna
Descripción Añade el elemento ’new’ al principio de la lista.
*/
