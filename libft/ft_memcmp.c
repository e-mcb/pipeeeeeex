/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzutter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 23:44:02 by mzutter           #+#    #+#             */
/*   Updated: 2024/10/29 23:44:07 by mzutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*convs1;
	unsigned char	*convs2;
	size_t			i;

	convs1 = (unsigned char *) s1;
	convs2 = (unsigned char *) s2;
	i = 0;
	while ((i < n) && (convs1[i] == convs2[i]))
		i++;
	return ((unsigned char) convs1[i] - (unsigned char) convs2[i]);
}
