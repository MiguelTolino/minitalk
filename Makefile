# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/24 16:04:19 by user42            #+#    #+#              #
#    Updated: 2023/07/20 16:44:48 by mmateo-t         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#AUTHOR mmateo-t
#USAGE

#make          #compile all binary
#make clean		#remove all binaries
#make fclean		#remove all binaries and executable

# Colors
GREEN=\033[0;32m
RED=\033[0;31m
BLUE=\033[0;34m
END=\033[0m

SRCS_DIR:=srcs/
S_SRCS := $(SRCS_DIR)server.c
S_OBJS := $(S_SRCS:%.c=%.o)
C_SRCS := $(SRCS_DIR)client.c
C_OBJS := $(C_SRCS:%.c=%.o)
SERVERNAME:= server
CLIENTNAME:= client
BINPATH:= bin
CC:= cc
DEBUG_FLAG:= -g
CFLAGS:= -Wall -Werror -Wextra -std=c99 $(DEBUG_FLAG)
RM :=	rm -rvf
PRINTF_PATH:= lib/ft_printf
PRINTF_LIB:= -L$(PRINTF_PATH) $(PRINTF_PATH)/libftprintf.a

all: printf bin $(SERVERNAME) $(CLIENTNAME) msg

$(SERVERNAME): $(S_OBJS)
	$(CC) $(CFLAGS) $(S_OBJS) -o $(BINPATH)/$(SERVERNAME) $(PRINTF_LIB)

$(CLIENTNAME): $(C_OBJS)
	$(CC) $(CFLAGS) $(C_OBJS) -o $(BINPATH)/$(CLIENTNAME) $(PRINTF_LIB)

$(%.o): $(%.c)
		$(CC) -c $^ -o $@
		@echo "Creating objects"

bin:
	@if [ ! -d "bin" ]; then \
		mkdir -p "bin"; \
		echo "Created 'bin' directory"; \
	else \
		echo "'bin' directory exists.\n"; \
	fi

printf:
		make -C $(PRINTF_PATH) all
		@echo  "$(BLUE)------------------------------------------------------------------------$(END)"
		@echo  "$(GREEN)Printf and libft compiled$(END)"
		@echo  "$(BLUE)------------------------------------------------------------------------$(END)"

clean:
		@echo "$(BLUE)Removing objects...$(END)"
		$(RM) $(S_OBJS) $(C_OBJS)
fclean:
		make clean
		make -C $(PRINTF_PATH) fclean
		$(RM) $(BINPATH)
		@echo  "$(BLUE)------------------------------------------------------------------------$(END)"
		@echo  "$(BLUE)All files removed$(END)"
		@echo  "$(BLUE)------------------------------------------------------------------------$(END)"
msg:
	@echo  "$(BLUE)------------------------------------------------------------------------$(END)"
	@echo  "$(GREEN)All files compiled$(END)"
	@echo  "$(BLUE)------------------------------------------------------------------------$(END)"

re:
	make fclean all
	@echo "$(BLUE)All files has been deleted and recompiled$(END)"

run:
	./$(BINPATH)/$(SERVERNAME)

.PHONY: clean fclean all re debug printf bin run
