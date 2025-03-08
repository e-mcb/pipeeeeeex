/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzutter <mzutter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 23:52:42 by mzutter           #+#    #+#             */
/*   Updated: 2025/03/08 01:02:31 by mzutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	secure_dup2(int old_fd, int new_fd)
{
	if (dup2(old_fd, new_fd) == -1)
	{
		perror("dup2 failed");
		exit(EXIT_FAILURE);
	}
}

// prints an error message and exits the program
// only used if the exit status is supposed to be 1
void	ft_error(const char *message)
{
	perror(message);
	exit(EXIT_FAILURE);
}

char	*trim_quotes(char *str)
{
	int		start;
	int		end;
	char	*trimmed;

	start = 0;
	end = ft_strlen(str) - 1;
	if (str[start] == '"' || str[start] == '\'')
		start++;
	if (str[end] == '"' || str[end] == '\'')
		end--;
	trimmed = malloc(end - start + 2);
	if (!trimmed)
		return (NULL);
	ft_strlcpy(trimmed, &str[start], end - start + 2);
	return (trimmed);
}

char *helper_path(char **cmd, char **envp)
{
	char *path;
	
	if (cmd[0][0] == '/')
		path = cmd[0];
	else
		path = ft_pathfinder(cmd[0], envp);
	if (!path)
		return(free_paths(cmd), NULL);
	return(path);
}
