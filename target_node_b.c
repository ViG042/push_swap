/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target_node_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgodoy <vgodoy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:45:14 by vgodoy            #+#    #+#             */
/*   Updated: 2024/11/06 16:59:24 by vgodoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_card	*target_b(t_card *deck_a, int nbr)
{
	t_card	*tgt;
	t_card	*a;

	a = deck_a;
	tgt = find_bigger(deck_a);
	while (a)
	{
		if (a->nbr > nbr && tgt->nbr > a->nbr)
			tgt = a;
		a = a->next;
	}
	if (tgt->nbr < nbr)
		tgt = find_smaller(deck_a);
	return (tgt);
}

void	target_node_b(t_decks	*decks)
{
	t_card	*b;

	b = decks->deck_b;
	while (b)
	{
		b->tgt = target_b(decks->deck_a, b->nbr);
		b = b->next;
	}
}
