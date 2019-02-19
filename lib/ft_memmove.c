/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwright <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 19:25:25 by rwright           #+#    #+#             */
/*   Updated: 2019/02/13 01:29:04 by rwright          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	void *end;

	if (dst == src || !n)
		return (dst);
	else if (dst > src)
		return (ft_memcpy(dst, src, n));
	end = dst + n;
	while (dst != end)
		*((t_byte *)dst++) = *((const t_byte *)src++);
	return (dst - n);
}
