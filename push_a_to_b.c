/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgodoy <vgodoy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:06:53 by vgodoy            #+#    #+#             */
/*   Updated: 2024/11/11 15:55:51 by vgodoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_b(t_decks *decks, t_card *better_choice)
{
	int	i;

	if (better_choice->tgt->index <= better_choice->tgt->decklen / 2)
	{
		i = better_choice->tgt->index;
		while (i > 0)
		{
			rb(decks, 1);
			i--;
		}
	}
	else
	{
		i = better_choice->tgt->decklen - better_choice->tgt->index;
		while (i > 0)
		{
			rrb(decks, 1);
			i--;
		}
	}
}

void	move_a(t_decks *decks, t_card *better_choice)
{
	int	i;

	if (better_choice->index <= better_choice->decklen / 2)
	{
		i = better_choice->index;
		while (i > 0)
		{
			ra(decks, 1);
			i--;
		}
	}
	else
	{
		i = better_choice->decklen - better_choice->index;
		while (i > 0)
		{
			rra(decks, 1);
			i--;
		}
	}
}

t_card	*choose_wisely(t_decks *decks)
{
	t_card	*better_choice;
	t_card	*a;

	a = decks->deck_a;
	better_choice = a;
	while (a)
	{
		if (a->cost < better_choice->cost)
			better_choice = a;
		a = a->next;
	}
	return (better_choice);
}

void	push_a_to_b(t_decks *decks)
{
	t_card *better_choice;

	better_choice = choose_wisely(decks);
	if (same_side_of_their_median(better_choice)
			&& (opti_push_cost(better_choice)
			< calculate_cost(better_choice, better_choice->tgt)))
		opti_move(decks, better_choice);
	else
	{
		move_a(decks, better_choice);
		move_b(decks, better_choice);
	}
	pb(decks);
}
