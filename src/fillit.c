/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwright <rwright@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 20:03:36 by rwright           #+#    #+#             */
/*   Updated: 2019/02/21 17:34:42 by rwright          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		try_place(t_block block, int index, t_byte board[][32],
		int row_col)
{
	int row;
	int col;

	row = (row_col >> 8);
	col = row_col % 8;
	if (board[row + block % 16 / 4][col + block % 16 % 4] ||
			board[row + (block >> 4) % 16 / 4][col + (block >> 4) % 16 % 4] ||
			board[row + (block >> 8) % 16 / 4][col + (block >> 8) % 16 % 4] ||
			board[row + (block >> 12) / 4][col + (block >> 12) % 4])
		return (0);
	board[row + block % 16 / 4][col + block % 16 % 4] = 'A' + index;
	board[row + (block >> 4) % 16 / 4][col + (block >> 4) % 16 % 4] =
		'A' + index;
	board[row + (block >> 8) % 16 / 4][col + (block >> 8) % 16 % 4] =
		'A' + index;
	board[row + (block >> 12) / 4][col + (block >> 12) % 4] = 'A' + index;
	return (1);
}

void	unplace(t_block block, t_byte board[][32], int row, int col)
{
	board[row + block % 16 / 4][col + block % 16 % 4] = 0;
	board[row + (block >> 4) % 16 / 4][col + (block >> 4) % 16 % 4] = 0;
	board[row + (block >> 8) % 16 / 4][col + (block >> 8) % 16 % 4] = 0;
	board[row + (block >> 12) / 4][col + (block >> 12) % 4] = 0;
}

int		get_unplaced(t_uint unplaced, int start)
{
	while (++start < 26)
		if ((1U << start) & unplaced)
			return (start);
	return (-1);
}

int		recur(t_byte board[][32], t_block *blocks, char square,
		t_uint unplaced)
{
	int next;
	int i;
	int j;

	if ((next = get_unplaced(unplaced, -1)) == -1)
		return (1);
	while (next != -1)
	{
		i = -1;
		while (++i < square)
		{
			j = -1;
			while (++j < square)
			{
				if (try_place(blocks[next], next, board, (i << 8) + j))
				{
					if (recur(board, blocks, square, unplaced & ~(1U << next)))
						return (1);
					unplace(blocks[next], board, i, j);
				}
			}
		}
		next = get_unplaced(unplaced, next);
	}
	return (0);
}

void	fillit(t_block *arr, int count)
{
	t_byte	board[32][32];
	t_uint	unplaced;
	char	square;

	unplaced = 0;
	square = -1;
	while (++square < count)
		unplaced = (unplaced << 1U) + 1;
	square = count / 2 + 1;
	make_board(board, square);
	while (!recur(board, arr, square, unplaced) && square < 16)
	{
		square++;
		make_board(board, square);
	}
	print_board(board, square);
}
