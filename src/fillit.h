/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwright <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 13:12:30 by rwright           #+#    #+#             */
/*   Updated: 2019/02/19 16:46:26 by rwright          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"
# include <stdlib.h> // Exit, malloc, free

struct s_block
{
	int		height;
	int		width;
	char	**block;
};

typedef struct s_block	t_block;

/*
**	PARSE
*/
int		parse(char *file, t_block **blocks);

#endif
