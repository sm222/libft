/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 11:34:32 by anboisve          #+#    #+#             */
/*   Updated: 2022/11/02 17:46:46 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	d;

	if (dstsize == 0)
		return (0);
	d = ft_strlen(dst);
	if (dstsize <= d)
		return (dstsize + ft_strlen(src));
	dstsize -= d + 1;
	while (dstsize-- > 0 && *src)
		dst[d++] = *src++;
	dst[d] = '\0';
	return (ft_strlen(src) + d);
}
