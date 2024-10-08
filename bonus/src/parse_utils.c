/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 00:36:32 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/09/12 00:36:32 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	find_first_one(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] != 'X')
			break ;
	return (i);
}

int	find_last_one(char *str)
{
	int	i;

	i = ft_strlen(str);
	while (--i > 0)
		if (str[i] != 'X')
			break ;
	return (i);
}

void	take_max_x(char **res, t_game *cub3d)
{
	int	i;

	i = -1;
	while (res[++i])
		if (take_line_len(res[i]) > cub3d->map.size.x)
			cub3d->map.size.x = take_line_len(res[i]);
}

int	take_line_len(char	*str)
{
	int	len;
	int	i;

	if (!str)
		return (0);
	i = -1;
	len = 0;
	while (str[++i])
	{
		if (str[i] == '\t')
			len += 4;
		else
			len++;
	}
	return (len);
}

void	free_dpointer(char	**arr)
{
	int	i;

	i = -1;
	if (!arr)
		return ;
	while (arr[++i])
		free (arr[i]);
	free (arr);
}
