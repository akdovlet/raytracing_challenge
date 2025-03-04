/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 10:22:22 by akdovlet          #+#    #+#             */
/*   Updated: 2025/01/15 14:09:10 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_matrix	scale(double x, double y, double z)
{
	return ((t_matrix){{
			{x, 0, 0, 0}, \
			{0, y, 0, 0}, \
			{0, 0, z, 0}, \
			{0, 0, 0, 1} \
	}});
}

t_matrix	translate(double x, double y, double z)
{
	return ((t_matrix){{
			{1, 0, 0, x}, \
			{0, 1, 0, y}, \
			{0, 0, 1, z}, \
			{0, 0, 0, 1} \
	}});
}
