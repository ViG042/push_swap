/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgodoy <vgodoy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:06:53 by vgodoy            #+#    #+#             */
/*   Updated: 2024/11/06 16:50:55 by vgodoy           ###   ########.fr       */
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
			rb(decks);
			i--;
		}
	}
	else
	{
		i = better_choice->tgt->decklen - better_choice->tgt->index;
		while (i > 0)
		{
			rrb(decks);
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
			ra(decks);
			i--;
		}
	}
	else
	{
		i = better_choice->decklen - better_choice->index;
		while (i > 0)
		{
			rra(decks);
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
	move_a(decks, better_choice);
	move_b(decks, better_choice);
	pb(decks);
}
