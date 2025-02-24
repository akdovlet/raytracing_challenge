/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_for_pixel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 20:36:39 by akdovlet          #+#    #+#             */
/*   Updated: 2025/02/21 18:51:43 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ray_for_pixel(t_camera *cam, t_ray *ray, double x, double y)
{
	double	world_y;
	double	world_x;
	t_tuple	pixel;

	world_x = cam->half_width - ((x + 0.5) * cam->psize);
	world_y = cam->half_height - ((y + 0.5) * cam->psize);
	pixel = matrix_multiply_tuple(cam->transform, point_new(world_x, world_y, -1));
	// ray->origin = matrix_multiply_tuple(cam->transform, point_new(0, 0, 0));
	ray->direction = tuple_normalize(tuple_substract(pixel, ray->origin));
}

void	cache_ray(t_ray *ray, t_camera *cam)
{
	int	y;
	int	x;
	t_tuple origin;
	
	origin = matrix_multiply_tuple(cam->transform, point_new(0, 0, 0));
	y = 0;
	while (y < cam->vsize)
	{
		x = 0;
		while (x < cam->hsize)
		{
			ray[x + y * cam->hsize].origin = origin;
			ray_for_pixel(cam, &ray[x + y * cam->hsize], x, y);
			x++;
		}
		y++;
	}
}
