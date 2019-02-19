/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwright <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 20:47:24 by rwright           #+#    #+#             */
/*   Updated: 2019/01/30 19:43:36 by rwright          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strsub(char *s, unsigned int start, size_t len)
{
	char	*ptr;

	if ((ptr = malloc(len + 1)))
	{
		ft_memcpy(ptr, s + start, len);
		ptr[len] = '\0';
	}
	return (ptr);
}
