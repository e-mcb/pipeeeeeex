/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzutter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 23:46:02 by mzutter           #+#    #+#             */
/*   Updated: 2024/10/30 00:09:08 by mzutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	convc;
	size_t	len;

	i = 0;
	convc = (char) c;
	len = ft_strlen(s);
	if (convc == '\0')
		return ((char *)&s[len]);
	while (s[i] != '\0')
	{
		if (s[i] == convc)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}
