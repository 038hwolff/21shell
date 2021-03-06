# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/18 08:34:44 by hwolff            #+#    #+#              #
#    Updated: 2019/01/24 00:28:38 by hben-yah         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	21sh

COMP			=	clang
FLAG			=	-Wall -Wextra -Werror -g3 -pedantic

# Files names
SHELL_N			=	shell.c free.c data.c init.c putchar.c \
					signals.c term.c exception.c exit.c reset.c \
					cancel.c completion.c completion2.c completion3.c
EDITLINE_N		=	read_line.c mouve.c term.c \
					history.c setup.c ft_enter.c print_line.c \
					prompt.c select_mode.c copy_paste.c cut_high.c \
					control_keys.c supp_char.c complete_word.c multiline.c
LEXER_N			=	lexer.c checker.c token.c helper.c 
PARSER_N		=	parser.c command_completion.c completion_checkers.c \
					helper.c heredoc.c heredoc_getter.c operators.c \
					pop_char.c special_prompt.c tokendel.c
ASTBUILDER_N	=	build_ast.c print_ast.c helper.c
EXECUTOR_N		=	executor.c fd_agregator.c \
					pipes.c redirections.c exec_cmd_line.c semicolon.c \
					operator.c tools.c var_get.c \
					exp_goto_next_quote.c exp_tilde.c exp_vars_assign.c \
					exp_vars_get.c exp_vars_substitute.c exp_vars.c \
					expansion.c var_set.c heredoc.c exp_quotes.c \
					assignement.c exec_subcmd.c exp_substit_cmd.c
BUILTINS_N		=	builtins_cd.c builtins_echo.c builtins_env.c \
					builtins_exit.c builtins_main.c \
					builtins_setenv.c \
					builtins_unsetenv.c builtins_export.c builtins_unset.c \
					builtins_set.c

# Sources paths
FILES_C			=	$(addprefix 0_shell/, $(SHELL_N)) \
					$(addprefix 1_lineeditor/, $(EDITLINE_N)) \
					$(addprefix 2_lexer/, $(LEXER_N)) \
					$(addprefix 3_parser/, $(PARSER_N)) \
					$(addprefix 4_astbuilder/, $(ASTBUILDER_N)) \
					$(addprefix 5_executor/, $(EXECUTOR_N)) \
					$(addprefix 6_builtins/, $(BUILTINS_N)) \

FILES_O			=	$(FILES_C:.c=.o)
FILES_H			=	a_shell.h b_lineeditor.h c_lexer.h d_parser.h define.h e_astbuilder.h f_executor.h g_builtins.h shell.h struct.h

# Directories
SRCS_SD			= 	0_shell 1_lineeditor 2_lexer 3_parser 4_astbuilder 5_executor 6_builtins
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

all				:	$(NAME)

$(NAME)			:	$(LFT_P) $(OBJS)
					@echo "\nAssemblage et création de l'exécutable $(NAME)"
					@$(COMP) $(FLAG) $(OBJS) $(LFT_P) $(TRMCP_I) -o $(NAME)
					@echo "Terminé"

$(LFT_P)		:	force
					@echo "Vérification de la librairie Libft"
					@make -C $(LFT_D)

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

re				:	fclean all

force			:
					@true

.PHONY			:	all clean fclean test debug libs re force
