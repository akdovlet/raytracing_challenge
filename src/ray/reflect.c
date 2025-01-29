/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 17:13:01 by akdovlet          #+#    #+#             */
/*   Updated: 2025/01/29 15:33:31 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "tuple.h"
#include "colors.h"

t_tuple	reflect(t_tuple in, t_tuple normal)
{
	double	dot_product;
	t_tuple	reflection;

	dot_product = tuple_dot(in, normal);
	reflection = tuple_multiply(normal, 2.0);
	reflection = tuple_multiply(reflection, dot_product);
	reflection = tuple_substract(in, reflection);
	return (reflection);
}

t_tuple	reflected_color(t_world *world, t_comps *comps, int depth)
{
	t_ray	reflect_ray;
	t_tuple	color;

	if (depth <= 0 || !world->obj[comps->shape_index].matter.reflective)
		return (color_new(0, 0, 0));
	reflect_ray = ray_new(comps->overz, comps->reflectv);
	color = color_at(world, reflect_ray, depth);
	return (tuple_multiply(color, world->obj[comps->shape_index].matter.reflective));
}
