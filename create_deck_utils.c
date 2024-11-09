/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_deck_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgodoy <vgodoy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 17:02:26 by vgodoy            #+#    #+#             */
/*   Updated: 2024/11/09 17:12:55 by vgodoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long	ft_atol(char *str)
{
	long long	nbr;
	int			i;
	int			minus;

	nbr = 0;
	i = 0;
	minus = 1;
	if (str[i] == '-')
	{
		minus = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr * 10 + (str[i] - '0');
		i++;
	}
	nbr = nbr * minus;
	if ((str[i] != '\0' || nbr < INT_MIN || nbr > INT_MAX)
		|| (nbr == 0 && str[0] == '-'))
		return (2147483648);
	else
		return (nbr);
}

bool	test_repetitions(t_card *a)
{
	t_card	*first_card;
	t_card	*aception;

	first_card = a;
	while (a)
	{
		aception = first_card;
		while(aception)
		{
			if (a != aception && a->nbr == aception->nbr)
				return(0);
			aception = aception->next;
		}
		a = a->next;
	}
	return (1);
}
