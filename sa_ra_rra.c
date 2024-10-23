/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_ra_rra.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgodoy <vgodoy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 16:38:33 by vgodoy            #+#    #+#             */
/*   Updated: 2024/10/23 19:45:13 by vgodoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_decks *decks)
{
	t_card	*a;

	a = decks->deck_a;
	a = swap(a);
	decks->deck_a = a;
}

void	ra(t_decks *decks)
{
	t_card	*a;

	a = decks->deck_a;
	a = rotate(a);
	decks->deck_a = a;
}

void	rra(t_decks *decks)
{
	t_card	*a;

	a = decks->deck_a;
	a = reverse_rotate(a);
	decks->deck_a = a;
}
