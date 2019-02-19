/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwright <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 21:33:51 by rwright           #+#    #+#             */
/*   Updated: 2019/02/10 20:18:11 by rwright          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int	i;

	if (!*needle)
		return ((char *)haystack);
	while (*haystack)
	{
		i = 0;
		while (needle[i] && needle[i] == haystack[i])
			i++;
		if (!needle[i])
			return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}
