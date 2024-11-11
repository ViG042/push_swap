/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgodoy <vgodoy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 15:23:56 by vgodoy            #+#    #+#             */
/*   Updated: 2024/11/11 17:48:54 by vgodoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	everything_gets_in_b(t_decks *decks)
{
	deckslen(decks);
	pb(decks);
	pb(decks);
	deckslen(decks);
	while (decks->deck_a->decklen > 3)
	{
		target_node_a(decks);
		push_cost_a_to_b(decks);
		push_a_to_b(decks);
		deckslen(decks);
	}
	sort3a(decks);
	deckslen(decks);
}

void	everything_gets_back_in_a(t_decks *decks)
{
	while (decks->deck_b->decklen > 1)
	{
		target_node_b(decks);
		push_cost_b_to_a(decks);
		push_b_to_a(decks);
		deckslen(decks);
	}
	target_node_b(decks);
	move_a2(decks, decks->deck_b);
	pa(decks);
	deckslen(decks);
}

void	final_move(t_decks *decks, t_card *smaller)
{
	int	i;

	if (smaller->index <= smaller->decklen / 2)
	{
		i = smaller->index;
		while (i > 0)
		{
			ra(decks, 1);
			i--;
		}
	}
	else
	{
		i = smaller->decklen - smaller->index;
		while (i > 0)
		{
			rra(decks, 1);
			i--;
		}
	}
	deckslen(decks);
}

int	main(int argc, char **argv)
{
	t_decks	*decks;

	decks = create_decks(argc, argv);
	if (!decks)
		return (-1);
	if (sorted(decks->deck_a))
		return (free_decks(decks), 0);
	if (decks->deck_a->decklen <= 3)
		sort_under_3(decks);
	else
	{
		everything_gets_in_b(decks);
		everything_gets_back_in_a(decks);
		final_move(decks, find_smaller(decks->deck_a));
	}
	free_decks(decks);
	return (0);
}
