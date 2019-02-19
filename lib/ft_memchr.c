/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwright <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 19:10:21 by rwright           #+#    #+#             */
/*   Updated: 2019/01/21 22:05:43 by rwright          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memchr(const void *s, int c, size_t n)
{
	const t_byte	*sp;
	size_t			i;

	sp = s;
	i = 0;
	while (i < n)
	{
		if (sp[i] == (t_byte)c)
			return ((void *)(sp + i));
		i++;
	}
	return (NULL);
}
