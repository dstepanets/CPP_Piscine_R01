# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dstepane <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/03 19:05:25 by dstepane          #+#    #+#              #
#    Updated: 2019/07/03 19:05:27 by dstepane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME		= ft_gkrellm
CC			= clang++
FLAGS		= -g -Wall -Wextra -Werror -std=c++98 -Wconversion

SRC_DIR		= ./src/
INC_DIR		= ./inc/
OBJ_DIR		= ./obj/

SRC			=	main.cpp \
				monitor.cpp \
				NcursesDisplay.cpp \
				NameModule.cpp \
				TimeModule.cpp \
				OsModule.cpp \
				HddModule.cpp \
				CpuModule.cpp \
				RAMModule.cpp\
				NetModule.cpp

HPP			=	monitor.hpp \
				includes.hpp \
				IMonitorModule.hpp \
				IMonitorDisplay.hpp \
				IMonitorDisplay.hpp \
				NcursesDisplay.hpp \
				NameModule.hpp \
				TimeModule.hpp \
				OsModule.hpp \
				HddModule.hpp \
				CpuModule.hpp \
				RAMModule.hpp \
				NetModule.hpp

HEADS		= $(addprefix $(INC_DIR), $(HPP))
OBJ 		= $(addprefix $(OBJ_DIR), $(SRC:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(FLAGS) -lncurses $(OBJ) -o $(NAME)
	@echo "\033[32m\033[100m\033[1m<ft_gkrellm> executable compiled.\033[0m"

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: %.cpp $(HEADS)
	@$(CC) $(FLAGS) -c $< -o $@ -I $(INC_DIR)
	@echo "	\033[96m$@\033[0m"

clean:
	@rm -f $(OBJ)
	@rm -rf $(OBJ_DIR)
	@echo "\033[31m<ft_gkrellm> object files removed.\033[0m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[31m<ft_gkrellm> executable removed.\033[0m"

re: fclean all

vpath %.cpp $(SRC_DIR)

.PHONY: all clean fclean re

