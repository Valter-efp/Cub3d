# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vafernan <vafernan@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/03 15:45:46 by vafernan          #+#    #+#              #
#    Updated: 2025/02/03 15:45:46 by vafernan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#* NAME - Name of the file to be created *#
#* SRCS - List of source C files to be CCiled *#
#* OBJS - List of object files that will be generated during CCile *#
#* .PONY - tells the make, that these are not files to be addressed, *#
#* not to be confused with file beacause they are commands *#
#* %.o: %.c - its a rule to assing .o files as object files *#
#* and .c as C source files *#

NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

# Directories
SRC_DIR = .
PRINTF_DIR = ft_printf
GNL_DIR = GNL

# Source and object files
SRCS = $(wildcard $(SRC_DIR)/*.c) \
       $(wildcard $(PRINTF_DIR)/*.c) \
       $(wildcard $(GNL_DIR)/*.c)
EXCEPTIONS = $(GNL_DIR)/get_next_line_bonus.c \
             $(GNL_DIR)/get_next_line_utils_bonus.c
SRCS += $(EXCEPTIONS)
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

# Rule to compile .c files to .o files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re