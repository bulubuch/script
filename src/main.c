/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuch <mbuch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 09:23:25 by mbuch             #+#    #+#             */
/*   Updated: 2019/12/04 14:02:42 by mbuch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_script.h"

static uint8_t		get_option(char c)
{
	uint8_t			opt;
	int				i;

	i = 0;
	opt = 1;
	while (SCRIPT_OPTIONS[i] != '\0')
	{
		if (SCRIPT_OPTIONS[i] == c)
			return (opt);
		opt *= 2;
		i++;
	}
}

static int			get_options(t_job *job, int ac, char **av)
{
	int				i;
	int				j;
	uint8_t			o;

	i = 1;
	job->opt = 0;
	while (i < ac)
	{
		j = 1;
		if (av[i][0] == '-')
		{
			while ((o = get_option(av[i][j])))
			{
				job->opt |= o;
				j++;
			}
		}
		else
			return (i);
		i++;
	}
	return (0);
}

int					init_job(t_job *job, int ac, char **av)
{
	job->filename = NULL;
	job->opt = get_options(job, ac, av);
}

int					main(int ac, char **av)
{
	uint8_t			opt;
	char			buf[BUF_SIZE];

	opt = 0;
	if (ac == 1)
		return (script(open("typescript", O_WRONLY | \
		O_CREAT | O_TRUNC, 0755), opt));
	else
	{
		opt = get_options(ac, av);
		return (script(open("typescript", O_WRONLY | \
		O_CREAT | O_TRUNC, 0755), opt));
	}
	time_t		now;
	time();
	return (0);
}