/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 13:46:45 by anboisve          #+#    #+#             */
/*   Updated: 2022/12/07 11:54:03 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *old, size_t count, size_t size)
{
	void	*new;

	if (!old)
		return (NULL);
	new = ft_calloc(count + 1, size);
	if (!new)
		return (NULL);
	ft_memcpy(new, old, count * size);
	ft_safe_free(old);
	return (new);
}
