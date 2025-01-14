/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 14:43:28 by akdovlet          #+#    #+#             */
/*   Updated: 2025/01/10 16:43:30 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "light.h"
#include "tuple.h"
#include "objects.h"

t_world	default_world(void)
{
	t_world		world;

	world.light = point_light(point_new(-10, 10, -10), color_new(1, 1, 1));
	world.obj[0] = sphere(point_new(0.0, 0.0, 0.0), 1);
	world.obj[0].matter = material();
	world.obj[0].matter.color = color_new(0.8, 1.0, 0.6);
	world.obj[0].matter.diffuse = 0.7;
	world.obj[0].matter.specular = 0.2;
	world.obj[1] = sphere(point_new(0.0, 0.0, 0.0), 1);
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

	if (hits->count <= 1)
		return;
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
	// return (hits);
}

bool intersect_world(t_world world, t_ray ray, t_junction *hits)
{
	int				i;
	int				j;
	t_intersection	inter;

	i = 0;
	j = 0;
	hits->count = 0;
	while (i < world.obj_count)
	{
		inter = intersection(world.obj[i], intersect(ray, world.obj[i]));
		if (hit(&inter))
		{
			hits->count += inter.count;
			hits->cross[j].t = inter.xs.x;
			hits->cross[j++].obj = world.obj[i];
			if (inter.count == 2)
			{
				hits->cross[j].t = inter.xs.y;
				hits->cross[j++].obj = world.obj[i];
			}
		}
		i++;
	}
	if (hits->count)
	{
		sort_hits(hits);
		return (true);
	}
	return (false);
}

t_color	color_at(t_world world, t_ray ray)
{
	t_tuple		color;
	t_comps		comps;
	t_junction	hits;

	color = color_new(0, 0, 0);
	if (intersect_world(world, ray, &hits))
	{
		comps = pre_compute(hits.cross[0], ray);
		color = shade_hit(world, comps);
	}
	return (tuple_tocolor(color));
}
