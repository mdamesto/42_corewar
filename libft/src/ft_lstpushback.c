/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpushback.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 17:37:06 by jde-maga          #+#    #+#             */
/*   Updated: 2015/12/01 17:50:51 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_lstpushback(t_list **alst, t_list *new)
{
	t_list	*buflst;

	buflst = *alst;
	if (!*alst)
		*alst = new;
	while (buflst->next)
		buflst = buflst->next;
	buflst->next = new;
	new->next = NULL;
}
