/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brainfuck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariperez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 11:38:56 by ariperez          #+#    #+#             */
/*   Updated: 2018/12/10 18:58:46 by ariperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int		brackets(char *str, int i)
{
	int		count;

	count = 0;
	if (*(str + i) == '[')
	{
		while (*(str + i) != '\0')
		{
			if (*(str + i) == '[')
				count++;
			else if (*(str + i) == ']')
				count--;
			if ((*(str + i) == ']') && count == 0)
				return (i);
			i++;
		}
	}
	else if (*(str + i) == ']')
	{
		while (i >= 0)
		{
			if (*(str + i) == '[')
				count++;
			else if (*(str + i) == ']')
				count--;
			if ((*(str + i) == '[') && count == 0)
				return (i);
			i--;
		}
	}
	return (0);
}

int		brainfuck(char *str)
{
	int		i;
	int		j;
	char	*ptr;

	i = 0;
	j = 0;
	if ((ptr = malloc(sizeof(*ptr) * 2048)) == NULL)
		return (0);
	while (*(str + i) != '\0')
	{
		if (*(str + i) == '>')
			j++;
		else if (*(str + i) == '<')
			j--;
		else if (*(str + i) == '+')
			ptr[j]++;
		else if (*(str + i) == '-')
			ptr[j]--;
		else if (*(str + i) == '.')
			write(1, &ptr[j], 1);
		else if ((*(str + i) == '[' && !*(ptr + j)) ||
				(*(str + i) == ']' && *(ptr + j)))
			i = brackets(str, i);
		i++;
	}
	return (0);
}

int		main(int ac, char **av)
{
	if (ac > 1)
		brainfuck(av[1]);
	else
		write(1, "\n", 1);
	return (8);
}
