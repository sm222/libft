/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 09:09:23 by anboisve          #+#    #+#             */
/*   Updated: 2022/10/30 18:29:30 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*add_int(int *old, int size, int nb)
{
	int	*new;

	new = (int *)ft_calloc(size + 1, sizeof(int));
	if (!new)
		return (new);
	if (old)
		ft_memmove(new, old, size * sizeof(int));
	new[size] = nb;
	free(old);
	return (new);
}

int	*find_words(char const *s, char c, int *words_nb)
{
	int	*index;
	int	i;
	int	index_s;

	index_s = 0;
	i = 0;
	index = NULL;
	while (s[i])
	{
		if (((s[i] == c && s[i + 1] != c) && s[i + 1]) || (i == 0 && s[0] != c))
		{
			if (i != 0)
				i++;
			index = add_int(index, index_s++, i);
			while (s[i] && s[i] != c)
				i++;
			index = add_int(index, index_s++, i);
			*words_nb += 1;
		}
		else
			i++;
	}
	index = add_int(index, index_s, -1);
	return (index);
}

char	**ft_split(char const *s, char c)
{
	int		*list;
	char	**split_txt;
	int		words_nb;
	int		i;
	int		j;

	j = 0;
	i = 0;
	words_nb = 0;
	list = find_words(s, c, &words_nb);
	split_txt = (char **)ft_calloc(words_nb + 1, sizeof(char *));
	if (words_nb == 0 || split_txt == NULL)
	{
		if (list == 0)
			free(list);
		return (split_txt);
	}
	while (j < words_nb)
	{
		split_txt[j] = ft_substr(s, list[i], list[i + 1] - list[i]);
		i += 2;
		j++;
	}
	return (split_txt);
}
