/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwright <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 15:42:36 by rwright           #+#    #+#             */
/*   Updated: 2019/01/30 20:44:16 by rwright          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(const void *content, size_t content_size)
{
	t_list *ret;

	if ((ret = malloc(sizeof(t_list))))
	{
		if ((ret->content = malloc(content_size)))
		{
			if (content)
			{
				ft_memcpy(ret->content, content, content_size);
				ret->content_size = content_size;
			}
			else
			{
				ret->content = 0;
				ret->content_size = 0;
			}
			ret->next = NULL;
		}
	}
	return (ret);
}
