/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaraka <hakaraka@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 10:21:56 by hakaraka          #+#    #+#             */
/*   Updated: 2023/08/24 12:45:08 by hakaraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;

	if (dst != NULL || src != NULL)
	{
		i = 0;
		if (dst > src)
		{
			while (i < len)
			{
				((char *)dst)[len - 1 - i] = ((char *)src)[len - 1 - i];
				i++;
			}
		}
		else
		{
			while (i < len)
			{
				((char *)dst)[i] = ((char *)src)[i];
				i++;
			}
		}
	}
	return (dst);
}
