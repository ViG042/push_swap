/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_r_rr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgodoy <vgodoy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 15:30:58 by vgodoy            #+#    #+#             */
/*   Updated: 2024/10/23 20:05:44 by vgodoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_card	*swap2(t_card *first, t_card *second)
{
	first->prev = second;
	second->next = first;
	second->prev = NULL;
	first->next = NULL;
	return (second);
}

t_card	*swap(t_card *first)
{
	t_card	*second;
	t_card	*third;

	if (first == NULL || first->next == NULL)
		return (first);
	second = first->next;
	if (second->next == NULL)
		return (swap2(first, second));
	third = second->next;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	first->next = third;
	third->prev = first;
	return (second);
}

t_card	*rotate(t_card *first)
{
	t_card	*second;
	t_card	*last;

	if (first == NULL || first->next == NULL)
		return (first);
	second = first->next;
	if (second->next == NULL)
		return (swap2(first, second));
	last = second->next;
	while (last->next != NULL)
		last = last->next;
	second->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
	return (second);
}

t_card	*reverse_rotate(t_card *first)
{
	t_card	*last;
	t_card	*before_last;

	if (first == NULL || first->next == NULL)
		return (first);
	last = first->next;
	if (last->next == NULL)
		return (swap2(first, last));
	while (last->next != NULL)
		last = last->next;
	before_last = last->prev;

	last->next = first;
	first->prev = last;
	before_last->next = NULL;
	last->prev = NULL;
	return (last);
}
