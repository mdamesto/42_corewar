/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 10:36:42 by jde-maga          #+#    #+#             */
/*   Updated: 2015/12/10 16:28:17 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*otp;

	if ((otp = (t_list *)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	if (!content)
	{
		otp->content = NULL;
		otp->content_size = 0;
	}
	else
	{
		if ((otp->content = (void *)malloc(sizeof(content))) == NULL)
			return (NULL);
		ft_memcpy(otp->content, content, content_size);
		otp->content_size = content_size;
	}
	otp->next = NULL;
	return (otp);
}
