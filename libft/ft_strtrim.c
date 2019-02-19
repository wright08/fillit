/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwright <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 21:40:48 by rwright           #+#    #+#             */
/*   Updated: 2019/02/13 01:43:28 by rwright          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_strtrim(const char *s)
{
	char	*ret;
	int		start;
	int		end;

	start = 0;
	while (ft_isspace(s[start]))
		start++;
	end = start;
	while (s[end + 1])
		end++;
	while (ft_isspace(s[end]))
		end--;
	if (start == 0 && !ft_isspace(s[end + 1]))
		return (ft_strdup(s));
	if ((ret = malloc(end - start + 2)))
	{
		ft_memcpy(ret, s + start, end - start + 1);
		ret[end - start + 1] = '\0';
	}
	return (ret);
}
