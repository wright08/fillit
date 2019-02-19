/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwright <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 07:41:43 by rwright           #+#    #+#             */
/*   Updated: 2019/01/30 21:10:21 by rwright          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	const t_byte	*s1u;
	const t_byte	*s2u;
	size_t			i;

	if (!n)
		return (0);
	s1u = (const t_byte *)s1;
	s2u = (const t_byte *)s2;
	i = 0;
	while (i < n && s1u[i])
	{
		if (s1u[i] != s2u[i])
			break ;
		i++;
	}
	return (i == n ? 0 : s1u[i] - s2u[i]);
}
