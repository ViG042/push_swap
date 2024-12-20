/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_cost_b_to_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgodoy <vgodoy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:42:07 by vgodoy            #+#    #+#             */
/*   Updated: 2024/11/11 18:05:31 by vgodoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	cost_to_the_top2(t_card *b)
{
	int	cost;

	if (b->index <= b->decklen / 2)
		cost = b->index;
	else
		cost = b->decklen - b->index;
	return (cost);
}

int	calculate_cost2(t_card *b, t_card *b_tgt)
{
	int	cost;

	cost = cost_to_the_top2(b);
	cost = cost + cost_to_the_top2(b_tgt);
	return (cost);
}

void	push_cost_b_to_a(t_decks *decks)
{
	t_card	*a;
	t_card	*b;
	int		opti_cost;

	a = decks->deck_a;
	b = decks->deck_b;
	while (b)
	{
		b->cost = calculate_cost2(b, b->tgt);
		if (same_side_of_their_median(b))
		{
			opti_cost = opti_push_cost(b);
			if (opti_cost < b->cost)
				b->cost = opti_cost;
		}
		b = b->next;
	}
}
