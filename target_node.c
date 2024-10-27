/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgodoy <vgodoy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 15:06:39 by vgodoy            #+#    #+#             */
/*   Updated: 2024/10/27 15:44:25 by vgodoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_card	*target_a(t_card *deck_b, int nbr)
{
	t_card	*tgt;
	t_card	*b;

	b = deck_b;
	tgt = deck_b;
	while (b)
	{
		if (b->nbr < nbr && tgt->nbr < b->nbr)
			tgt = b;
		b = b->next;
	}
	if (tgt->nbr > nbr)
		tgt = find_bigger(deck_b);
	return (tgt);
}

void	target_node_a(t_decks	*decks)
{
	t_card	*a;

	a = decks->deck_a;
	while (a)
	{
		a->tgt = target_a(decks->deck_b, a->nbr);
		a = a->next;
	}
}
