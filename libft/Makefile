# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: felcaue- <felcaue-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/12 18:09:28 by felcaue-          #+#    #+#              #
#    Updated: 2022/07/13 15:41:07 by felcaue-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

#compilation
CC 			= gcc
CFLAGS 		= -Wall -Wextra -Werror
CFI 		= -I $(INCLUDE).

RM			=	rm -f
AR			=	ar -rcs

LIBFT_PATH		= ./libft_d/
GNL_PATH		= ./GNL_d/
PRINT_PATH 		= ./ft_printf_d/
OBJ_PATH		= ./objs_libft/
INCLUDE 		= ./include/

# Colors
GR	= \033[32;1m
RE	= \033[31;1m
YE	= \033[33;1m
CY	= \033[36;1m
RC	= \033[0m

SOURCES		=	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c\
				ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c\
				ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c\
				ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c\
				ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c\
				ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c\
				ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c\
				ft_atoi_base.c ft_uitoa_base.c ft_strnjoin.c ft_strndup.c \
				ft_strisalnum.c ft_appendchar.c \
				get_next_line.c \
				conversion.c convert_c.c convert_d_i.c convert_p.c convert_pct.c \
				convert_s.c convert_ux.c ft_printf.c initialize.c parse.c placeholder.c 
				

VPATH		:=	$(PRINT_PATH)\
			$(GNL_PATH)\
			$(LIBFT_PATH)\


OBJECTS		=	$(addprefix $(OBJ_PATH), $(notdir $(SOURCES:.c=.o)))

all:	$(NAME)

$(OBJ_PATH)%.o: %.c
				@printf "\n$(CY)Generating object...$(RC)\n"
				mkdir -p $(OBJ_PATH)
				$(CC) $(CF) $(CFI) -c $< -o $@
				@printf "$(YE)Object ready!$(RC)"

$(NAME):		$(OBJECTS) $(INCLUDE)
				@printf "\n$(CY)Generating libft library...$(RC)\n"
				$(AR) $(NAME) $(OBJECTS) 
				@printf "$(GR)Done!$(RC)\n\n"

.c.o:	$(CC) (CFLAGS) $(CFI) -c $< -o $(<:.c=.o)

clean:
			$(RM) $(OBJECTS)
			@printf "$(RE)libft objects removed!$(RC)\n\n"

fclean:		clean
			$(RM) $(NAME)
			@printf "$(RE)Executables removed!$(RC)\n\n"

re:	fclean all

.PHONY:	all clean fclean re
