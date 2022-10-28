/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 09:09:23 by anboisve          #+#    #+#             */
/*   Updated: 2022/10/28 10:14:49 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	return_p(char const *s, int *p1, int *p2, char c)
{
	while (s[*p1] != c)
		*p1++;
	return ();
}

char	**ft_split(char const *s, char c)
{
	char	**r;

	r = ft_calloc(2, sizeof(char *));
	r[0] = ft_calloc(ft_strlen(s), sizeof(char));
	r[0] = ft_substr(s, 10, 10);
	return (r);
}

int	main(void)
{
	char	**p;
	int		i;

	p = ft_split(" this is a test yo oy    yo s ytos oyoy ", ' ');
	printf("%s", p[0]);
	free(p[0]);
	free(p);
	return (0);
}
