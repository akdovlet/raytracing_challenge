/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_cmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 11:33:23 by akdovlet          #+#    #+#             */
/*   Updated: 2024/12/20 14:04:15 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	matrix_cmp(float **m1, float **m2, int row, int col)
{
	int	i;
	int	j;

	i = 0;
	while (i < row)
	{
		j = 0;
		while (j < col)
		{
			if (m1[i][j] != m2[i][j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
