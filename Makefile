# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/14 13:21:32 by hben-yah          #+#    #+#              #
#    Updated: 2018/11/30 14:22:33 by hben-yah         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	21sh

COMP			=	clang
FLAG			=	-Wall -Wextra -Werror -g3
FLAGDEGUG		=	$(FLAG) -fsanitize=address

# Files names
SHELL_N			=	shell.c free.c data.c init.c putchar.c \
					signals.c term.c var.c exception.c exit.c
EDITLINE_N		=	command_reader.c read_line.c mouve.c term.c \
					history.c setup.c ft_enter.c signal.c print_line.c \
					prompt.c select_mode.c copy_paste.c cut_high.c \
					control_keys.c
LEXER_N			=	lexer.c checker.c token.c helper.c 
PARSER_N		=	parser.c syntax_checker.c helper.c
ASTBUILDER_N		=	astbuilder.c
EXECUTOR_N		=	
BUILTINS_N		=	

# Sources paths
FILES_C			=	$(addprefix 0_shell/, $(SHELL_N)) \
					$(addprefix 1_lineeditor/, $(EDITLINE_N)) \
					$(addprefix 2_lexer/, $(LEXER_N)) \
					$(addprefix 3_parser/, $(PARSER_N)) \
					$(addprefix 4_astbuilder/, $(ASTBUILDER_N)) \
					$(addprefix 5_executor/, $(EXECUTOR_N)) \
					$(addprefix 6_builtins/, $(BUILTINS_N)) \

FILES_O			=	$(FILES_C:.c=.o)
FILES_H			=	shell.h

# Directories
SRCS_SD			= 	0_shell 1_lineeditor 2_lexer 3_parser 4_astbuilder 5_executor 6_builtins
					# builtins expansions inhibitors core editline shell file_desc signal
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
