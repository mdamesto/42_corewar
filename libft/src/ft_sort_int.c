/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsort_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 14:54:00 by jde-maga          #+#    #+#             */
/*   Updated: 2015/12/16 14:15:41 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void		ft_sort_int_dec(int *array, int size)
{
	int i;
	int tmp;

	i = 1;
	while (i <= size - 1)
	{
		if (array[i] > array[i - 1])
		{
			tmp = array[i - 1];
			array[i - 1] = array[i];
			array[i] = tmp;
			i = 1;
		}
		else
			i++;
	}
}

static void		ft_sort_int_inc(int *array, int size)
{
	int i;
	int tmp;

	i = 1;
	while (i <= size - 1)
	{
		if (array[i] < array[i - 1])
		{
			tmp = array[i - 1];
			array[i - 1] = array[i];
			array[i] = tmp;
			i = 1;
		}
		else
			i++;
	}
}

void			ft_sort_int(int *array, int size, int c)
{
	if (c <= 0)
		ft_sort_int_inc(array, size);
	if (c > 0)
		ft_sort_int_dec(array, size);
}
