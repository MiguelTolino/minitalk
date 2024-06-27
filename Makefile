# Colors
RED=\033[0;31m
GREEN=\033[0;32m
BLUE=\033[0;34m
END=\033[0m

# Paths
SRCS_DIR:=srcs
BINPATH:=bin
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
CFLAGS:= -Wall -Werror -Wextra -I.
PRINTF_LIB:= -L$(PRINTF_PATH) $(PRINTF_PATH)/libftprintf.a
RM :=	rm -rvf

# Target names
SERVERNAME:= server
CLIENTNAME:= client

.PHONY: all clean fclean re debug printf bin run msg

all: printf bin $(SERVERNAME) $(CLIENTNAME) msg

$(SERVERNAME): $(S_OBJS)
    $(CC) $(CFLAGS) $(S_OBJS) -o $(BINPATH)/$(SERVERNAME) $(PRINTF_LIB)

$(CLIENTNAME): $(C_OBJS)
    $(CC) $(CFLAGS) $(C_OBJS) -o $(BINPATH)/$(CLIENTNAME) $(PRINTF_LIB)

%.o: %.c
    $(CC) -c $< -o $@
    @echo "Creating objects"

bin:
    @if [ ! -d "$(BINPATH)" ]; then \
        mkdir -p "$(BINPATH)"; \
        echo "Created '$(BINPATH)' directory"; \
    else \
        echo "'$(BINPATH)' directory exists.\n"; \
    fi

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
    $(RM) $(BINPATH)
    @echo  "$(BLUE)------------------------------------------------------------------------$(END)"
    @echo  "$(BLUE)All files removed$(END)"
    @echo  "$(BLUE)------------------------------------------------------------------------$(END)"

re: fclean all

msg:
    @echo  "$(BLUE)------------------------------------------------------------------------$(END)"
    @echo  "$(GREEN)All files compiled$(END)"
    @echo  "$(BLUE)------------------------------------------------------------------------$(END)"

run:
    ./$(BINPATH)/$(SERVERNAME)

debug: CFLAGS += -DDEBUG
debug: re
    @echo "$(GREEN)Debug mode: ON$(END)"