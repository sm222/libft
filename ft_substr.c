/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 14:26:34 by anboisve          #+#    #+#             */
/*   Updated: 2022/12/07 17:04:08 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	if (start < ft_strlen(s))
		while (s[i + start] && len > i)
			i++;
	new = ft_calloc(i * sizeof(char) + 1, 1);
	if (!new)
		return (NULL);
	if (start >= ft_strlen(s))
		return (new);
	ft_strlcpy(new, &s[start], i + 1);
	return (new);
}
