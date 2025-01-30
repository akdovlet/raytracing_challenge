/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 10:09:08 by akdovlet          #+#    #+#             */
/*   Updated: 2025/01/30 16:52:42 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"

t_vec2	sphere_intersect(t_ray ray, t_shape shape)
{
	double	a;
	double	b;
	double	c;
	double	dis;
	t_tuple	local_ray;

	local_ray = tuple_substract(ray.origin, shape.coordinates);
	a = tuple_dot(ray.direction, ray.direction);
	b = 2 * tuple_dot(ray.direction, local_ray);
	c = tuple_dot(local_ray, local_ray) - 1.0;
	dis = pow(b, 2.0) - 4.0 * a * c;
	return ((t_vec2){
		.dis = dis,
		.x = (-b - sqrt(dis)) / (2.0 * a),
		.y = (-b + sqrt(dis)) / (2.0 * a)
	});
}

t_tuple	sphere_normal_at(t_shape obj, t_tuple point)
{
	t_tuple	object_normal;

	object_normal = tuple_substract(point, obj.coordinates);
	return (object_normal);
}

t_shape	sphere(t_tuple point, double radius)
{
	t_shape	new;

	new = (t_shape){
		.coordinates = point,
		.radius = radius,
		.id = new_id(),
		.type = SPHERE,
		.transform = identity(),
		.matter = material(),
		.local_interesct = &sphere_intersect,
		.local_normalat = &sphere_normal_at
	};
	return (new);
}

t_shape	sphere_default(void)
{
	t_shape	new;

	new = (t_shape){
		.coordinates = point_new(0, 0, 0),
		.radius = 1,
		.id = new_id(),
		.type = SPHERE,
		.transform = identity(),
		.matter = material(),
		.local_interesct = &sphere_intersect,
		.local_normalat = &sphere_normal_at
	};
	return (new);
}

void	set_transform(t_shape *obj, t_matrix m)
{
	obj->transform = inverse(m);
}
