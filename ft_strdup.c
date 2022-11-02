/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 11:41:52 by anboisve          #+#    #+#             */
/*   Updated: 2022/11/02 15:06:14 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*r;

	i = ft_strlen(s1);
	r = malloc(sizeof(char) * i++ + 1);
	if (r == 0)
		return (NULL);
	while (--i >= 0)
		r[i] = s1[i];
	return (r);
}
