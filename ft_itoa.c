/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 10:25:48 by anboisve          #+#    #+#             */
/*   Updated: 2022/11/17 17:39:01 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_s(int n)
{
	int	i;

	i = 1;
	if (n == -2147483648)
		return (11);
	else if (n < 0)
	{	
		n = n * -1;
		i++;
	}
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static void	set_str(char *s, int i, int long n)
{
	if (i > 0)
	{
		s[i] = n % 10 + '0';
		set_str(s, i - 1, n / 10);
	}
	else
		s[i] = n % 10 + '0';
}

char	*ft_itoa(int n)
{
	char		*r;
	long int	temp;

	temp = n;
	r = ft_calloc(num_s(n) + 1, sizeof(char));
	if (!r)
		return (NULL);
	else if (temp < 0)
		temp = temp * -1;
	set_str(r, num_s(n) - 1, temp);
	if (n < 0)
		r[0] = '-';
	return (r);
}
