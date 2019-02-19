/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwright <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 21:05:52 by rwright           #+#    #+#             */
/*   Updated: 2019/02/17 10:14:01 by rwright          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include "libft.h"
# include <stddef.h>

typedef	struct	s_vector
{
	int		capacity;
	int		size;
	void	**items;
}				t_vector;


void		*vector_add(t_vector *v, void *item);
void		vector_delete(t_vector *v, int index);
void		vector_free(t_vector *v);
void		*vector_get(t_vector *v, int index);
t_vector	*vector_new(int capacity);
t_vector	*vector_resize(t_vector *v, int capacity);
void		vector_set(t_vector *v, int index, void *item);

#endif
