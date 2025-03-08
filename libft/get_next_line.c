/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzutter <mzutter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 11:13:01 by mzutter           #+#    #+#             */
/*   Updated: 2025/02/19 23:30:23 by mzutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*check_storage(char *storage)
{
	if (!storage)
		storage = ft_strdup("");
	if (!storage)
		return (NULL);
	return (storage);
}

static char	*reader_function(int fd, char *storage, char *buffer)
{
	char	*str;
	ssize_t	read_value;

	read_value = 1;
	while (read_value)
	{
		read_value = read(fd, buffer, BUFFER_SIZE);
		if (read_value <= 0)
		{
			if (read_value == 0)
				break ;
			return (NULL);
		}
		buffer[read_value] = 0;
		storage = check_storage(storage);
		str = storage;
		storage = ft_strjoin(str, buffer);
		free (str);
		str = NULL;
		if (!storage)
			return (NULL);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (storage);
}

static char	*extract_line(char *next_line)
{
	char	*storage;
	size_t	i;

	i = 0;
	while (next_line[i] != '\n' && next_line[i] != 0)
		i++;
	if (next_line[i] == 0 || next_line[i + 1] == 0)
		return (NULL);
	storage = ft_substr(next_line, i + 1, ft_strlen(next_line) - i);
	if (!storage)
	{
		free(storage);
		storage = NULL;
	}
	next_line[i + 1] = 0;
	return (storage);
}

char	*get_next_line(int fd)
{
	static char	*storage;
	char		*buffer;
	char		*next_line;

	buffer = malloc((size_t)BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(buffer);
		buffer = NULL;
		free(storage);
		storage = NULL;
		return (NULL);
	}
	next_line = reader_function(fd, storage, buffer);
	free(buffer);
	if (!next_line)
	{
		free (storage);
		storage = NULL;
		return (NULL);
	}
	storage = extract_line(next_line);
	return (next_line);
}
