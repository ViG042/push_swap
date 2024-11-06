/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decklen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgodoy <vgodoy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 14:22:34 by vgodoy            #+#    #+#             */
/*   Updated: 2024/11/06 15:04:40 by vgodoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	how_long(t_card *a)
{
	int	i;

	i = 0;
	if (a)
	{
		while (a)
		{
			a->index = i;
			a = a->next;
			i++;
		}
	}
	return (i);
}

void	replicate_length(t_card *a)
{
	int	length;

	length = a->decklen;
	while (a)
	{
		a->decklen = length;
		a = a->next;
	}
}

void	deckslen(t_decks *decks)
{
	if (decks->deck_a)
	{
		decks->deck_a->decklen = how_long(decks->deck_a);
		replicate_length(decks->deck_a);
	}
	if (decks->deck_b)
	{
		decks->deck_b->decklen = how_long(decks->deck_b);
		replicate_length(decks->deck_b);
	}
}
