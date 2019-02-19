/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwright <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 22:25:20 by rwright           #+#    #+#             */
/*   Updated: 2019/01/30 21:10:09 by rwright          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	const t_byte	*s1u;
	const t_byte	*s2u;
	size_t			i;

	s1u = (const t_byte *)s1;
	s2u = (const t_byte *)s2;
	i = 0;
	while (s1u[i])
	{
		if (s1u[i] != s2u[i])
			break ;
		i++;
	}
	return (s1u[i] - s2u[i]);
}
