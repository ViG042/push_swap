/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_decks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgodoy <vgodoy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 16:14:04 by vgodoy            #+#    #+#             */
/*   Updated: 2024/10/23 19:28:08 by vgodoy           ###   ########.fr       */
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
			printf("%d", a->nbr);
			a = a->next;
		}
		printf("          ");
		if (b != NULL)
		{
			printf("%d", b->nbr);
			b = b->next;
		}
		printf("\n");
	}
	printf("-----------\n");
}
