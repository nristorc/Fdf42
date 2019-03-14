/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nristorc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 12:49:32 by nristorc          #+#    #+#             */
/*   Updated: 2017/11/14 10:41:02 by nristorc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}