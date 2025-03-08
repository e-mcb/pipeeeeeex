/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzutter <mzutter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 22:47:19 by mzutter           #+#    #+#             */
/*   Updated: 2025/03/08 01:02:39 by mzutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdbool.h>
# include <stdio.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "libft/libft.h"

char	*ft_pathfinder(char *cmd, char **envp);
int		ft_exec_cmd(char *argv, char **envp);
//utils functions
char	**ft_split2(char const *s, char c);
void	ft_error(const char *message);
bool	is_quote(char c);
bool	is_closing_quote(char c, char opening_quote);
bool	handle_quotes(char c, bool *in_quotes, char *opening_quote);
char	*trim_quotes(char *str);
char *helper_path(char **cmd, char **envp);

#endif