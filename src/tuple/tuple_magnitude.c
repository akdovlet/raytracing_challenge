/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_magnitude.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:34:33 by akdovlet          #+#    #+#             */
/*   Updated: 2025/01/09 18:39:26 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

float	tuple_magnitude(t_tuple a)
{
	a *= a;
	return (sqrt(a[0] + a[1] + a[2] + a[3]));
}
