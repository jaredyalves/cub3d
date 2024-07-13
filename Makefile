NAME		:= cub3D

LIBFT_DIR	:= libft
LIBFT_INC	:= $(LIBFT_DIR)/include
LIBFT_NAME	:= libft.a
LIBFT		:= $(LIBFT_DIR)/$(LIBFT_NAME)

GNL_DIR		:= get_next_line
GNL_INC		:= $(GNL_DIR)/include
GNL_NAME	:= libgnl.a
GNL			:= $(GNL_DIR)/$(GNL_NAME)

SRCDIR		:= src
OBJDIR		:= obj
INCDIR		:= include

SRCS		:= \
	$(SRCDIR)/main.c \
	$(SRCDIR)/init/init_config.c \
	$(SRCDIR)/parse/check_args.c \
	$(SRCDIR)/parse/parse_file.c \
	$(SRCDIR)/parse/parse_line.c \

OBJS		:= $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SRCS))
INCS		:= \
	$(INCDIR)/cub3d.h

CC			:= cc
INCLUDES	:= -I$(INCDIR) -I$(LIBFT_INC) -I$(GNL_INC)
CFLAGS		:= -O3 -Wall -Werror -Wextra $(INCLUDES)
LDFLAGS		:= -L$(LIBFT_DIR) -lft -L$(GNL_DIR) -lgnl

RM			:= rm
RMFLAGS		:= -rf

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(GNL)
	$(CC) -o $@ $(OBJS) $(LDFLAGS)

$(LIBFT):
	make -C $(LIBFT_DIR) $(LIBFT_NAME)

$(GNL):
	make -C $(GNL_DIR) $(GNL_NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(INCS)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	$(RM) $(RMFLAGS) $(OBJDIR)
	make -C $(LIBFT_DIR) clean
	make -C $(GNL_DIR) clean

fclean: clean
	$(RM) $(RMFLAGS) $(NAME)
	make -C $(LIBFT_DIR) fclean
	make -C $(GNL_DIR) fclean

re: fclean all
