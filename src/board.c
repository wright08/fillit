/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwright <rwright@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 16:26:25 by rwright           #+#    #+#             */
/*   Updated: 2019/02/21 17:36:24 by rwright          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_board(t_byte board[][32], char square)
{
	int i;
	int j;

	i = 0;
	while (i < square)
	{
		j = -1;
		while (++j < square)
		{
			if (board[i][j] == 0)
				ft_putchar('.');
			else
				ft_putchar(board[i][j]);
		}
		ft_putendl("");
		i++;
	}
}

void	make_board(t_byte board[][32], char square)
{
	int i;

	ft_bzero(board, 32 * 32 * sizeof(t_byte));
	i = -1;
	while (++i < square)
		board[i][(int)square] = 1;
	i = -1;
	while (++i < square)
		board[(int)square][i] = 1;
}
