/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 15:13:33 by jde-maga          #+#    #+#             */
/*   Updated: 2015/11/30 15:59:48 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static void	ft_strnstr_resetvars(int *i, int *j, size_t *n, int c)
{
	if (!c)
	{
		*i = 0;
		*j = 0;
	}
	if (c)
	{
		*j = 0;
		*i = *i + 1;
		*n = *n - 1;
	}
}

char		*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	int i;
	int j;
	int s2size;
	int k;

	s2size = 0;
	ft_strnstr_resetvars(&i, &j, &n, 0);
	while (s2[s2size])
		s2size++;
	if (!s2size)
		return ((char *)s1);
	while (s1[i] && n)
	{
		k = n;
		while (s1[i + j] == s2[j] && k)
		{
			k--;
			if (j == s2size - 1)
				return ((char *)s1 + i);
			j++;
		}
		ft_strnstr_resetvars(&i, &j, &n, 1);
	}
	return (NULL);
}
