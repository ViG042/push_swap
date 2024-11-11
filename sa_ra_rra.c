/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_ra_rra.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgodoy <vgodoy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 16:38:33 by vgodoy            #+#    #+#             */
/*   Updated: 2024/11/11 15:13:03 by vgodoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_decks *decks)
{
	t_card	*a;

	a = decks->deck_a;
	a = swap(a);
	decks->deck_a = a;
	write(1,"sa\n",3);
}

void	ra(t_decks *decks, bool speak)
{
	t_card	*a;

	a = decks->deck_a;
	a = rotate(a);
	decks->deck_a = a;
	if (speak)
		write(1,"ra\n",3);
}

void	rra(t_decks *decks, bool speak)
{
	t_card	*a;

	a = decks->deck_a;
	a = reverse_rotate(a);
	decks->deck_a = a;
	if (speak)
		write(1,"rra\n",4);
}
