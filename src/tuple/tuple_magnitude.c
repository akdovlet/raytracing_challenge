/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_magnitude.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:34:33 by akdovlet          #+#    #+#             */
/*   Updated: 2025/02/11 19:15:00 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	tuple_magnitude(v4 a)
{
	a *= a;
	return (sqrt(a[0] + a[1] + a[2] + a[3]));
}
