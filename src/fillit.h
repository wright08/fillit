/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwright <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 13:12:30 by rwright           #+#    #+#             */
/*   Updated: 2019/02/21 17:35:08 by rwright          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"
# include <stdlib.h>

typedef unsigned short	t_block;
typedef unsigned int	t_uint;

void	print_board(t_byte board[][32], char square);
void	make_board(t_byte board[][32], char square);
void	fillit(t_block *arr, int count);
int		parse(char *file, t_block *arr, int *count);

#endif
