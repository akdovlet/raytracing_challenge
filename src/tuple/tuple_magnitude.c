/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_magnitude.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:34:33 by akdovlet          #+#    #+#             */
/*   Updated: 2024/12/16 18:38:47 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

float	tuple_magnitude(t_tuple a)
{
	return (sqrt((a.x * a.x) + (a.y * a.y) + (a.z * a.z) + (a.w * a.w)));
}
