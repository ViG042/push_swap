/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgodoy <vgodoy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:51:08 by vgodoy            #+#    #+#             */
/*   Updated: 2024/11/11 16:03:36 by vgodoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_a2(t_decks *decks, t_card *better_choice)
{
	int	i;

	if (better_choice->tgt->index <= better_choice->tgt->decklen / 2)
	{
		i = better_choice->tgt->index;
		while (i > 0)
		{
			ra(decks, 1);
			i--;
		}
	}
	else
	{
		i = better_choice->tgt->decklen - better_choice->tgt->index;
		while (i > 0)
		{
			rra(decks, 1);
			i--;
		}
	}
}

void	move_b2(t_decks *decks, t_card *better_choice)
{
	int	i;

	if (better_choice->index <= better_choice->decklen / 2)
	{
		i = better_choice->index;
		while (i > 0)
		{
			rb(decks, 1);
			i--;
		}
	}
	else
	{
		i = better_choice->decklen - better_choice->index;
		while (i > 0)
		{
			rrb(decks, 1);
			i--;
		}
	}
}

t_card	*choose_wisely2(t_decks *decks)
{
	t_card	*better_choice;
	t_card	*b;

	b = decks->deck_b;
	better_choice = b;
	while (b)
	{
		if (b->cost < better_choice->cost)
			better_choice = b;
		b = b->next;
	}
	return (better_choice);
}

void	push_b_to_a(t_decks *decks)
{
	t_card *better_choice;

	better_choice = choose_wisely2(decks);
	if (same_side_of_their_median(better_choice)
			&& (opti_push_cost(better_choice)
			< calculate_cost2(better_choice, better_choice->tgt)))
		opti_move(decks, better_choice);
	else
	{
		move_b2(decks, better_choice);
		move_a2(decks, better_choice);
	}
	pa(decks);
}
