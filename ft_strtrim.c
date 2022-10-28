/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:33:50 by anboisve          #+#    #+#             */
/*   Updated: 2022/10/25 18:53:37 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//redo
char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	s_i;
	size_t			s_j;

	s_i = 0;
	s_j = ft_strlen(s1);
	if (s1[0] == 0)
		return (ft_strdup(s1));
	while (ft_strchr(set, (int)s1[s_i]) != NULL && s_i <= s_j)
		s_i++;
	while (ft_strchr(set, (int)s1[s_j]) != NULL && s_i <= s_j)
		s_j--;
	return (ft_substr(s1, s_i, (s_j - s_i + 1)));
}
