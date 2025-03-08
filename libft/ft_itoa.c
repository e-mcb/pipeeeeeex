/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzutter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 23:41:13 by mzutter           #+#    #+#             */
/*   Updated: 2024/10/30 00:04:33 by mzutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_digits(int n)
{
	size_t	i;

	i = 0;
	if (n == 0 || n == -0)
		return (1);
	if (n < 0)
		i++;
	while (n != 0)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

char	*create_arr(size_t len, long n)
{
	char	*str;

	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	if (n == 0 || n == -0)
		str[0] = '0';
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	i;
	size_t	len;
	long	nbr;

	i = 0;
	nbr = n;
	len = count_digits(nbr);
	str = create_arr(len, nbr);
	if (!str)
		return (NULL);
	str[len] = 0;
	if (nbr < 0)
	{
		str[0] = '-';
		nbr = -nbr;
		i++;
	}
	while (nbr != 0)
	{
		str[--len] = nbr % 10 + 48;
		nbr = nbr / 10;
	}
	return (str);
}

/*int main()
{
    //printf("%d", count_digits(-5));
    printf("%s", ft_itoa(1654874));
    return 0;
}*/
