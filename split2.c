/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzutter <mzutter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 21:24:48 by mzutter           #+#    #+#             */
/*   Updated: 2025/02/26 22:20:46 by mzutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	**ft_malloc_error(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

static void	ft_init_var(size_t *i, size_t *count, bool *in_quotes, char *c)
{
	*i = 0;
	*count = 0;
	*in_quotes = false;
	*c = '\0';
}

static size_t	ft_nb_words(char const *s, char c)
{
	size_t	i;
	size_t	nb_words;
	bool	in_quotes;
	char	opening_quote;

	ft_init_var(&i, &nb_words, &in_quotes, &opening_quote);
	if (!s[0])
		return (0);
	while (s[i] == c)
		i++;
	while (s[i])
	{
		handle_quotes(s[i], &in_quotes, &opening_quote);
		if (s[i] == c && !in_quotes)
		{
			nb_words++;
			while (s[i] == c)
				i++;
		}
		else
			i++;
	}
	if (s[i - 1] != c || in_quotes)
		nb_words++;
	return (nb_words);
}

static void ft_get_next_word(char **next_word, size_t *next_word_len, char c) {
	size_t	i;
	bool	in_quotes;
	char	opening_quote;

	*next_word += *next_word_len;
	*next_word_len = 0;
	i = 0;
 	in_quotes = false;
 	opening_quote = '\0';
	while (**next_word == c && !in_quotes)
		(*next_word)++;
	while ((*next_word)[i]) 
	{
		handle_quotes((*next_word)[i], &in_quotes, &opening_quote);
		if ((*next_word)[i] == c && !in_quotes)
			return;
		(*next_word_len)++;
		i++;
    }
}

char	**ft_split2(char const *s, char c)
{
	char	**tab;
	char	*next_word;
	size_t	next_word_len;
	size_t	i;

	if (!s)
		return (NULL);
	tab = (char **)malloc(sizeof(char *) * (ft_nb_words(s, c) + 1));
	if (!tab)
		return (NULL);
	i = 0;
	next_word = (char *)s;
	next_word_len = 0;
	while (i < ft_nb_words(s, c))
	{
		ft_get_next_word(&next_word, &next_word_len, c);
		tab[i] = (char *)malloc(sizeof(char) * (next_word_len + 1));
		if (!tab[i])
			return (ft_malloc_error(tab));
		ft_strlcpy(tab[i], next_word, next_word_len + 1);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

// int main(void)
// {
// 	char line[] = "'salut les gars' 'aurevoir les gars' ''";
// 	char **result;
// 	char *trimmed;
// 	int i = 0;

// 	result = ft_split2(line, ' ');
// 	while (result[i])
// 	{
// 		printf("%s\n", result[i]);
// 		trimmed = trim_quotes(result[i]);
// 		printf("%s\n", trimmed);
// 		free(result[i]);
// 		free(trimmed);
// 		i++;
// 	}
// 	free(result);
// }
