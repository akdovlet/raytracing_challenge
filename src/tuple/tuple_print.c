/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 16:46:18 by akdovlet          #+#    #+#             */
/*   Updated: 2024/12/23 16:47:22 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	tuple_print(t_tuple t1)
{
	fprintf(stderr, "x: %f, y: %f, z: %f, w: %f\n", t1.x, t1.y, t1.z, t1.w);
}
