/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwright <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 14:20:43 by rwright           #+#    #+#             */
/*   Updated: 2019/02/13 01:17:34 by rwright          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t i;

	i = 0;
	while (i < n && ((t_byte *)src)[i] != (t_byte)c)
		i++;
	ft_memcpy(dst, src, (i == n ? i : i + 1));
	if (i == n)
		return (NULL);
	return (dst + i + 1);
}
