/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariperez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 13:02:20 by ariperez          #+#    #+#             */
/*   Updated: 2018/12/03 13:41:12 by ariperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_memory(const void *addr, size_t size)
{
	size_t			i;
	size_t			j;
	unsigned char	*ptr;
	char			*hex;

	hex = "0123456789abcdef";
	i = 0;
	ptr = (unsigned char*)addr;
	while (i < size)
	{
		j = 0;
		while (j < 16)
		{
			if (i + j < size)
			{
				write(1, &hex[ptr[i + j] / 16], 1);
				write(1, &hex[ptr[i + j] % 16], 1);
			}
			else
				write(1, "  ", 2);
			if (j % 2)
				write(1, " ", 1);
			j++;
		}
		j = 0;
		while (j < 16 && i + j < size)
		{
			if (' ' <= ptr[i + j] && ptr[i + j] <= '~')
				write(1, &ptr[i + j], 1);
			else
				write(1, ".", 1);
			j++;
		}
		write(1, "\n", 1);
		i += 16;
	}
}
