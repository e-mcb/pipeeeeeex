/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzutter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 23:43:47 by mzutter           #+#    #+#             */
/*   Updated: 2024/10/29 23:43:56 by mzutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*convs;
	unsigned char	convc;
	size_t			i;

	convs = (unsigned char *) s;
	convc = (unsigned char) c;
	i = 0;
	while (i < n)
	{
		if (convs[i] == convc)
			return ((void *) &convs[i]);
		i++;
	}
	return (NULL);
}
