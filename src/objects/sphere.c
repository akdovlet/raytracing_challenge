/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 10:09:08 by akdovlet          #+#    #+#             */
/*   Updated: 2025/01/07 18:53:29 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"

static t_vec2	local_intersect(t_ray ray, t_shape shape)
{
	float	a;
	float	b;
	float	c;
	float	dis;
	t_tuple	local_ray;

	ray = ray_transform(ray, inverse(shape.transform));
	local_ray = tuple_substract(ray.origin, shape.coordinates);
	a = tuple_dot(ray.direction, ray.direction);
	b = 2 * tuple_dot(ray.direction, local_ray);
	c = tuple_dot(local_ray, local_ray) - 1;
	dis = pow(b, 2) - 4 * a * c;
	return ((t_vec2){
		.dis = dis,
		.x = (-b - sqrt(dis)) / (2 * a),
		.y = (-b + sqrt(dis)) / (2 * a)
	});
}


static t_tuple	local_normal_at(t_shape obj, t_tuple world_point)
{
	t_tuple object_point;
	t_tuple	object_normal;
	t_tuple	world_normal;

	object_point = matrix_multiply_tuple(inverse(obj.transform), world_point);
	object_normal = tuple_substract(object_point, obj.coordinates);
	world_normal = matrix_multiply_tuple(matrix_transpose(inverse(obj.transform)), object_normal);
	world_normal.w = 0;
	return (tuple_normalize(world_normal));
}

t_shape	sphere(t_tuple point, float radius)
{
	t_shape	new;

	new = (t_shape){
		.coordinates = point,
		.radius = radius,
		.id = (uintptr_t) &new,
		.type = SPHERE,
		.transform = identity(),
		.local_interesct = &local_intersect,
		.local_normalat = &local_normal_at
	};
	return (new);
}

t_shape	sphere_default(void)
{
	t_shape	new;

	new = (t_shape){
		.coordinates = point_new(0, 0, 0),
		.radius = 1,
		.id = (uintptr_t) &new,
		.type = SPHERE,
		.transform = identity(),
		.local_interesct = &local_intersect,
		.local_normalat = &local_normal_at
	};
	return (new);
}

void	set_transform(t_shape *obj, t_matrix m)
{
	obj->transform = m;
}
