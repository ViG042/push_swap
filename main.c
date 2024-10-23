/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgodoy <vgodoy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 15:23:56 by vgodoy            #+#    #+#             */
/*   Updated: 2024/10/23 12:32:29 by vgodoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	show_deck(t_card *first_card)
{
	t_card	*card;
	int		nbr;

	card = first_card;
	write(1,".........\n",10);
	while (card != NULL)
	{
		printf("%d\n",card->nbr);
		card = card->next;
	}
}

void	show_args(int argc, char **argv)
{
	int	i;

	i = 0;
	printf("argc=[%d]    ", argc);
	while (i < argc)
	{
		printf("i=[%d] ", i);
		printf("argv[i]=[%s]   ", argv[i]);
		i++;
	}
	printf(".\n");
}

int	main(int argc, char **argv)
{
	t_card	*first_card;

	if (argc <= 1)
		return (-1);
//	show_args(argc, argv);
	first_card = create_deck(argc, argv);
	if (!first_card)
		return (-1);
	show_deck(first_card);
	first_card = rotate(first_card);
	printf("\nra\n");
	show_deck(first_card);
	free_deck(first_card);
	return (0);
}
