/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 14:43:28 by akdovlet          #+#    #+#             */
/*   Updated: 2025/02/02 15:28:47 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "light.h"
#include "tuple.h"
#include "shapes.h"

t_world	default_world(void)
{
	t_world		world;

	world.light = point_light(point_new(-10, 10, -10), color_new(1, 1, 1));
	world.obj[0] = sphere_default();
	world.obj[0].matter = material();
	world.obj[0].matter.color = color_new(0.8, 1.0, 0.6);
	world.obj[0].matter.diffuse = 0.7;
	world.obj[0].matter.specular = 0.2;
	world.obj[1] = sphere_default();
	world.obj[1].transform = (scale(0.5, 0.5 , 0.5));
	world.obj[1].matter = material();
	world.obj_count = 2;
	return (world);
}

void	sort_hits(t_junction *hits)
{
	int			i;
	int			j;
	t_crossing	tmp;


	i = 0;
	while (i < hits->count)
	{
		j = i + 1;
		while (j < hits->count)
		{
			if (hits->cross[i].t > hits->cross[j].t)
			{
				tmp = hits->cross[i];
				hits->cross[i] = hits->cross[j];
				hits->cross[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	find_hit(t_junction *hits)
{
	int	i;

	i = 0;
	hits->hit = false;
	while (i < hits->count)
	{
		if (hits->cross[i].t >= 0.0)
		{
			hits->closest = hits->cross[i];
			hits->hit = true;
			break ;
		}
		i++;
	}
}

void	intersect_world(t_world *world, t_ray ray, t_junction *hits)
{
	int				i;
	int				j;
	t_intersection	inter;

	i = 0;
	j = 0;
	hits->count = 0;
	while (i < world->obj_count)
	{
		inter = hit(intersection(world->obj[i], intersect(ray, world->obj[i])));
		if (inter.count)
		{
			hits->count += inter.count;
			hits->cross[j].t = inter.xs.x;
			hits->cross[j++].obj = world->obj[i];
			if (inter.count == 2)
			{
				hits->cross[j].t = inter.xs.y;
				hits->cross[j++].obj = world->obj[i];
			}
		}
		i++;
	}
	sort_hits(hits);
	find_hit(hits);
}

t_tuple	color_at(t_world *world, t_ray ray, int depth)
{
	t_tuple		color;
	t_comps		comps;
	t_junction	hits;

	intersect_world(world, ray, &hits);
	color = color_new(0, 0, 0.01);
	if (hits.hit)
	{
		pre_compute(&comps, hits.closest, ray, hits);
		color = shade_hit(world, &comps, depth);
	}
	return (color);
}
