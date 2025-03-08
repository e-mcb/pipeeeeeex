/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzutter <mzutter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 04:05:03 by mzutter           #+#    #+#             */
/*   Updated: 2025/03/05 01:03:15 by mzutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_gnl_heredoc(int fd[2], char *limiter)
{
	char	*line;

	close(fd[0]);
	while (1)
	{
		write(1, "pipe heredoc>", 13);
		line = get_next_line(0);
		if (!line || (limiter[0] == 0 && line[0] == '\n')
			|| ft_strncmp(line, limiter, ft_strlen(limiter)) == 0)
		{
			free(line);
			exit(EXIT_SUCCESS);
		}
		ft_putstr_fd(line, fd[1]);
		free(line);
	}
}

void	ft_handle_heredoc(int argc, char *limiter)
{
	pid_t	pid;
	int		fd[2];

	if (argc < 6)
		ft_error("Format error: Expected \"./pipex"
			"here_doc LIMITER cmd cmd1 file\"");
	if (pipe(fd) == -1)
		ft_error("Failed to create pipe");
	pid = fork ();
	if (pid == 0)
		ft_gnl_heredoc(fd, limiter);
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		wait(NULL);
	}
}

void	open_heredoc(int argc, char **argv)
{
	int	out;

	out = ft_open(argv[argc - 1], 0);
	ft_handle_heredoc(argc, argv[2]);
	secure_dup2(out, STDOUT_FILENO);
}
