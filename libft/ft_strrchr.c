/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwright <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 13:10:03 by rwright           #+#    #+#             */
/*   Updated: 2019/01/30 18:30:26 by rwright          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	const char *last;

	last = NULL;
	while (*str)
	{
		if (*str == c)
			last = str;
		str++;
	}
	return ((char *)(*str == c ? str : last));
}
