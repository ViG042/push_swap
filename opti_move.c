/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opti_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgodoy <vgodoy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 17:17:59 by vgodoy            #+#    #+#             */
/*   Updated: 2024/11/09 17:47:54 by vgodoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
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
*/
void	go_up(t_decks *decks, t_card *better_choice)
{
	t_card	*target;
	int		double_move;

	target = better_choice->tgt;
	if (better_choice->index < target->index)
		double_move = better_choice->index;
	else
		double_move = target->index;
	while (double_move > 0)
	{
		rr(decks);
		double_move--;
	}
	deckslen(decks);
//---------------------------------------simple_move_up
}

bool	same_side_of_their_median(t_decks *decks, t_card *better_choice)
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

void	opti_move(t_decks *decks, t_card *better_choice)
{
	t_card	*target;

	target = better_choice->tgt;
	if (better_choice->index <= better_choice->decklen / 2
			&& target->index <= target->decklen / 2)
		go_up(decks, better_choice);
	if (better_choice->index > better_choice->decklen / 2
			&& target->index > target->decklen / 2)
		go_down(decks, better_choice);
}
