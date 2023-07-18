# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/24 16:04:19 by user42            #+#    #+#              #
#    Updated: 2023/07/18 18:56:32 by mmateo-t         ###   ########.fr        #
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
CC:= cc
CFLAGS:= -Wall -Werror -Wextra -std=c99
RM :=	rm -rvf
LIBFT_PATH:= libft/
LIBFT_LIB:= -L$(LIBFT_PATH) $(LIBFT_PATH)libft.a
DEBUG_FLAG:= -g

all: libft $(SERVERNAME) $(CLIENTNAME) msg

$(SERVERNAME): $(S_OBJS)
	$(CC) $(CFLAGS) $(S_OBJS) -o $(SERVERNAME) $(LIBFT_LIB)

$(CLIENTNAME): $(C_OBJS)
	$(CC) $(CFLAGS) $(C_OBJS) -o $(CLIENTNAME) $(LIBFT_LIB)

$(%.o): $(%.c)
		$(CC) -c $^ -o $@
		@echo "Creating objects"

libft:
		make -C $(LIBFT_PATH) all
		@echo  "$(BLUE)------------------------------------------------------------------------$(END)"
		@echo  "$(GREEN)Libft compiled$(END)"
		@echo  "$(BLUE)------------------------------------------------------------------------$(END)"

clean:
		@echo "$(BLUE)Removing objects$(END)"
		$(RM) $(S_OBJS) $(C_OBJS)
fclean:
		make clean
		make -C $(LIBFT_PATH) fclean
		$(RM) $(SERVERNAME) $(CLIENTNAME)
msg:
	@echo  "$(BLUE)------------------------------------------------------------------------$(END)"
	@echo  "$(GREEN)All files compiled$(END)"
	@echo  "$(BLUE)------------------------------------------------------------------------$(END)"

re:
	make fclean all
	@echo "$(BLUE)All files has been deleted and recompiled$(END)"

.PHONY: clean fclean all re debug libft
