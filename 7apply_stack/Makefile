NAME = check_bracket.a
AR = ar
ARFLAGS = -rcs
CC = gcc
FLAGS = -Wall -Wextra -Werror
RM = rm -rf

SRCS =  check_bracket.c \
		../6stack/linkedstack.c
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(SRCS)
	$(AR) $(ARFLAGS) $@ $^
	./a.out "(" ")" "{(A * B) + C}" "1+2-3" "{C[A+B(5*5)]}" "{[)}" "1+2"

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)
	$(RM) a.out

re : fclean all

.PHONY : all clean fclean re bonus
.SILENT : all name clean fclean
