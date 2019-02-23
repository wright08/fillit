/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwright <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 15:53:35 by rwright           #+#    #+#             */
/*   Updated: 2019/02/22 17:14:56 by rwright          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include <stdlib.h>

t_vector	*vector_new(int capacity)
{
	t_vector *v;

	if ((v = malloc(sizeof(t_vector))))
	{
		v->size = 0;
		v->capacity = capacity;
		if (!(v->items = malloc(capacity * sizeof(size_t))))
			return (NULL);
	}
	return (v);
}
