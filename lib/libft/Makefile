# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cjoanne <cjoanne@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/21 12:30:03 by cjoanne           #+#    #+#              #
#    Updated: 2021/05/28 06:02:01 by cjoanne          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS_LIST =	ft_isdigit.c\
			ft_memccpy.c\
			ft_memcmp.c\
			ft_memcpy.c\
			ft_memset.c\
			ft_putchar_fd.c\
			ft_memchr.c\
			ft_bzero.c\
			ft_atoi.c\
			ft_isalpha.c\
			ft_memmove.c\
			ft_putstr_fd.c\
			ft_strmapi.c\
			ft_strlen.c\
			ft_strncmp.c\
			ft_tolower.c\
			ft_toupper.c\
			ft_isalnum.c\
			ft_putendl_fd.c\
			ft_isprint.c\
			ft_itoa.c\
			ft_putnbr_fd.c\
			ft_strchr.c\
			ft_strdup.c\
			ft_strlcat.c\
			ft_strlcpy.c\
			ft_strrchr.c\
			ft_strnstr.c\
			ft_isascii.c\
			ft_strjoin.c\
			ft_calloc.c\
			ft_substr.c\
			ft_strtrim.c\
			ft_split.c\
			ft_strcmp.c\
			ft_isspace.c\
			ft_lstnew.c\
			ft_lstdelone.c\
			ft_lstadd_front.c\
			ft_lstsize.c\
			ft_lstlast.c\
			ft_lstadd_back.c\
			ft_lstclear.c\
			ft_lstmap.c\
			ft_lstiter.c\
			ft_putstrnewline.c\
			ft_split_len.c
SRCS_DIR = srcs/
SRCS = $(addprefix $(SRCS_DIR), $(SRCS_LIST))

OBJS_DIR = objects/
OBJS_LIST = $(patsubst %.c, %.o, $(SRCS_LIST))
OBJS = $(addprefix $(OBJS_DIR), $(OBJS_LIST))

INCLUDES = -I./includes/

FLAGS = -Wall -Wextra -Werror

# COLORS
GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m
BLUE= \033[0;34m

all : $(NAME)

$(NAME) : $(OBJS_DIR) $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@echo "\n$(NAME): $(BLUE)object files were created$(RESET)"
	@echo "$(NAME): $(GREEN)$(NAME) was created$(RESET)"

$(OBJS_DIR) :
	@mkdir -p $(OBJS_DIR)

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c
	@gcc -g $(FLAGS) $(INCLUDES) -c $< -o $@
	@echo "$(BLUE)`ruby -e "puts (0..1).to_a.shuffle.join('')"`$(RESET)\c"

clean :
	@rm -rf $(OBJS_DIR)
	@echo "$(NAME): $(RED)object files were deleted$(RESET)"

fclean : clean
	@rm -rf $(NAME)
	@echo "$(NAME): $(RED)$(NAME)was deleted$(RESET)"

re : fclean all

.PHONY : all clean fclean re bonus