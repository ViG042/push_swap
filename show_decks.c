/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_decks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgodoy <vgodoy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 16:14:04 by vgodoy            #+#    #+#             */
/*   Updated: 2024/10/26 12:26:12 by vgodoy           ###   ########.fr       */
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
				printf("[%d]", a->nbr);
			if (a->prev != NULL)
				printf("  <-%d   ", a->prev->nbr);
			else
				printf("  <-NulL");
			if (a->next != NULL)
				printf("|   %d->", a->next->nbr);
			else
				printf("|NulL->");
		}
		printf("          ");
		if (b != NULL)
		{
			if (a == NULL)
				printf("                  ");
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
	printf("-----------\n");
}
