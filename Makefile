# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hwolff <hwolff@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/14 13:21:32 by hben-yah          #+#    #+#              #
#    Updated: 2018/11/01 14:28:07 by hwolff           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	21sh

COMP			=	clang
FLAG			=	-Wall -Wextra -Werror -g3
FLAGDEGUG		=	$(FLAG) -fsanitize=address

# Files names
BUILTINS_N		=	builtins_cd.c builtins_echo.c builtins_env.c builtins_exit.c \
					builtins_main.c builtins_setenv.c builtins_tools.c \
					builtins_unsetenv.c
EXPANSIONS_N	=	expansions_dollar.c expansions_main.c expansions_tilde.c \
					arithmetics.c
INHIBITORS_N	=	backslash.c quotes.c
CORE_N			=	shell.c error.c free.c get_executable.c parse.c read.c \
					ft_enter.c setup.c loop.c
EDITLINE_N		=	mouve.c print_line.c

# Sources paths
FILES_C			=	$(addprefix builtins/, $(BUILTINS_N)) \
					$(addprefix expansions/, $(EXPANSIONS_N)) \
					$(addprefix inhibitors/, $(INHIBITORS_N)) \
					$(addprefix editline/, $(EDITLINE_N)) \
					$(addprefix core/, $(CORE_N)) \

FILES_O			=	$(FILES_C:.c=.o)
FILES_H			=	shell.h

# Directories
SRCS_SD			= 	builtins expansions inhibitors core editline
SRCS_D			=	./srcs/
OBJS_D			=   ./objs/
INCL_D 			=	./includes/

# Paths
SRCS			= 	$(addprefix $(SRCS_D), $(FILES_C))
OBJS			=	$(addprefix $(OBJS_D), $(FILES_O))
INCL			=	$(addprefix $(INCL_D), $(FILES_H))

# Libft
LFT_D			=	./libft/
LFT_P			=	$(addprefix $(LFT_D), libft.a)
LFT_I			=	./libft/includes/
LFT_L			=	./libft
LFT_H			=	libft.h ft_boolean.h ft_char.h ft_collection.h ft_convert.h ft_input.h \
					ft_integer.h ft_list.h ft_math.h ft_memory.h ft_misc.h ft_output.h \
					ft_printf.h ft_sort.h ft_string.h ft_stringbuffer.h ft_table.h

# Termcaps

TRMCP_I			=	-ltermcap


# Rules

all				:	$(LFT_P) $(NAME)

$(LFT_P)		:	force
					@echo "Vérification de la librairie Libft"
					@make -C $(LFT_D)


$(NAME)			:	$(OBJS)
					@echo "\nAssemblage et création de l'exécutable $(NAME)"
					@$(COMP) $(FLAG) $(OBJS) $(LFT_P) $(TRMCP_I) -o $(NAME)
					@echo "Terminé"

$(OBJS_D)%.o	:	$(SRCS_D)%.c $(addprefix $(LFT_I), $(LFT_H)) $(INCL)
					@echo -e "\033[2K\c"
					@echo "\rCréation de l'objet $@\c"
					@mkdir -p $(addprefix $(OBJS_D), $(SRCS_SD))
					@$(COMP) $(FLAG) -I $(LFT_I) -I $(INCL_D) -o $@ -c $<

clean			:
					@make -C $(LFT_D) clean
					@echo "Nettoyage des objets $(OBJS_D)"
					@rm -rf $(OBJS_D)

fclean			:
					@make -C $(LFT_D) fclean
					@echo "Nettoyage des objets $(OBJS_D)"
					@rm -rf $(OBJS_D)
					@echo "Nettoyage de l'exécutable $(NAME)"
					@rm -f $(NAME)

test			:	@$(COMP) $(FLAGDEBUG) ${INC} ${LIB} ${FWS} -o ${NAME} ${SRCS}

debug			:	test
					lldb ./${NAME}

re				:	fclean all

force			:
					@true

.PHONY			:	all clean fclean test debug libs re force
