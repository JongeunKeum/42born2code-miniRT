#ifndef PARSE_H
# define PARSE_H

# include "minirt.h"

int	parse_rt(char	*argv, t_scene *scene);
int	handle_info(char **info, t_scene *scene);
int	info_r(char	**info, t_scene *scene);
int	info_c(char **info, t_scene *scene);
int	info_l(char **info, t_scene *scene);
int	info_sp(char **info, t_scene *scene, t_object **world);
int	info_pl(char **info, t_scene *scene, t_object **world);
int	info_sq(char **info, t_scene *scene, t_object **world);
int	info_cy(char **info, t_scene *scene, t_object **world);
int	info_tr(char **info, t_scene *scene, t_object **world);

int	ft_isright_info(char c);
int	check_info_err(char **info);

#endif
