/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_decks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgodoy <vgodoy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 16:14:04 by vgodoy            #+#    #+#             */
/*   Updated: 2024/10/27 17:02:43 by vgodoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	show_decks(t_decks *decks)
{
	t_card	*a;
	t_card	*b;

	a = decks->deck_a;
	b = decks->deck_b;
	while ((a != NULL) || (b != NULL))
	{
		if (a != NULL)
		{
			printf("%d.", a->index);
			printf("[%d]", a->nbr);
			if (a->prev != NULL)
				printf("  <-%d   ", a->prev->nbr);
			else
				printf("  <-NulL");
			if (a->next != NULL)
				printf("|   %d->", a->next->nbr);
			else
				printf("|NulL->");
			if (a->tgt)
				printf("  tgt=[%d]", a->tgt->nbr);
			else
				printf("          ");
			if (a->cost)
				printf(" cost=[%d]", a->cost);
			else
				printf("          ");
		}
		printf("          ");
		if (b != NULL)
		{
			if (a == NULL)
				printf("                             ");
			printf("%d.", b->index);
			printf("[%d]", b->nbr);
			if (b->prev != NULL)
				printf("  <-%d   ", b->prev->nbr);
			else
				printf("  <-NulL");
			if (b->next != NULL)
				printf("|   %d->", b->next->nbr);
			else
				printf("|NulL->");
			b = b->next;
		}
		if (a != NULL)
			a = a->next;
		printf("\n");
	}
	if (decks->deck_a)
		printf("total a = [%d]                                    ", decks->deck_a->decklen);
	else
		printf("                                                 ");
	if (decks->deck_b)
		printf("total b len = [%d]", decks->deck_b->decklen);
	printf("\n-----------\n\n");
}
