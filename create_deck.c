/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_deck.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgodoy <vgodoy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 16:58:34 by vgodoy            #+#    #+#             */
/*   Updated: 2024/11/11 17:46:19 by vgodoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

t_card	*create_deck_a(int argc, char **argv)
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
	if (!test_repetitions(first_card))
			return (free_deck(previous_card), NULL);
	return (first_card);
}

t_decks	*assign_decks(t_decks *decks, t_card *a)
{
	t_card	*b;

	b = NULL;
	decks->deck_a = a;
	decks->deck_b = b;
	deckslen(decks);
	return (decks);
}

t_decks	*create_decks(int argc, char **argv)
{
	t_decks	*decks;
	t_card	*a;

	if (argc <= 1)
		return (NULL);
	decks = malloc(sizeof(t_decks));
	if (!decks)
		return (write(2, "Error\n", 6), NULL);
	a = create_deck_a(argc, argv);
	if (!a)
		return(free(decks), write(2, "Error\n", 6), NULL);
	assign_decks(decks, a);
	if (how_long(a) > 600)
		return(free_decks(decks), write(2, "Error\n", 6), NULL);
	return (decks);
}
