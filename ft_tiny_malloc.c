/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tiny_malloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbres <sbres@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/18 18:55:49 by sbres             #+#    #+#             */
/*   Updated: 2014/04/19 10:06:18 by sbres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"
#include <stdlib.h>

void	*ft_tiny_malloc(size_t size)
{
	t_data	*tmp;
	void	*new_area;
	printf("tiny\n");

	// printf("%p\n", pages.tiny);
	tmp = pages.tiny;
	// printf("%p\n", pages.tiny);
	// printf("%d\n", pages.tiny);
	// printf("id freee%d\n", tmp->is_free);
	// printf("tmp size%d\n", tmp->size);
	// printf("next ? %p\n", tmp->next );
	while ((tmp->is_free == 0 && tmp->size <= size ) || tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	if (tmp->size < size || tmp->is_free == 0)
		return (NULL);
	if (tmp->size == size)
	{
		tmp->is_free = 0;
		return (tmp->ptr);
	}
	new_area = tmp->ptr;
	// printf("new = %p\nsize = %d\n", new_area, size);
	new_area += size;//SI SA BUG C'est sa sa stock la nouvelle memoire
	//printf("new = %p\n", new_area);
	new_block(tmp->size - size, new_area, 1, &pages.tiny);
	tmp->is_free = 0;
	tmp->size = size;
	return (tmp->ptr);
}
