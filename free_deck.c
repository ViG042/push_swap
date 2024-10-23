/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_deck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgodoy <vgodoy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 09:24:17 by vgodoy            #+#    #+#             */
/*   Updated: 2024/10/23 16:09:29 by vgodoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_card	*go_first(t_card *actual_card)
{
	while (actual_card->prev != 0)
	{
		actual_card = actual_card->prev;
	}
	return (actual_card);
}

void	free_deck(t_card *actual_card)
{
	t_card	*next_card;

	if (!actual_card)
		return ;
	if (actual_card->prev != NULL)
		actual_card = go_first(actual_card);
	next_card = actual_card->next;
	while (next_card)
	{
		free(actual_card);
		actual_card = next_card;
		next_card = next_card->next;
	}
	free(actual_card);
}

void	free_decks(t_decks	*decks)
{
	free_deck(decks->deck_a);
	free_deck(decks->deck_b);
	free(decks);
}
