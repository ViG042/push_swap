/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_deck.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgodoy <vgodoy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 16:58:34 by vgodoy            #+#    #+#             */
/*   Updated: 2024/10/23 11:26:46 by vgodoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_atoi(char *str)
{
	int			*ptr;
	long long	nbr;
	int			short_nbr;
	int			i;
	int			minus;
//												printf("   in ft_atoi\n");
	nbr = 0;
	i = 0;
	minus = 1;
	if (str[i] == '-')
	{
		minus = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr * 10 + (str[i] - '0');
		i++;
	}
	nbr = nbr * minus;
//												printf("nbr=[%lld]\n", nbr);
	if ((str[i] != '\0' || nbr < INT_MIN || nbr > INT_MAX)
		|| (nbr == 0 && str[0] == '-'))
	{
//												printf("not a valid number\n");
		return (NULL);
	}
	else
	{
		short_nbr = (int)nbr;
		ptr = &short_nbr;
//												printf("ptr=[%p] *ptr=[%d]\n", ptr, *ptr);
		return (ptr);
	}
}

t_card	*create_card(t_card *previous_card, char *str)
{
	int		nbr;
	int		*number;
	t_card	*new_card;
//												printf("    in create_card\n");
//												printf("str=[%s]\n", str);
	number = ft_atoi(str);
	if (!number)
		return (NULL);
	nbr = *number;
//												printf("in create_card: (ptr)number=[%p] *number=[%d] nbr=[%d]\n", number, *number, nbr);
	new_card = malloc(sizeof(t_card));
	if (!new_card)
		return (NULL);
//												printf("in create_card: new_card=[%p]\n", new_card);
	new_card->nbr = nbr;
	new_card->next = NULL;
//												printf("new_card->nbr=[%d]\n", new_card->nbr);
//												printf("new_card->next=[%p]\n", new_card->next);
//												printf("previous_card=[%p]\n", previous_card);
	if (previous_card != 0)
		previous_card->next = new_card;
	new_card->prev = previous_card;
	//											printf("previous_card->next=[%p] =? new_card=[%p]\n", previous_card->next, new_card);
	//											printf("new_card->prev=[%p] =? previous_card=[%p]\n", new_card->prev, previous_card);
	return (new_card);
}

t_card	*create_deck(int argc, char **argv)
{
	int		i;
	t_card	*first_card;
	t_card	*previous_card;
	t_card	*next_card;
//												printf("in create_deck\n");
	first_card = create_card(NULL, argv[1]);
	if (!first_card)
	{
//												printf("first_card ABORT\n");
		return (free_deck(first_card), NULL);
	}
	previous_card = first_card;
//												printf("\nin create_deck : previous_card=[%p] =? first_card=[%p]\n", previous_card , first_card);
	i = 2;
	while (i < argc)
	{
		next_card = create_card(previous_card, argv[i]);
		if (!next_card)
			return (free_deck(previous_card), NULL);
		previous_card = next_card;
		i++;
	}
	return (first_card);
}
