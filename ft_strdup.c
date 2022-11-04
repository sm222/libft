/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 11:41:52 by anboisve          #+#    #+#             */
/*   Updated: 2022/11/03 20:00:13 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*new;

	if (!s1)
		return (NULL);
	i = ft_strlen(s1);
	new = malloc(sizeof(char) * i++ + 1);
	if (!new)
		return (NULL);
	while (--i >= 0)
		new[i] = s1[i];
	return (new);
}
