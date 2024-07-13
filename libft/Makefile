NAME		:= libft.a
NAME_BONUS	:= $(patsubst %.a,%_bonus.a,$(NAME))

SRCDIR		:= src
OBJDIR		:= obj
INCDIR		:= include

SRCS		:= \
	$(SRCDIR)/ft_atoi.c \
	$(SRCDIR)/ft_bzero.c \
	$(SRCDIR)/ft_calloc.c \
	$(SRCDIR)/ft_isalnum.c \
	$(SRCDIR)/ft_isalpha.c \
	$(SRCDIR)/ft_isascii.c \
	$(SRCDIR)/ft_isdigit.c \
	$(SRCDIR)/ft_isprint.c \
	$(SRCDIR)/ft_itoa.c \
	$(SRCDIR)/ft_memchr.c \
	$(SRCDIR)/ft_memcmp.c \
	$(SRCDIR)/ft_memcpy.c \
	$(SRCDIR)/ft_memmove.c \
	$(SRCDIR)/ft_memset.c \
	$(SRCDIR)/ft_putchar_fd.c \
	$(SRCDIR)/ft_putendl_fd.c \
	$(SRCDIR)/ft_putnbr_fd.c \
	$(SRCDIR)/ft_putstr_fd.c \
	$(SRCDIR)/ft_split.c \
	$(SRCDIR)/ft_strchr.c \
	$(SRCDIR)/ft_strdup.c \
	$(SRCDIR)/ft_striteri.c \
	$(SRCDIR)/ft_strjoin.c \
	$(SRCDIR)/ft_strlcat.c \
	$(SRCDIR)/ft_strlcpy.c \
	$(SRCDIR)/ft_strlen.c \
	$(SRCDIR)/ft_strmapi.c \
	$(SRCDIR)/ft_strncmp.c \
	$(SRCDIR)/ft_strnstr.c \
	$(SRCDIR)/ft_strrchr.c \
	$(SRCDIR)/ft_strtrim.c \
	$(SRCDIR)/ft_substr.c \
	$(SRCDIR)/ft_tolower.c \
	$(SRCDIR)/ft_toupper.c \

SRCS_BONUS	:= \
	$(SRCDIR)/ft_lstadd_back.c \
	$(SRCDIR)/ft_lstadd_front.c \
	$(SRCDIR)/ft_lstclear.c \
	$(SRCDIR)/ft_lstdelone.c \
	$(SRCDIR)/ft_lstiter.c \
	$(SRCDIR)/ft_lstlast.c \
	$(SRCDIR)/ft_lstmap.c \
	$(SRCDIR)/ft_lstnew.c \
	$(SRCDIR)/ft_lstsize.c \

OBJS		:= $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SRCS))
OBJS_BONUS	:= $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SRCS_BONUS))
INCS		:= $(INCDIR)/libft.h

CC			:= cc
INCLUDES	:= -I$(INCDIR)
CFLAGS		:= -O3 -Wall -Werror -Wextra $(INCLUDES)
LDFLAGS		:=

AR			:= ar
ARFLAGS		:= -rcs

RM			:= rm
RMFLAGS		:= -rf

.PHONY: all bonus clean fclean re

all: $(NAME)

bonus: $(NAME_BONUS)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

$(NAME_BONUS): $(OBJS_BONUS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS_BONUS)
	$(AR) $(ARFLAGS) $(NAME_BONUS) $(OBJS_BONUS)

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(INCS)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	$(RM) $(RMFLAGS) $(OBJDIR)

fclean: clean
	$(RM) $(RMFLAGS) $(NAME) $(NAME_BONUS)

re: fclean all
