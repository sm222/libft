/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 09:09:23 by anboisve          #+#    #+#             */
/*   Updated: 2022/11/06 10:19:59 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_free_list(int *list)
{
	if (list)
		free (list);
	return (NULL);
}

static char	**ft_i_want_to_break_free(char **str, int *int_list)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
	if (int_list)
		free(int_list);
	return (NULL);
}

static int	*add_int(int *old, int size, int nb)
{
	int	*new;

	new = (int *)ft_calloc(size + 1, sizeof(int));
	if (!new)
		return (0);
	if (old)
		ft_memmove(new, old, size * sizeof(int));
	new[size] = nb;
	if (old)
		free(old);
	return (new);
}

static int	*find_words(char const *s, char c, int *words_nb)
{
	int	*index;
	int	i;
	int	index_s;

	index = NULL;
	index_s = 0;
	i = 0;
	while (s[i])
	{
		if (((s[i] == c && s[i + 1] != c) && s[i + 1]) || (i == 0 && s[0] != c))
		{
			if (i != 0 || s[0] == c)
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
	return (index);
}

char	**ft_split(char const *s, char c)
{
	int		*list;
	char	**split_txt;
	int		words_nb;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	words_nb = 0;
	j = 0;
	i = 0;
	list = find_words(s, c, &words_nb);
	split_txt = (char **)ft_calloc(words_nb + 1, sizeof(char *));
	if (!split_txt)
		return (ft_free_list(list));
	while (j < words_nb)
	{
		split_txt[j] = ft_substr(s, list[i], list[i + 1] - list[i]);
		if (!split_txt[j])
			return (ft_i_want_to_break_free(split_txt, list));
		i += 2;
		j++;
	}
	free(list);
	return (split_txt);
}
