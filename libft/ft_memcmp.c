/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwright <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 19:02:56 by rwright           #+#    #+#             */
/*   Updated: 2019/02/10 22:08:59 by rwright          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const t_byte	*s1p;
	const t_byte	*s2p;
	size_t			i;

	if (n)
	{
		s1p = s1;
		s2p = s2;
		i = 0;
		while (i < n)
		{
			if (s1p[i] != s2p[i])
				return (s1p[i] - s2p[i]);
			i++;
		}
	}
	return (0);
}
