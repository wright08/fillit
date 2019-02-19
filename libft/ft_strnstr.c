/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwright <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 11:46:48 by rwright           #+#    #+#             */
/*   Updated: 2019/02/10 20:50:26 by rwright          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t i;
	size_t j;

	if (!*needle)
		return ((char *)haystack);
	i = 0;
	while (i < n && haystack[i])
	{
		j = 0;
		while (i + j < n && needle[j] && needle[j] == haystack[i + j])
			j++;
		if (!needle[j] && i + j <= n)
			return ((char *)(haystack + i));
		i++;
	}
	return (NULL);
}
