/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 14:00:50 by anboisve          #+#    #+#             */
/*   Updated: 2022/12/04 13:11:06 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t coun, size_t size)
{
	char	*new;

	new = malloc(coun * size);
	if (!new)
		return (NULL);
	ft_bzero(new, coun * size);
	return (new);
}
