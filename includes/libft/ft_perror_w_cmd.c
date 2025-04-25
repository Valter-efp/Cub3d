/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perror_w_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafernan <vafernan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:37:24 by vafernan          #+#    #+#             */
/*   Updated: 2025/02/03 15:42:57 by vafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_perror_w_cmd(int error_code, const char *command)
{
	char	error_message[256];

	ft_strcpy(error_message, "minishell: ");
	ft_strcat(error_message, command);
	ft_strcat(error_message, ": ");
	if (error_code == 1)
		ft_strcat(error_message, "No such file or directory\n");
	else if (error_code == 2)
		ft_strcat(error_message, "Is a directory\n");
	else if (error_code == 3)
		ft_strcat(error_message, "Permission denied\n");
	else if (error_code == 4)
		strcat(error_message, "command not found\n");
	ft_perror(error_message);
}
