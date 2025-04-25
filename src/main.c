/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafernan < vafernan@student.42porto.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-03 16:20:47 by vafernan          #+#    #+#             */
/*   Updated: 2025-03-03 16:20:47 by vafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

/// @brief Closes the game window and exits the program.
/// @param game A pointer to the game structure containing the window data.
/// @return Always returns 0.
int	close_window(t_game *game)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (game->texture_img[i])
			mlx_destroy_image(game->mlx, game->texture_img[i]);
		i++;
	}
	free(game->path_north);
	free(game->path_south);
	free(game->path_west);
	free(game->path_east);
	ft_free_map(game->map);
	if (game->img)
		mlx_destroy_image(game->mlx, game->img);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	exit(0);
	return (0);
}

/// @brief Handles key press events, specifically the ESC key to close the game.
/// @param key The key code of the pressed key.
/// @param game A pointer to the game structure.
/// @return Always returns 0.
int	handle_key(int key, t_game *game)
{
	if (key == 65307)
		close_window(game);
	return (0);
}

/// @brief The main function that initializes the game and starts the main loop
/// ofr mlx_hook event type 2 KeyPress, 3 keyRelease, and 17 DestroyNotify.
/// for mlx_hook masks 1L <<< 0 keyPressMask, 1L << 1 keyReleaseMask
/// 0 DestroyNotifyMask.
/// @return Always returns 0.
int	main(int argc, char **argv)
{
	t_game	game;

	if (!ft_check(argc, argv))
		return (0);
	init_game(&game, argv);
	mlx_hook(game.win, 2, 1L << 0, key_press, &game);
	mlx_hook(game.win, 3, 1L << 1, key_release, &game);
	mlx_hook(game.win, 17, 0, close_window, &game);
	mlx_loop_hook(game.mlx, draw_loop, &game);
	mlx_loop(game.mlx);
	return (0);
}
