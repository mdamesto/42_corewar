/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 14:53:32 by jde-maga          #+#    #+#             */
/*   Updated: 2015/12/17 15:46:33 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_realloc(void *ptr, size_t size)
{
	void *otp;

	if ((otp = (void *)malloc(size)) == NULL)
		return (NULL);
	ft_memcpy(otp, ptr, size);
	free(ptr);
	return (otp);
}
