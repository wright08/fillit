/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwright <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 21:24:43 by rwright           #+#    #+#             */
/*   Updated: 2019/02/18 14:18:28 by rwright          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int		try_file(t_file *file, void **buff, void **next_line, int *off)
{
	int		total_read;
	int		cur_read;
	void	*new_buff;

	if (file->thread->size > 0)
	{
		*buff = vector_get(file->thread, file->thread->size - 1);
		*off = file->thread->size == 1 ? file->offset : 0;
		if ((*next_line = ft_memchr(*buff + *off, '\n', BUFF_SIZE - *off)))
			return (2);
	}
	if (!(new_buff = ft_memalloc(BUFF_SIZE + 1)))
		return (-1);
	*off = file->thread->size == 1 ? file->offset : 0;
	total_read = 0;
	cur_read = 1;
	while (total_read < BUFF_SIZE && (cur_read = read(file->fd, new_buff +
		total_read, BUFF_SIZE - total_read)) > 0)
		total_read += cur_read;
	if (!total_read)
		free(new_buff);
	else if (!vector_add(file->thread, new_buff))
		return (-1);
	return (cur_read == -1 ? -1 : (total_read > 0));
}

int		try_thread(t_file *file)
{
	void	*next_line;
	void	*buff;
	int		offset;
	int		status;

	while (file->offset > BUFF_SIZE && file->thread->size > 0)
	{
		free(vector_get(file->thread, 0));
		vector_delete(file->thread, 0);
		file->offset -= BUFF_SIZE;
	}
	next_line = NULL;
	while ((status = try_file(file, &buff, &next_line, &offset)) == 1)
		;
	if (status == 0 && file->thread->size > 0)
	{
		buff = vector_get(file->thread, file->thread->size - 1);
		next_line = ft_memchr(buff + offset, '\0', BUFF_SIZE - offset + 1);
		if (next_line - buff == offset)
			return (0);
		status = 1;
	}
	file->next_line = (file->thread->size - 1) * BUFF_SIZE + next_line - buff;
	return (status > 1 ? 1 : status);
}

int		get_line(t_file *file, char **line)
{
	int status;
	int i;

	status = try_thread(file);
	if (status > 0)
	{
		if (!(*line = malloc(file->next_line - file->offset + 1)))
			return (-1);
		(*line)[file->next_line - file->offset] = '\0';
		i = file->next_line / BUFF_SIZE;
		ft_memcpy(*line, vector_get(file->thread, 0) + file->offset,
				(i == 0 ? file->next_line : BUFF_SIZE) - file->offset);
		if (i > 0)
		{
			ft_memcpy(*line + (i - 1) * BUFF_SIZE + BUFF_SIZE - file->offset,
					vector_get(file->thread, i), file->next_line % BUFF_SIZE);
			while (--i)
				ft_memcpy(
						*line + (i - 1) * BUFF_SIZE + BUFF_SIZE - file->offset,
						vector_get(file->thread, i), BUFF_SIZE);
		}
		file->offset = file->next_line + 1;
		status = 1;
	}
	return (status);
}

int		get_file(t_vector *threads, int fd)
{
	t_file	*file;
	int		i;

	if (fd < 0)
		return (-1);
	i = 0;
	while (i < threads->size && ((t_file *)vector_get(threads, i))->fd != fd)
		i++;
	if (i == threads->size)
	{
		if ((file = malloc(sizeof(t_file))))
		{
			file->fd = fd;
			file->offset = 0;
			file->next_line = 0;
			if (!(file->thread = vector_new(2)) || !(vector_add(threads, file)))
				return (-1);
		}
		else
			return (-1);
	}
	return (i);
}

int		get_next_line(const int fd, char **line)
{
	static t_vector	*threads = NULL;
	t_file			*file;
	int				file_index;
	int				status;

	if (BUFF_SIZE == 0 || !(threads || (threads = vector_new(4))))
		return (-1);
	if ((file_index = get_file(threads, fd)) < 0)
		return (-1);
	file = vector_get(threads, file_index);
	status = get_line(file, line);
	if (status < 1 && file->thread->size > 0)
	{
		free(vector_get(file->thread, 0));
		vector_free(file->thread);
		free(file);
		vector_delete(threads, file_index);
		*line = NULL;
	}
	else
		file->next_line = 0;
	return (status);
}
