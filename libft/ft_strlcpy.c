/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzutter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 23:47:27 by mzutter           #+#    #+#             */
/*   Updated: 2024/10/30 00:11:04 by mzutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dsize)
{
	size_t	i;

	i = 0;
	while (*src && (i + 1) < dsize)
	{
		*dst++ = *src++;
		++i;
	}
	if (i < dsize)
		*dst = 0;
	while (*src++)
		++i;
	return (i);
}
