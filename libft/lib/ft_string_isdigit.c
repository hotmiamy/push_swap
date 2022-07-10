/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_isdigit.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n < llopes-n@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 06:54:11 by llopes-n          #+#    #+#             */
/*   Updated: 2022/06/29 19:47:13 by llopes-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_string_isdigit(char *str)
{
	int	inx;

	inx = 0;
	while (str[inx])
	{
		if ((str[inx] == '-' && str[inx + 1] == ' ')
			|| (str[inx] == '+' && str[inx + 1] == ' '))
			return (1);
		else
			inx++;
		if (str[inx] < '0' || str[inx] > '9')
			return (str[inx]);
		inx++;
	}
	return (str[inx]);
}
