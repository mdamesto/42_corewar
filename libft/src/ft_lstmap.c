/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 12:01:42 by jde-maga          #+#    #+#             */
/*   Updated: 2015/12/01 17:54:48 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *otp;
	t_list *otp_buf;
	t_list *buffer;

	otp_buf = NULL;
	while (lst)
	{
		buffer = f(lst);
		if (otp_buf == NULL)
		{
			otp_buf = buffer;
			otp = otp_buf;
			otp_buf->next = NULL;
		}
		else
		{
			otp_buf->next = buffer;
			otp_buf = otp_buf->next;
			otp_buf->next = NULL;
		}
		lst = lst->next;
	}
	return (otp);
}
