/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 09:09:23 by anboisve          #+#    #+#             */
/*   Updated: 2022/11/01 11:19:43 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_i_want_to_brake_free(char **str, int *int_list)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	if (str)
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

	*words_nb = 0;
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

	words_nb = 0;
	j = 0;
	i = 0;
	list = find_words(s, c, &words_nb);
	split_txt = (char **)ft_calloc(words_nb + 1, sizeof(char *));
	if (split_txt == NULL)
		return (NULL);
	while (j < words_nb)
	{
		split_txt[j] = ft_substr(s, list[i], list[i + 1] - list[i]);
		if (!split_txt[j])
			return (ft_i_want_to_brake_free(split_txt, list));
		i += 2;
		j++;
	}
	free(list);
	return (split_txt);
}

int	main(void)
{
	char	**p;
	int		i;

	i = 0;
	p = ft_split("aw wad  split", ' ');
	while (p[i])
	{
		printf("%s\n", p[i]);
		i++;
	}
	return (0);
}

