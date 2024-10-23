/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_deck.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgodoy <vgodoy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 16:58:34 by vgodoy            #+#    #+#             */
/*   Updated: 2024/10/23 14:36:24 by vgodoy           ###   ########.fr       */
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

t_card	*create_card(t_card *previous_card, char *str)
{
	int			nbr;
	long long	number;
	t_card		*new_card;

	number = ft_atol(str);
	if (number > INT_MAX)
		return (NULL);
	nbr = (int)number;
	new_card = malloc(sizeof(t_card));
	if (!new_card)
		return (NULL);
	new_card->nbr = nbr;
	new_card->next = NULL;
	if (previous_card != 0)
		previous_card->next = new_card;
	new_card->prev = previous_card;
	return (new_card);
}

t_card	*create_deck(int argc, char **argv)
{
	int		i;
	t_card	*first_card;
	t_card	*previous_card;
	t_card	*next_card;

	first_card = create_card(NULL, argv[1]);
	if (!first_card)
	{
		return (free_deck(first_card), NULL);
	}
	previous_card = first_card;
	i = 2;
	while (i < argc)
	{
		next_card = create_card(previous_card, argv[i]);
		if (!next_card)
			return (free_deck(previous_card), NULL);
		previous_card = next_card;
		i++;
	}
	return (first_card);
}
