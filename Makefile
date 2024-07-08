# Colors
RED=\033[0;31m
GREEN=\033[0;32m
BLUE=\033[0;34m
END=\033[0m

# Paths
SRCS_DIR:=srcs
PRINTF_PATH:=lib/ft_printf

# Source files - Use wildcard to automatically include all .c files
S_SRCS := $(wildcard $(SRCS_DIR)/server*.c)
C_SRCS := $(wildcard $(SRCS_DIR)/client*.c)

# Object files - Automatically generated from source files
S_OBJS := $(S_SRCS:.c=.o)
C_OBJS := $(C_SRCS:.c=.o)

# Compilation settings
CC:= cc
DEBUG_FLAG:= -g
# Include path for ft_printf
PRINTF_INC:= -I$(PRINTF_PATH)
# Library path and static library for linking
PRINTF_LIB:= -L$(PRINTF_PATH) -lftprintf

# Adjust CFLAGS to include only the include path
CFLAGS:= -Wall -Werror -Wextra $(PRINTF_INC)

RM :=	rm -rvf

# Target names
SERVERNAME:= server
CLIENTNAME:= client

.PHONY: all clean fclean re

all: printf $(SERVERNAME) $(CLIENTNAME) msg


$(SERVERNAME): $(S_OBJS)
	$(CC) $(S_OBJS) -o $(SERVERNAME) $(CFLAGS) $(PRINTF_PATH)/libftprintf.a


$(CLIENTNAME): $(C_OBJS)
	$(CC) $(C_OBJS) -o $(CLIENTNAME) $(CFLAGS) $(PRINTF_PATH)/libftprintf.a


%.o: %.c
	$(CC) -c $< -o $@ $(CFLAGS)
	@echo "Creating objects"

printf:
	make -C $(PRINTF_PATH) all
	@echo  "$(BLUE)------------------------------------------------------------------------$(END)"
	@echo  "$(GREEN)Printf and libft compiled$(END)"
	@echo  "$(BLUE)------------------------------------------------------------------------$(END)"

clean:
	@echo "$(BLUE)Removing objects...$(END)"
	$(RM) $(S_OBJS) $(C_OBJS)

fclean: clean
	make -C $(PRINTF_PATH) fclean
	$(RM) $(SERVERNAME) $(CLIENTNAME)
	@echo  "$(BLUE)------------------------------------------------------------------------$(END)"
	@echo  "$(BLUE)All files removed$(END)"
	@echo  "$(BLUE)------------------------------------------------------------------------$(END)"

re: fclean all

msg:
	@echo  "$(BLUE)------------------------------------------------------------------------$(END)"
	@echo  "$(GREEN)All files compiled$(END)"
	@echo  "$(BLUE)------------------------------------------------------------------------$(END)"

run:
	./$(SERVERNAME)

debug: CFLAGS += -DDEBUG
debug: re
	@echo "$(GREEN)Debug mode: ON$(END)"