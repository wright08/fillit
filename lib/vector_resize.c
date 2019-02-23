/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_resize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwright <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 21:39:53 by rwright           #+#    #+#             */
/*   Updated: 2019/02/22 17:13:58 by rwright          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include <stdlib.h>

t_vector	*vector_resize(t_vector *v, int capacity)
{
	void	**items;
	int		i;

	if (capacity == 0)
		capacity = 1;
	if ((items = malloc(capacity * sizeof(size_t))))
	{
		i = -1;
		while (++i < v->size)
			items[i] = v->items[i];
		free(v->items);
		v->items = items;
		v->capacity = capacity;
		return (v);
	}
	return (NULL);
}
