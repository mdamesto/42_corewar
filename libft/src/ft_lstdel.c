/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 11:14:11 by jde-maga          #+#    #+#             */
/*   Updated: 2015/12/01 11:28:48 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *bufalst;
	t_list *bufnextalst;

	bufalst = *alst;
	while (bufalst)
	{
		bufnextalst = bufalst->next;
		ft_lstdelone(&bufalst, del);
		bufalst = bufnextalst;
	}
	*alst = NULL;
}
