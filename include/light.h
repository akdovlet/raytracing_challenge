/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 19:47:37 by akdovlet          #+#    #+#             */
/*   Updated: 2025/01/10 16:23:58 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_struct.h"

t_light	point_light(t_tuple point, t_tuple intensity);
t_tuple	shade_hit(t_world world, t_comps comps);
t_tuple	lighting(t_material mat, t_light light, t_tuple eyev, 
t_tuple normalv, t_tuple point);
// t_tuple	blinn_phong(t_material mat, t_light light, t_tuple eyev,
// t_tuple normalv, t_tuple point);
// t_tuple	blinn_phong(t_material mat, t_light light, t_tuple overz, t_tuple eyev, t_tuple normalv, bool shadowed);
t_tuple	blinn_phong(t_material mat, t_light light, t_tuple overz, t_tuple eyev, t_tuple normalv, bool shadowed, t_shape shape);

