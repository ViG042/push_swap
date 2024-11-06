/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgodoy <vgodoy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 15:23:56 by vgodoy            #+#    #+#             */
/*   Updated: 2024/11/06 18:08:10 by vgodoy           ###   ########.fr       */
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

void	everythings_gets_back_in_a(t_decks *decks)
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
			ra(decks);
			i--;
		}
	}
	else
	{
		i = smaller->decklen - smaller->index;
		while (i > 0)
		{
			rra(decks);
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
	show_decks(decks);
	everything_gets_in_b(decks);
	show_decks(decks);
	everythings_gets_back_in_a(decks);
	show_decks(decks);
	final_move(decks, find_smaller(decks->deck_a));
	show_decks(decks);
	free_decks(decks);
	return (0);
}
