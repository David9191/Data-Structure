NAME = bintree.a
AR = ar
ARFLAGS = -rcs
CC = gcc
FLAGS = -Wall -Wextra -Werror
RM = rm -rf

SRCS =  bintree.c \
		bintree_test.c
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(SRCS)
	$(AR) $(ARFLAGS) $@ $^
	./a.out

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)
	$(RM) a.out

re : fclean all

.PHONY : all clean fclean re bonus
.SILENT : all name clean fclean
