/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_minor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 15:33:11 by akdovlet          #+#    #+#             */
/*   Updated: 2024/12/23 17:59:16 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

float	matrix_minor(float **m, int row, int col, int size)
{
	float	**sub;
	float	determinant;

	sub = sub_matrix(m, size, row, col);
	if (!sub)
		return (0);
	determinant = matrix_determinant(sub);
	matrix_free(sub, size - 1);
	return (determinant);
}
