/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opti_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgodoy <vgodoy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 17:17:59 by vgodoy            #+#    #+#             */
/*   Updated: 2024/11/11 15:37:41 by vgodoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	search_in_a(t_decks *decks, t_card *card)
{
	t_card	*a;

	a = decks->deck_a;
	while (a)
	{
		if (a == card)
			return (1);
		a = a->next;
	}
	return (0);
}

void	go_up_double_move(t_decks *decks, int double_move)
{
	while (double_move > 0)
	{
		rr(decks);
		double_move--;
	}
	deckslen(decks);
}

void	go_up_simple_move(t_decks *decks, t_card *to_be_simple_moved)
{
	int	i;

	if (to_be_simple_moved->index == 0)
		i = 0;
	else
		i = to_be_simple_moved->index;
	if (search_in_a(decks, to_be_simple_moved))
	{
		while (i > 0)
		{
			ra(decks, 1);
			i--;
		}
	}
	else
	{
		while (i > 0)
		{
			rb(decks, 1);
			i--;
		}
	}
	deckslen(decks);
}

void	go_up(t_decks *decks, t_card *better_choice)
{
	t_card	*target;
	int		double_move;
	t_card	*to_be_simple_moved;

	target = better_choice->tgt;
	if (better_choice->index < target->index)
	{
		double_move = better_choice->index;
		to_be_simple_moved = target;
	}
	else
	{
		double_move = target->index;
		to_be_simple_moved = better_choice;
	}
	go_up_double_move(decks, double_move);
	go_up_simple_move(decks, to_be_simple_moved);
}

void	go_down_double_move(t_decks *decks, int double_move)
{
	while (double_move > 0)
	{
		rrr(decks);
		double_move--;
	}
	deckslen(decks);
}

void	go_down_simple_move(t_decks *decks, t_card *to_be_simple_moved)
{
	int	i;

	if (to_be_simple_moved->index == 0)
		i = 0;
	else
		i = to_be_simple_moved->decklen - to_be_simple_moved->index;
	if (search_in_a(decks, to_be_simple_moved))
	{
		while (i > 0)
		{
			rra(decks, 1);
			i--;
		}
	}
	else
	{
		while (i > 0)
		{
			rrb(decks, 1);
			i--;
		}
	}
	deckslen(decks);
}

void	go_down(t_decks *decks, t_card *better_choice)
{
	t_card	*target;
	int		double_move;
	t_card	*to_be_simple_moved;

	target = better_choice->tgt;
	if ((better_choice->decklen - better_choice->index)
			< target->decklen - target->index)
	{
		double_move = better_choice->decklen - better_choice->index;
		to_be_simple_moved = target;
	}
	else
	{
		double_move = target->decklen - target->index;
		to_be_simple_moved = better_choice;
	}
	go_down_double_move(decks, double_move);
	go_down_simple_move(decks, to_be_simple_moved);
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
