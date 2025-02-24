/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 18:22:01 by akdovlet          #+#    #+#             */
/*   Updated: 2025/02/24 15:52:56 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "shapes.h"

void	render(t_camera cam, t_world world, t_img *img, t_mlx *mlx)
{
	int	y;
	int	x;
	t_ray	*ray;
	t_tuple	color;

	y = 0;
	ray = malloc(sizeof(t_ray) * (cam.vsize * cam.hsize));
	if (!ray)
		return ;
	cache_ray(ray, &cam);
	while (y < cam.vsize)
	{
		x = 0;
		while (x < cam.hsize)
		{
			color = color_at(&world, ray[x + y * cam.hsize], 5);
			ak_mlx_pixel_put(img, x, y, tuple_tocolor(color));
			x++;
		}
		y++;
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, img->img_ptr, 0, 0);
	}
	free(ray);
}

void	path_tracing(t_ray *ray, t_camera cam, t_world world, t_img *img, t_mlx *mlx, double frame_index,t_tuple *accumulation)
{
	int		y;
	int		x;
	t_tuple	color;
	t_tuple	final_color;

	y = 0;
	while (y < cam.vsize)
	{
		x = 0;
		while (x < cam.hsize)
		{
			color = trace_rays(&world, ray[x + y * WIDTH], (x + y * WIDTH) * frame_index);
			if (frame_index == 1)
				accumulation[x + y * WIDTH] = color;
			else
				accumulation[x + y * WIDTH] = tuple_add(accumulation[x + y * WIDTH], color);
			final_color = accumulation[x + y * WIDTH];
			final_color = tuple_divide(final_color, frame_index);
			ak_mlx_pixel_put(img, x, y, tuple_tocolor(final_color));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, img->img_ptr, 0, 0);
}

void	render_accumulation(t_camera cam, t_world world, t_img *img, t_mlx *mlx)
{
	double				frame_index;
	t_tuple				*accumulation;
	t_ray				*ray;

	frame_index = 1;
	ray = malloc(sizeof(t_ray) * (WIDTH * HEIGHT));
	accumulation = malloc(sizeof(t_tuple) * (WIDTH * HEIGHT));
	if (!accumulation || !ray)
		return ;
	cache_ray(ray, &cam);
	while (frame_index < 100)
	{
		path_tracing(ray, cam, world, img, mlx, frame_index, accumulation);
		frame_index++;
	}
	free(ray);
	free(accumulation);
}

int	render_and_move(t_data *data)
{
	int		y;
	int		x;
	t_ray	*ray;
	t_tuple	color;
	clock_t	start;
	clock_t	end;

	y = 0;
	start = clock();
	ray = malloc(sizeof(t_ray) * (WIDTH * HEIGHT));
	if (!ray)
		return (1);
	cache_ray(ray, &data->cam);
	while (y < data->cam.vsize)
	{
		x = 0;
		while (x < data->cam.hsize)
		{
			color = color_at(&data->world, ray[x + y * WIDTH], 5);
			ak_mlx_pixel_put(&data->img, x, y, tuple_tocolor(color));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx.mlx_ptr, data->mlx.win_ptr, data->img.img_ptr, 0, 0);
	end = clock();
	data->ts = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("frame time: %f ms\n", data->ts);
	free(ray);
	return (0);
}

