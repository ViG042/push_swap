/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgodoy <vgodoy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 15:23:56 by vgodoy            #+#    #+#             */
/*   Updated: 2024/10/23 15:35:53 by vgodoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	show_deck(t_card *card)
{
	while (card != NULL)
	{
		printf("%d\n",card->nbr);
		card = card->next;
	}
}

void	show_decks(t_card *deck_a, t_card *deck_b)
{
	printf("--------deck_a:\n");
	show_deck(deck_a);
	printf("--------deck_b:\n");
	show_deck(deck_b);
}

int	main(int argc, char **argv)
{
	t_card	*deck_a;
	t_card	*deck_b;

	if (argc <= 1)
		return (-1);
	deck_a = create_deck(argc, argv);
	if (!deck_a)
		return (-1);
	deck_b = NULL;
	show_decks(deck_a, deck_b);

	deck_a = reverse_rotate(deck_a);
	printf("\nrra\n");
	show_deck(deck_a);

	deck_a = rotate(deck_a);
	printf("\nra\n");
	show_deck(deck_a);

	deck_a = swap(deck_a);
	printf("\nsa\n");
	show_deck(deck_a);

	free_deck(deck_a);
	free_deck(deck_b);
	return (0);
}
