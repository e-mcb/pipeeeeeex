/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzutter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 23:44:19 by mzutter           #+#    #+#             */
/*   Updated: 2024/10/29 23:44:24 by mzutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*tmp_dest;
	unsigned char	*tmp_src;

	if (dest == (NULL) && src == (NULL))
		return (dest);
	tmp_dest = (unsigned char *) dest;
	tmp_src = (unsigned char *) src;
	while (n > 0)
	{
		*(tmp_dest++) = *(tmp_src++);
		n--;
	}
	return (dest);
}
