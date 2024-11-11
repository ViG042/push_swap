/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgodoy <vgodoy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 14:27:18 by vgodoy            #+#    #+#             */
/*   Updated: 2024/11/11 16:58:01 by vgodoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	sorted(t_card *a)
{
	while (a->next != 0 && a->next->nbr > a->nbr)
		a = a->next;
	if (a->next == 0)
		return (1);
	else
		return (0);
}

void	sort3a(t_decks *decks)
{
	if (sorted(decks->deck_a))
		return ;
	if (find_bigger(decks->deck_a) == decks->deck_a)
		ra(decks, 1);
	else if (find_bigger(decks->deck_a) == decks->deck_a->next)
		rra(decks, 1);
	if (decks->deck_a->nbr > decks->deck_a->next->nbr)
		sa(decks);
}

void	sort_under_3(t_decks *decks)
{
	t_card	*a;

	a = decks->deck_a;
	if (a->decklen == 1)
		return ;
	if (a->decklen == 2)
		sa(decks);
	else
		sort3a(decks);
}
