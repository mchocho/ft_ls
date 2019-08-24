/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isvalidoptions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchocho <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 18:51:45 by mchocho           #+#    #+#             */
/*   Updated: 2019/08/23 18:53:56 by mchocho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isvalidoptions(char c)
{
	char	options[40];
	int		i;

	options = "[-ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1]";
	i = 0;
	while(options[i])
	{
		if (options[i] == c)
			return (true);
		i++;
	}
	return (false);
}
