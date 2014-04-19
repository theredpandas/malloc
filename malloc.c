/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbres <sbres@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/17 11:31:51 by sbres             #+#    #+#             */
/*   Updated: 2014/04/19 10:54:38 by sbres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"
#include <stdlib.h>

/*
** Au debut de malloc on va pre_alouer les tables
** Apres on va rajouter la taille du header pour definir une categorie
*/

void	*ft_malloc(size_t size)
{
	static int		is_init = 0;
	void			*memory_zone;

	if (size <= 0)
		return (NULL);
	if (is_init == 0)
	{
		init_pages();
		is_init = 1;
	}
	if (size <= TINY_MAX)
		memory_zone = ft_tiny_malloc(size);
	else if (size <= MEDIUM_MAX)
		memory_zone = ft_medium_malloc(size);
	else
		memory_zone = ft_big_malloc(size);
	return (memory_zone);
}

int main(int argc, char const *argv[])
{
	char	*toto;

	toto = (char*)ft_malloc(25);
	ft_malloc(25);
	ft_malloc(150);
	ft_malloc(1800);
	ft_malloc(180);
	ft_malloc(160);
	ft_malloc(150);
	ft_malloc(18);
	ft_malloc(15);
	show_alloc_mem();
	ft_free(toto);
	printf("\n\n");
	show_alloc_mem();
	//printf("%zu\n", sizeof(char));
	return 0;
}
