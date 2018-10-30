# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hwolff <hwolff@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/14 13:21:32 by hben-yah          #+#    #+#              #
#    Updated: 2018/10/30 16:40:59 by hwolff           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	libft.a

COMP			=	clang
FLAG			=	-Wall -Wextra -Werror

# Files names
ARR_FILES_N		=	ft_sortinttab.c ft_sortstrtab.c ft_strtabdup.c \
					ft_strtablen.c ft_strtabncpy.c ft_strtabnew.c \
					ft_strtabrealloc.c ft_tabdel.c ft_print_words_tables.c \
					ft_split_whitespaces.c
ARRLST_FILES_N	=	arraylist.c
BOOL_FILES_N	=	ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
					ft_ishexa.c ft_islower.c ft_isprime.c ft_isprint.c \
					ft_isspace.c ft_isspace_wnt.c ft_isupper.c
CONV_FILES_N	=	ft_atoi.c ft_atoi_base.c ft_convert_base.c ft_itoa.c \
					ft_itoa_base.c
OTH_FILES_N		=	ft_indexof.c ft_linear_interpolate.c get_next_line.c
INT_FILES_N		=	ft_intswap.c ft_nbrlen.c
LST_FILES_N		=	ft_lstadd.c ft_lstcnt.c ft_lstdel.c ft_lstdelone.c \
					ft_lstiter.c ft_lstmap.c ft_lstnew.c ft_lstrev.c
MATH_FILES_N	=	ft_abs.c ft_max.c ft_min.c ft_pow.c ft_sqrt.c
MEM_FILES_N		=	ft_bzero.c ft_memalloc.c ft_memccpy.c ft_memchr.c \
					ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c \
					ft_memset.c
PRINTF_FILES_N	=	ft_printf.c ft_dprintf.c ft_asprintf.c \
					ft_vprintf.c ft_vdprintf.c ft_vasprintf.c
PF_CONV_FILES_N	=	char.c color.c date.c integer.c \
					integer_plus.c integer_signed.c integer_unsigned.c \
					memory.c pointer.c string.c non_printable.c
PF_CORE_FILES_N	=	converter.c exception.c formatter_handler.c helper.c \
					parser.c wchar_handler.c printer.c
PUT_FILES_N		=	ft_putchar.c ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c \
					ft_putnbr.c ft_putnbr_base.c ft_putnbr_fd.c ft_putnbrtab.c \
					ft_putstr.c ft_putstr_fd.c ft_putstrtab.c
STR_FILES_N		=	ft_charswap.c ft_hasnodupl.c ft_strcat.c ft_strchr.c \
					ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c\
					ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c \
					ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmap.c \
					ft_strmapi.c ft_strncat.c ft_strncmp.c ft_strncpy.c \
					ft_strnequ.c ft_strnew.c ft_strnstr.c ft_strrchr.c \
					ft_strrev.c ft_strsplit.c ft_strstr.c ft_strsub.c \
					ft_strtolower.c ft_strtoupper.c ft_strtrim.c \
					ft_tolower.c ft_toupper.c ft_wrdcnt.c ft_printabilize.c \
					ft_split_chars.c
STRBUF_FILES_N	=	stringbuffer.c

# Sources paths
FILES_C			=	$(addprefix array/, $(ARR_FILES_N)) \
					$(addprefix arraylist/, $(ARRLST_FILES_N)) \
					$(addprefix boolean/, $(BOOL_FILES_N)) \
					$(addprefix convert/, $(CONV_FILES_N)) \
					$(addprefix other/, $(OTH_FILES_N)) \
					$(addprefix integer/, $(INT_FILES_N)) \
					$(addprefix list/, $(LST_FILES_N)) \
					$(addprefix math/, $(MATH_FILES_N)) \
					$(addprefix memory/, $(MEM_FILES_N)) \
					$(addprefix printf/, $(PRINTF_FILES_N)) \
					$(addprefix printf/converters/, $(PF_CONV_FILES_N))\
					$(addprefix printf/core/, $(PF_CORE_FILES_N)) \
					$(addprefix put/, $(PUT_FILES_N)) \
					$(addprefix string/, $(STR_FILES_N)) \
					$(addprefix stringbuffer/, $(STRBUF_FILES_N))
FILES_O			=	$(FILES_C:.c=.o)
FILES_H			=	libft.h lft_array.h lft_boolean.h lft_convert.h lft_integer.h \
					lft_list.h lft_math.h lft_memory.h lft_other.h lft_printf.h \
					lft_put.h lft_string.h lft_stringbuffer.h

# Directories
SRCS_SD			= 	array arraylist boolean convert other list math memory printf \
					printf/converters printf/core integer put string stringbuffer
SRCS_D			=	./srcs/
OBJS_D			=   ./objs/
INCL_D 			=	./includes/

# Paths
SRCS			= 	$(addprefix $(SRCS_D), $(FILES_C))
OBJS			=	$(addprefix $(OBJS_D), $(FILES_O))
INCL			=	$(addprefix $(INCL_D), $(FILES_H))

all				:	$(NAME)

$(NAME)			:	$(OBJS)
					@echo "\nAssemblage et création de la librairie $(NAME)"
					@ar rc $(NAME) $(OBJS)
					@ranlib $(NAME)
					@echo "Libft terminée"

$(OBJS_D)%.o	:	$(SRCS_D)%.c $(INCL)
					@echo -e "\033[2K\c"
					@echo "\rCréation de l'objet $@\c"
					@mkdir -p $(addprefix $(OBJS_D), $(SRCS_SD))
					@$(COMP) $(FLAG) -I $(INCL_D) -o $@ -c $<

clean			:
					@echo "Nettoyage des objets ./libft/objs/"
					@rm -rf $(OBJS_D)

fclean			:	clean
					@echo "Nettoyage de la librairie $(NAME)"
					@rm -f $(NAME)

re				:	fclean all

.PHONY			:	all clean fclean re