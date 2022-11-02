/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 11:32:07 by anboisve          #+#    #+#             */
/*   Updated: 2022/11/01 14:48:07 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	int		n;

	i = 0;
	n = ft_strlen(s);
	while (i <= n)
	{
		if (((char *)s)[i] == (unsigned char)c)
			return (((char *)s) + i);
		i++;
	}
	return (NULL);
}
