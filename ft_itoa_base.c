/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlufulua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 14:27:44 by tlufulua          #+#    #+#             */
/*   Updated: 2021/07/13 08:00:14 by tlufulua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	bytes_str(long unsigned int len, int bs)
{
	size_t	bytes;

	bytes = (len == 0);
	while (len > 0)
	{
		len = len / bs;
		bytes++;
	}
	return (bytes);
}

int	check_base(char *base, int *bs)
{
	char	*or_base;
	int		i;

	or_base = base;
	i = 0;
	if (!base || ft_strlen(base) > 16 || repeat_char(base))
		return (0);
	while (*or_base)
	{
		if (*or_base < '0' || (*or_base > '9' && *or_base < 'a' ) \
				|| *or_base > 'f')
			return (0);
		or_base++;
	}
	*bs = ft_strlen(base);
	return (1);
}

char	*ft_itoa_base(long unsigned int n, char *base)
{
	size_t				str_size;
	char				*nb;
	long unsigned int	x;
	int					bs;

	if (!check_base(base, &bs))
		return (0);
	x = n;
	if (n < 0)
		x = n * -1;
	str_size = (n < 0) + bytes_str(x, bs);
	nb = (char *)ft_calloc(sizeof(char), (str_size-- + 1));
	if (nb && x == 0)
		nb[str_size] = 0 + '0';
	while (nb && x > 0)
	{
		if ((x % bs) < 10)
			nb[str_size--] = (x % bs) + '0';
		else
			nb[str_size--] = ((x % bs) + 39) + '0';
		x = x / bs;
	}
	if (n < 0)
		nb[0] = '-';
	return (nb);
}
