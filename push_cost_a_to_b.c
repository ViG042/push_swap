/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_cost_a_to_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgodoy <vgodoy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:30:25 by vgodoy            #+#    #+#             */
/*   Updated: 2024/11/09 17:48:39 by vgodoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	cost_to_the_top(t_card *a)
{
	int	cost;

	if (a->index <= a->decklen / 2)
		cost = a->index;
	else
		cost = a->decklen - a->index;
	return (cost);
}

int	calculate_cost(t_card *a, t_card *a_tgt)
{
	int	cost;

	cost = cost_to_the_top(a);
	cost = cost + cost_to_the_top(a_tgt);
	return (cost);
}

void	push_cost_a_to_b(t_decks *decks)
{
	t_card	*a;
	t_card	*b;

	a = decks->deck_a;
	b = decks->deck_b;

	while (a)
	{
		a->cost = calculate_cost(a, a->tgt);
		a = a->next;
	}
}
