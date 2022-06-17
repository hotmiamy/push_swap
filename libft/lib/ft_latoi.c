/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_latoi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n < llopes-n@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 18:24:20 by llopes-n          #+#    #+#             */
/*   Updated: 2022/06/15 20:39:01 by llopes-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static char	*ft_isspace(char *number)
{
	while ((*number >= '\a' && *number <= '\r') || *number == ' ')
		number++;
	return (number);
}

long int	ft_latoi(const char *numstr)
{
	int			index;
	int			sig;
	long int	num_int;

	index = 0;
	num_int = 0;
	sig = 1;
	numstr = ft_isspace((char *)numstr);
	if (numstr[index] == '-' || numstr[index] == '+')
	{
		sig = 1 - 2 * (numstr[index] == '-');
		index++;
	}
	while (numstr[index])
		num_int = num_int * 10 + (numstr[index++] - '0');
	if (num_int > 0)
		return (num_int * sig);
	return (0);
}
