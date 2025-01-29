/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 15:32:02 by akdovlet          #+#    #+#             */
/*   Updated: 2025/01/29 15:33:07 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "light.h"

bool	is_shadowed(t_world *world, t_tuple point)
{
	t_tuple	v;
	double	distance;
	t_tuple	direction;
	t_ray	ray;
	t_junction	hits;

	v = tuple_substract(world->light.position, point);
	distance = tuple_magnitude(v);
	direction = tuple_normalize(v);
	ray = ray_new(point, direction);
	intersect_world(world, ray, &hits);
	// if (hits.hit && hits.closest.t < distance && !hits.closest.obj.matter.transparency)
	if (hits.hit && hits.closest.t < distance && ! world->obj[hits.closest.shape_index].matter.transparency)
		return (true);
	return (false);
}

t_tuple	shade_hit(t_world *world, t_comps *comps, int depth)
{
	bool	shadowed;
	double	reflectance;
	t_tuple	surface;
	t_tuple reflected;
	t_tuple refracted;


	shadowed = is_shadowed(world, comps->overz);
	surface = blinn_phong(world->obj[comps->shape_index].matter, world->light, 
			comps->overz, comps->eyev, comps->normalv,
			shadowed, world->obj[comps->shape_index]);
	reflected = reflected_color(world, comps, depth - 1);
	refracted = refracted_color(world, comps, depth - 1);
	if (world->obj[comps->shape_index].matter.reflective > 0.0 && world->obj[comps->shape_index].matter.transparency > 0.0)
	{
		reflectance = schlick(comps);
		return (tuple_add(surface, tuple_add(tuple_multiply(reflected, reflectance),
							tuple_multiply(refracted, 1 - reflectance))));
	}
	return (tuple_add(tuple_add(surface, reflected), refracted));
}
