/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzutter <mzutter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 23:34:35 by mzutter           #+#    #+#             */
/*   Updated: 2025/02/27 04:05:39 by mzutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	secure_dup2(int old_fd, int new_fd)
{
	if (dup2(old_fd, new_fd) == -1)
	{
		perror("dup2 failed");
		exit(EXIT_FAILURE);
	}
}

void	ft_error(const char *message)
{
	perror(message);
	exit(EXIT_FAILURE);
}

int	handle_input_output(int argc, char **argv)
{
	int	in;
	int	out;

	in = ft_open(argv[1], 2);
	out = ft_open(argv[argc - 1], 1);
	secure_dup2(in, STDIN_FILENO);
	return (out);
}
