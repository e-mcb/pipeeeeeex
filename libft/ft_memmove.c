/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzutter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 23:44:31 by mzutter           #+#    #+#             */
/*   Updated: 2024/10/29 23:44:35 by mzutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*tmp_dest;
	unsigned char	*tmp_src;

	tmp_dest = (unsigned char *) dest;
	tmp_src = (unsigned char *) src;
	if (!dest && !src)
		return (NULL);
	if (src < dest)
		while (n--)
			tmp_dest[n] = tmp_src[n];
	else
		while (n--)
			*tmp_dest++ = *tmp_src++;
	return (dest);
}
