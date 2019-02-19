/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwright <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 21:05:20 by rwright           #+#    #+#             */
/*   Updated: 2019/02/13 01:44:32 by rwright          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*ret;
	int		s1_len;
	int		s2_len;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if ((ret = malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
	{
		ft_memcpy(ret, s1, s1_len);
		ft_memcpy(ret + s1_len, s2, s2_len + 1);
	}
	return (ret);
}
