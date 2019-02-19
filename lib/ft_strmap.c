/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwright <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 20:31:10 by rwright           #+#    #+#             */
/*   Updated: 2019/01/30 19:35:34 by rwright          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmap(const char *s, char (*f)(char))
{
	char	*ptr;
	int		i;

	if ((ptr = malloc(ft_strlen(s) + 1)))
	{
		i = 0;
		while (s[i])
		{
			ptr[i] = (*f)(s[i]);
			i++;
		}
		ptr[i] = '\0';
	}
	return (ptr);
}
