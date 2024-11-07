/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgodoy <vgodoy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:38:52 by vgodoy            #+#    #+#             */
/*   Updated: 2024/11/07 10:49:58 by vgodoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_decks *decks)
{
	t_card	*a1;
	t_card	*a2;
	t_card	*b1;

	if (decks->deck_a == NULL)
		return ;
	write(1,"pb\n",3);
	a1 = decks->deck_a;
	b1 = decks->deck_b;
	if (a1->next == NULL)
	{
		a1->next = b1;
		if (b1 != NULL)
			b1->prev = a1;
		decks->deck_a = NULL;
		decks->deck_b = a1;
		return ;
	}
	a2 = a1->next;
	decks->deck_a = a2;
	decks->deck_b = a1;
	a1->next = b1;
	if (b1 != NULL)
		b1->prev = a1;
	a2->prev = NULL;
}

void	pa(t_decks *decks)
{
	t_card	*b1;
	t_card	*b2;
	t_card	*a1;

	if (decks->deck_b == NULL)
		return ;
	write(1,"pa\n",3);
	b1 = decks->deck_b;
	a1 = decks->deck_a;
	if (b1->next == NULL)
	{
		b1->next = a1;
		if (a1 != NULL)
			a1->prev = b1;
		decks->deck_b = NULL;
		decks->deck_a = b1;
		return ;
	}
	b2 = b1->next;
	decks->deck_b = b2;
	decks->deck_a = b1;
	b1->next = a1;
	if (a1 != NULL)
		a1->prev = b1;
	b2->prev = NULL;
}
