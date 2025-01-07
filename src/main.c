/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:21:08 by akdovlet          #+#    #+#             */
/*   Updated: 2025/01/07 18:41:34 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "test.h"
#include "tuple.h"

void	put_pixel(t_img *img, unsigned int color, t_tuple t1)
{
	t_tuple center;
	
	center = (t_tuple){WIDTH / 2, HEIGHT / 2, 0, 1};
	ak_pixel_put(img, tuple_add(center, t1), color);
}

int main()
{
	t_img	img;
	t_mlx	mlx;

	init_mlx(&mlx, &img);
	mlx_key_hook(mlx.win_ptr, &key_manager, &mlx);
	mlx_hook(mlx.win_ptr, 17, 0, mlx_loop_end, mlx.mlx_ptr);

	// position_test();
	// sphere_test();
	// transform_test();
	// object_transform_test();
	// draw_sphere(&img, &mlx);
	// test_intersect_world();
	// test_light();
	// position_test();
	// normal_at_test();
	// transpose_test();
	// reflect_test();
	// test_color();
	// intersection_test();
	// test_pre_compute();
	// test_shading();
	// test_color_at();
	// test_view_transform();
	// test_camera();
	// test_ray_for_pixel();
	// test_render_world(&img, &mlx);
	test_scene(&img, &mlx);
	// test_is_shadowed();
	// test_shape_obj();
	test_intersect_plane();
	// mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, img.img_ptr, 0, 0);

	mlx_loop(mlx.mlx_ptr);
	mlx_clear(&mlx, &img);
	printf("AK out!\n");
	return (0);
}
