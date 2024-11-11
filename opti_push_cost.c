/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opti_push_cost.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgodoy <vgodoy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 17:48:52 by vgodoy            #+#    #+#             */
/*   Updated: 2024/11/11 12:30:50 by vgodoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	same_side_of_their_median(t_card *better_choice)
{
	t_card	*target;

	target = better_choice->tgt;
	if (better_choice->index <= better_choice->decklen / 2
			&& target->index <= target->decklen / 2)
		return (1);
	if (better_choice->index > better_choice->decklen / 2
			&& target->index > target->decklen / 2)
		return (1);
	return (0);
}

int	opti_push_cost(t_card *card)
{
	t_card	*target;
	int		push_cost;

	push_cost = 0;
	target = card->tgt;
	if (card->index <= card->decklen / 2
			&& target->index <= target->decklen / 2)
		if (card->index > target->index)
			push_cost = card->index;
		else
			push_cost = target->index;
	else
		if ((card->decklen - card->index) > (target->decklen - target->index))
			push_cost = card->decklen - card->index;
		else
			push_cost = target->decklen - target->index;
	return (push_cost);
}
