/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 18:28:04 by akdovlet          #+#    #+#             */
/*   Updated: 2025/01/14 18:35:09 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	mouse_manager(int button, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	if (button == 4)
		data->cam.from.z += 0.1;
	if (button == 5)
		data->cam.from.z -= 0.1;
	render_and_move(data);
	return (0);
}
