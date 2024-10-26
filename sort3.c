/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgodoy <vgodoy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 14:27:18 by vgodoy            #+#    #+#             */
/*   Updated: 2024/10/26 16:47:29 by vgodoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_card	*find_bigger(t_card *a)
{
	t_card	*bigger;

	bigger = a;
	while (a->next != 0)
	{
		a = a->next;
		if (a->nbr > bigger->nbr)
			bigger = a;
	}
	return (bigger);
}

bool	sorted(t_card *a)
{
	while (a->next != 0 && a->next->nbr > a->nbr)
		a = a->next;
	if (a->next == 0)
		return (1);
	else
		return (0);
}

t_card	*sort3(t_card *a)
{
	if (sorted(a))
		return (a);
	if (find_bigger(a) == a)
		a = rotate(a);
	else if (find_bigger(a) == a->next)
		a = reverse_rotate(a);
	if (a->nbr > a->next->nbr)
		a = swap(a);
	return (a);
}
