/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strerror.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 13:53:30 by jde-maga          #+#    #+#             */
/*   Updated: 2015/12/01 14:08:05 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdio.h>

char	*ft_strerror(int errnum)
{
	if (errnum < 0 || errnum > sys_nerr)
		return (NULL);
	return ((char *)sys_errlist[errnum]);
}
