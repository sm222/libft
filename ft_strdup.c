/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 11:41:52 by anboisve          #+#    #+#             */
/*   Updated: 2023/01/06 10:27:17 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*new;

	if (!s1)
		return (NULL);
	new = ft_calloc(ft_strlen(s1) + 1, sizeof(char));
	if (!new)
		return (NULL);
	return (ft_memcpy(new, s1, ft_strlen(s1)));
}
