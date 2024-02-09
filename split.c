/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatsuka <kmatsuka@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 03:00:01 by kmatsuka          #+#    #+#             */
/*   Updated: 2024/02/10 04:30:25 by kmatsuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*my_strndup(const char *s, size_t len)
{
	char	*dst;

	dst = (char *)malloc(len + 1);
	if (!dst)
		exit(1);
	ft_memcpy(dst, s, len);
	dst[len] = '\0';
	return (dst);
}

static void	my_deploy_words(char *s, char **str)
{
	size_t	ind_s;
	size_t	ind_e;
	size_t	count;

	ind_s = 0;
	ind_e = 0;
	count = 0;
	while (s[ind_e])
	{
		if (s[ind_e] == ' ')
		{
			str[count] = my_strndup(&s[ind_s], ind_e - ind_s);
			count++;
			ind_s = ind_e + 1;
		}
		ind_e++;
	}
	str[count] = my_strndup(&s[ind_s], ind_e - ind_s);
	str[count + 1] = NULL;
}

static size_t	my_count_words(char *s)
{
	size_t	count;
	int		flag;

	count = 1;
	flag = 0;
	while (*s)
	{
		if (*s++ == ' ')
		{
			if (!flag)
			{
				count++;
				flag = 1;
			}
			else
				my_error();
		}
		else
			flag = 0;
	}
	return (count);
}

void	my_free_splitedstr(char	**str)
{
	size_t	ind;

	ind = 0;
	while (str[ind])
	{
		free(str[ind]);
		ind++;
	}
	free(str);
}

char	**my_split_singlespace(char *s)
{
	char	**str;
	char	*s_trim;

	s_trim = ft_strtrim(s, " ");
	if (!s_trim)
		exit(1);
	if (!*s_trim)
		my_error();
	str = malloc(sizeof(char *) * (my_count_words(s_trim) + 1));
	if (!str)
		exit(1);
	my_deploy_words(s_trim, str);
	free(s_trim);
	return (str);
}
