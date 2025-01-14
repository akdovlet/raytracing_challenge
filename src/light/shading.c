/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 15:32:02 by akdovlet          #+#    #+#             */
/*   Updated: 2025/01/10 16:25:02 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "light.h"

bool	is_shadowed(t_world world, t_tuple point)
{
	t_tuple	v;
	float	distance;
	t_tuple	direction;
	t_ray	ray;
	t_junction	hits;

	v = tuple_substract(world.light.position, point);
	distance = tuple_magnitude(v);
	direction = tuple_normalize(v);
	ray = ray_new(point, direction);
	intersect_world(world, ray, &hits);
	return (hits.count && hits.cross[0].t < distance);
}

t_tuple	shade_hit(t_world world, t_comps comps)
{
	// bool	shadowed;

	// shadowed = is_shadowed(world, comps.overz);
	return (blinn_phong(
		comps.obj.matter,
		world.light,
		comps.overz,
		comps.eyev,
		comps.normalv,
		false,
		comps.obj));
}
