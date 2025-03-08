/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzutter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 23:49:05 by mzutter           #+#    #+#             */
/*   Updated: 2024/10/30 00:09:22 by mzutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;
	char	convc;

	convc = (char) c;
	len = ft_strlen(s);
	while (len > 0)
	{
		if (s[len] == convc)
			return ((char *)&s[len]);
		len--;
	}
	return (NULL);
}
