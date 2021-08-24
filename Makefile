# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nephilister <nephilister@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/21 12:30:03 by cjoanne           #+#    #+#              #
#    Updated: 2021/08/24 08:12:21 by nephilister      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRCS_LIST	=	pipex.c\
				errors.c\
				parsing.c\
				piping.c
SRCS_DIR	=	src/
SRCS		=	$(addprefix $(SRCS_DIR), $(SRCS_LIST))

OBJS_LIST	=	$(patsubst %.c, %.o, $(SRCS_LIST))
OBJS_DIR	=	objects/
OBJS		=	$(addprefix $(OBJS_DIR), $(OBJS_LIST))


BONUS_LIST	=	errors.c\
				parsing.c\
				pipex_bonus.c\
				piping_bonus.c
BONUS_SRC	=	$(addprefix $(SRCS_DIR), $(BONUS_LIST))

BONUS_OBJ_LIST	= $(patsubst %.c, %.o, $(BONUS_LIST))
BONUS_OBJ		= $(addprefix $(OBJS_DIR), $(BONUS_OBJ_LIST))

CC 			=	gcc
CFLAGS		=	-Wall -Wextra -Werror

INCLUDES	=	-I$(LIBFT_HEADER) -I$(HEADERS_DIR)

LIBFT_DIR		=	./lib/libft/
LIBFT_HEADER 	=	$(LIBFT_DIR)includes/
LIBFT			=	$(LIBFT_DIR)libft.a

HEADERS_DIR		=	./inc/
HEADERS_LIST	=	pipex.h
HEADERS 		=	$(addprefix $(HEADERS_DIR), $(HEADERS_LIST))

LIBRARIES = -lft -L$(LIBFT_DIR)

RM	=	rm -rf

# COLORS
GREEN = \033[0;32m
BLUE= \033[0;34m
RED = \033[0;31m
RESET = \033[0m
LIBA = libft.a

all : $(NAME)

$(NAME) : $(LIBFT) $(OBJS_DIR) $(OBJS)
	@$(CC) $(LIBFT) $(LIBRARIES) $(INCLUDES) $(OBJS) -o $(NAME)
	@echo "$(NAME): $(BLUE)$(NAME) object files were created$(RESET)"
	@echo "$(NAME): $(GREEN)$(NAME) was created$(RESET)"

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c
	@$(CC) $(СFLAGS) $(INCLUDES) -c $< -o $@
	
$(OBJS_DIR) :
	@mkdir -p $(OBJS_DIR)
	@echo "$(NAME): $(BLUE)creating $(NAME)$(RESET)"

bonus : $(LIBFT) $(OBJS_DIR) $(BONUS_OBJ)
	@$(CC) $(LIBFT) $(LIBRARIES) $(INCLUDES) $(BONUS_OBJ) -o $(NAME)_bonus
	@echo "$(NAME): $(BLUE)$(NAME)_bonus object files were created$(RESET)"
	@echo "$(NAME): $(GREEN)$(NAME)_bonus was created$(RESET)"

$(LIBFT) :
	@echo "$(NAME): $(BLUE)creating $(LIBA)$(RESET)"
	@$(MAKE) -C $(LIBFT_DIR)

clean :
	@$(RM) $(OBJS_DIR)
	@$(MAKE) clean -C $(LIBFT_DIR)
	@echo "$(NAME): $(RED)object files were deleted$(RESET)"

fclean : clean
	@$(RM) $(NAME)
	@echo "$(NAME): $(RED)$(NAME) was deleted$(RESET)"
	@$(RM) $(LIBFT)
	@echo "$(NAME): $(RED)$(LIBA) was deleted$(RESET)"
	@$(RM) $(NAME)_bonus

re : fclean all

.PHONY : all clean fclean re