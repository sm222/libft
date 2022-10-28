/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 18:19:44 by anboisve          #+#    #+#             */
/*   Updated: 2022/10/25 18:43:33 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*r;
	int		i;

	i = 0;
	r = ft_strdup(s);
	if (!r)
		return (NULL);
	while (r[i])
	{
		r[i] = f(i, r[i]);
		i++;
	}
	return (r);
}
