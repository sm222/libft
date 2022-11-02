/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 14:26:34 by anboisve          #+#    #+#             */
/*   Updated: 2022/11/02 15:05:46 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*r;
	size_t	i;

	i = 0;
	if (start < ft_strlen(s))
		while (s[i + start] && len > i)
			i++;
	r = ft_calloc(i * sizeof(char) + 1, 1);
	if (!r)
		return (NULL);
	if (start >= ft_strlen(s))
		return (r);
	ft_strlcpy(r, &s[start], i + 1);
	return (r);
}
