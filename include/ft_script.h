/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_script.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuch <mbuch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 08:35:20 by mbuch             #+#    #+#             */
/*   Updated: 2019/12/04 16:28:08 by mbuch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_SCRIPT_H_
# define _FT_SCRIPT_H_

# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <time.h>

# define BASE_16_LOW	"0123456789abcdef"
# define BASE_16_UP		"0123456789ABCDEF"

# define SCRIPT_OPTIONS	"adFkpqrt"
# define OPT_APPEND		1
# define OPT_DIRECT		2
# define OPT_FLUSH		4
# define OPT_KLOG		8
# define OPT_PLAY		16
# define OPT_QUIET		32
# define OPT_RECORD		64
# define OPT_TIME		128
# define BUF_SIZE		512

typedef struct			s_job
{
	uint8_t				opt;
	char				*filename;
	time_t				last;
	int					delay;
}						t_job;

typedef struct			s_entry
{
	time_t				timestamp;

}						t_entry;

#endif