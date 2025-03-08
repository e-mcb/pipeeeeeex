/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzutter <mzutter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 21:28:09 by mzutter           #+#    #+#             */
/*   Updated: 2025/02/26 03:02:54 by mzutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "../libft/libft.h"

void	ft_error(const char *message);
char	*ft_pathfinder(char *cmd, char **envp);
void	ft_exec_cmd(char *argv, char **envp);
char	*get_next_line(int fd);
bool	is_closing_quote(char c, char opening_quote);
bool	is_quote(char c);
bool	handle_quotes(char c, bool *in_quotes, char *opening_quote);
char	**ft_split2(char const *s, char c);
void	secure_dup2(int old_fd, int new_fd);
void	open_heredoc(int argc, char **argv);
int		handle_input_output(int argc, char **argv);
int		ft_open(char *argv, int i);
void	ft_handle_heredoc(int argc, char *limiter);

#endif