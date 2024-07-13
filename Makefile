NAME		:= cub3D

LIBFT_DIR	:= libft
LIBFT_INC	:= $(LIBFT_DIR)/include
LIBFT_NAME	:= libft.a
LIBFT		:= $(LIBFT_DIR)/$(LIBFT_NAME)

SRCDIR		:= src
OBJDIR		:= obj
INCDIR		:= include

SRCS		:= \
	$(SRCDIR)/main.c \
	$(SRCDIR)/parse/check_args.c \

OBJS		:= $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SRCS))
INCS		:= \
	$(INCDIR)/cub3d.h

CC			:= cc
INCLUDES	:= -I$(INCDIR) -I$(LIBFT_INC)
CFLAGS		:= -O3 -Wall -Werror -Wextra $(INCLUDES)
LDFLAGS		:= -L$(LIBFT_DIR) -lft

RM			:= rm
RMFLAGS		:= -rf

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) -o $@ $(OBJS) $(LDFLAGS)

$(LIBFT):
	make -C $(LIBFT_DIR) $(LIBFT_NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(INCS)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	$(RM) $(RMFLAGS) $(OBJDIR)
	make -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(RMFLAGS) $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all
