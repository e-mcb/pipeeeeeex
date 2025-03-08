/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzutter <mzutter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 21:28:05 by mzutter           #+#    #+#             */
/*   Updated: 2025/03/07 21:13:44 by mzutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	ft_open(char *argv, int i)
{
	int	file;

	file = 0;
	if (i == 0)
		file = open(argv, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (i == 1)
		file = open(argv, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (file == -1)
		ft_error("failed to open the file");
	if (i == 2)
		file = open(argv, O_RDONLY, 0644);
	return (file);
}

void	ft_child_process(char *cmd, char **envp, int in_fd, int out_fd)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		if (in_fd != STDIN_FILENO)
		{
			if (in_fd == -1)
				ft_error("failed to open file");
			dup2(in_fd, STDIN_FILENO);
			close(in_fd);
		}
		if (out_fd != STDOUT_FILENO)
		{
			dup2(out_fd, STDOUT_FILENO);
			close(out_fd);
		}
		ft_exec_cmd(cmd, envp);
	}
}

void	ft_pipex(int argc, char **argv, char **envp, int fd_io[2])
{
	int	i;
	int	pipe_fd[2];

	i = 2;
	if (argc > 5 && strcmp(argv[1], "here_doc") == 0)
		i = 3;
	while (i < argc - 2)
	{
		if (pipe(pipe_fd) == -1)
		{
			perror("pipe");
			exit(EXIT_FAILURE);
		}
		ft_child_process(argv[i], envp, fd_io[0], pipe_fd[1]);
		close(pipe_fd[1]);
		fd_io[0] = pipe_fd[0];
		i++;
	}
	ft_child_process(argv[argc - 2], envp, fd_io[0], fd_io[1]);
	close(fd_io[0]);
	close(fd_io[1]);
}

int	main(int argc, char **argv, char **envp)
{
	int	fd_io[2];
	int	i;

	if (argc < 5)
		write(2, "Wrong format, expected ./pipex file1 cmd1 cmd2 file2", 53);
	if (argc > 5 && strcmp(argv[1], "here_doc") == 0)
	{
		fd_io[1] = ft_open(argv[argc - 1], 0);
		ft_handle_heredoc(argc, argv[2]);
		secure_dup2(fd_io[1], STDOUT_FILENO);
		fd_io[0] = STDIN_FILENO;
	}
	else
	{
		fd_io[0] = ft_open(argv[1], 2);
		fd_io[1] = ft_open(argv[argc - 1], 1);
	}
	ft_pipex(argc, argv, envp, fd_io);
	i = 0;
	while (i++ < argc - 3)
		wait(NULL);
	return (close(fd_io[0]), close(fd_io[1]), 0);
}
