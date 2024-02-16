/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_nodes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:20:01 by rcutte            #+#    #+#             */
/*   Updated: 2024/01/31 14:55:24 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/pipex.h"

/**
 * * Create a new cmd struct
 * @return The new cmd struct
 */
t_cmd	*ft_new_cmd(void)
{
	t_cmd	*new_cmd;

	new_cmd = malloc(sizeof(t_cmd));
	if (!new_cmd)
		return (ft_putstr_fd("Error new_cmd alloc\n", 2), NULL);
	new_cmd->cmd_path = NULL;
	new_cmd->args = NULL;
	new_cmd->empty = 0;
	new_cmd->amount_args = 0;
	new_cmd->cmd_path = NULL;
	new_cmd->next = NULL;
	new_cmd->prev = NULL;
	return (new_cmd);
}

/**
 * *Add a node to the end of the stack
 * @params: stack, value
 */
void	ft_cmd_add_last(t_pipex *pipex, t_cmd *new)
{
	t_cmd	*tmp;

	if (!new)
		return ;
	if (!pipex->cmd_head)
	{
		pipex->cmd_head = new;
		return ;
	}
	tmp = pipex->cmd_head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	new->prev = tmp;
}

/**
 * *Delete the first cmd of the list
 * @params: stack
 */
void	ft_del_first_cmd(t_pipex *pipex)
{
	t_cmd	*tmp;

	tmp = pipex->cmd_head;
	if (pipex->cmd_head->next != NULL)
		pipex->cmd_head = pipex->cmd_head->next;
	ft_free_cmd(tmp);
}

void	ft_del_one_cmd(t_cmd *cmd, t_pipex *pipex)
{
	if (!cmd)
		return ;
	if (cmd == pipex->cmd_head)
	{
		pipex->cmd_head = cmd->next;
		if (pipex->cmd_head)
			pipex->cmd_head->prev = NULL;
	}
	else if (cmd->next == NULL)
	{
		cmd->prev->next = NULL;
	}
	else
	{
		cmd->prev->next = cmd->next;
		cmd->next->prev = cmd->prev;
	}
	ft_free_cmd(cmd);
}
