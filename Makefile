# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hwolff <hwolff@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/14 13:21:32 by hben-yah          #+#    #+#              #
#    Updated: 2018/10/30 14:48:33 by hwolff           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	21sh

COMP			=	clang
FLAG			=	-Wall -Wextra -Werror -g3
FLAGDEGUG		=	$(FLAG) -fsanitize=address

# Sources paths
FILES_C			=	shell.c \
builtins/echo.c \
builtins/exit.c \
builtins/main.c

FILES_O			=	$(FILES_C:.c=.o)
FILES_H			=	shell.h

# Directories
SRCS_SD			= 	builtins
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
LFT_H			=	libft.h lft_array.h lft_boolean.h lft_convert.h lft_integer.h \
					lft_list.h lft_math.h lft_memory.h lft_other.h lft_printf.h \
					lft_put.h lft_string.h lft_stringbuffer.h

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

.PHONY	: all clean fclean test debug libs re force