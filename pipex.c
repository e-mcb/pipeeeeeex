/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzutter <mzutter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 22:36:43 by mzutter           #+#    #+#             */
/*   Updated: 2025/03/08 01:02:15 by mzutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	free_paths(char **cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
	{
		free(cmd[i]);
		i++;
	}
	free(cmd);
	perror("command not found");
	exit(127);
}

// splits the command from its options
// finds the path of the command
// executes it
// void	ft_exec_cmd(char *argv, char **envp)
// {
// 	char	**cmd;
// 	char	*path;
// 	char	*trim;
// 	int		i;

// 	i = 0;
// 	cmd = ft_split2(argv, ' ');
// 	while (cmd[i])
// 	{
// 		trim = trim_quotes(cmd[i]);
// 		if (trim)
// 		{
// 			free(cmd[i]);
// 			cmd[i] = trim;
// 		}
// 		i++;
// 	}
// 	path = ft_pathfinder(cmd[0], envp);
// 	if (!path)
// 		free_paths(cmd);
// 	if (execve(path, cmd, envp) == -1)
// 		ft_error("execve failed");
// }

// int	ft_exec_cmd(char *argv, char **envp)
// {
// 	char	**cmd;
// 	char	*path;
// 	char	*trim;
// 	int		i;

// 	i = 0;
// 	cmd = ft_split2(argv, ' ');
// 	if (!cmd)
// 		return(ft_putstr_fd("Error:Malloc failed\n", 2), 0);
// 	while (cmd[i])
// 	{
// 		trim = trim_quotes(cmd[i]);
// 		if (trim)
// 		{
// 			free(cmd[i]);
// 			cmd[i] = trim;
// 		}
// 		i++;
// 	}
// 	path = ft_pathfinder(cmd[0], envp);
// 	if (!path)
// 		free_paths(cmd);
// 	if (execve(path, cmd, envp) == -1)
// 	{
// 		ft_error("execve failed");
// 		return (1);
// 	}
// 	return (0);
// }



int	ft_exec_cmd(char *argv, char **envp)
{
	char	**cmd;
	char	*path;
	char	*trim;
	int		i;

	i = 0;
	cmd = ft_split2(argv, ' ');
	if (!cmd)
		return(ft_putstr_fd("Error:Malloc failed\n", 2), 0);
	while (cmd[i])
	{
		trim = trim_quotes(cmd[i]);
		if (trim)
		{
			free(cmd[i]);
			cmd[i] = trim;
		}
		i++;
	}
	path = helper_path(cmd, envp);
	if (execve(path, cmd, envp) == -1)
	{
		ft_error("execve failed");
		return (1);
	}
	return (0);
}

// opens the file2, creates it if it doesnt exist
// deletes its content if it exists
// redirect STDIN to fd[0] (read) 
// to read from the child process
// redirects STDOUT to file2 (write)
// closes file2, fd[0] and fd[1]
// executes the cmd2
// writes its output into file2

// void	ft_parent_process(char **argv, char **envp, int *fd, pid_t pid)
// {
// 	int	file_output;

// 	file_output = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
// 	if (file_output == -1)
// 		ft_error("Failed to open output file");
// 	dup2(fd[0], STDIN_FILENO);
// 	dup2(file_output, STDOUT_FILENO);
// 	close(fd[0]);
// 	close(fd[1]);
// 	close(file_output);
// 	// waitpid(pid, NULL, 0);
// 	ft_exec_cmd(argv[3], envp, pid);
// }

// // opens file1 in read only mode
// // redirects STDOUT to fd[1]
// // redirects STDIN to file1
// // closes file1, fd[0] and fd[1]
// // executes the cmd1 which
// // will be sent back to the parent process

// void	ft_child_process(char **argv, char **envp, int *fd, pid_t pid)
// {
// 	int	file_input;

// 	file_input = open(argv[1], O_RDONLY);
// 	if (file_input == -1)
// 		ft_error("Failed to open input file");
// 	dup2(fd[1], STDOUT_FILENO);
// 	dup2(file_input, STDIN_FILENO);
// 	close(fd[0]);
// 	close(fd[1]);
// 	close(file_input);
// 	ft_exec_cmd(argv[2], envp, pid);
// }

// int	main(int argc, char **argv, char **envp)
// {
// 	int		fd[2];
// 	pid_t	pid;

// 	if (argc != 5)
// 		ft_error("Invalid format");
// 	if (pipe(fd) == -1)
// 		ft_error("Failed to create pipe");
// 	pid = fork();
// 	if (pid == -1)
// 		ft_error("Failed to fork");
// 	if (pid == 0)
// 		ft_child_process(argv, envp, fd, pid);
// 	ft_parent_process(argv, envp, fd, pid);
// 	return (EXIT_SUCCESS);
// }



void	child_process(char **argv, char **envp, int *end)
{
	int	f1;
	int	result;

	if (!argv[2] || argv[2][0] == '\0')
		ft_error("Error: Empty command.\n");
	f1 = open(argv[1], O_RDONLY);
	if (f1 == -1)
		ft_error("Error: failed to open source file.");
	if (dup2(f1, STDIN_FILENO) < 0)
		ft_error("Error: Dup2 failed");
	if (dup2(end[1], STDOUT_FILENO) < 0)
		ft_error("Error: Dup2 failed");
	close(f1);
	close(end[1]);
	result = ft_exec_cmd(argv[2], envp);
	if (result == 1)
		exit(EXIT_FAILURE);
	exit (1);
}

void	parent_process(char **argv, char **envp, int *end)
{
	int	f2;
	int	result;

	if (!argv[3] || argv[3][0] == '\0')
		ft_error("Error: Empty command.\n");
	f2 = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (f2 == -1)
		ft_error("Error: failed to open output file.");
	if (dup2(end[0], STDIN_FILENO) < 0)
		ft_error("Error: Dup2 failed");
	if (dup2(f2, STDOUT_FILENO) < 0)
		ft_error("Error: Dup2 failed");
	close(f2);
	close(end[0]);
	result = ft_exec_cmd(argv[3], envp);
	if (result == 1)
		exit(EXIT_FAILURE);
	exit (1);
}

int	main(int argc, char **argv, char **envp)
{
	int		end[2];
	pid_t	pid1[2];

	if (argc != 5)
		ft_error("Error: Bad arguments.\n");
	if (pipe(end) == -1)
		ft_error("Pipe error");
	pid1[0] = fork();
	if (pid1[0] < 0)
		ft_error("Fork error");
	if (pid1[0] == 0)
	{
		close(end[0]);
		child_process(argv, envp, end);
	}		
	pid1[1] = fork();
	if (pid1[1] < 0)
		ft_error("Fork error");
	waitpid(pid1[0], NULL, 0);
	if (pid1[1] == 0)
	{
		close(end[1]);
		parent_process(argv, envp, end);
	}		   
	return (close(end[0]), close(end[1]), waitpid(pid1[1], NULL, 0), 0);
}
