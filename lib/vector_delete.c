/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_delete.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwright <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 14:13:27 by rwright           #+#    #+#             */
/*   Updated: 2019/02/16 08:58:42 by rwright          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include <stdlib.h>

void	vector_delete(t_vector *v, int index)
{
	ft_memmove(v->items + index,
			v->items + index + 1,
			(v->size - index - 1) * sizeof(size_t));
	v->size--;
	if (v->size <= v->capacity / 4)
		vector_resize(v, v->capacity / 4);
}
