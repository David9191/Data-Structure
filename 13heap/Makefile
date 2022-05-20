NAME = heap.a
AR = ar
ARFLAGS = -rcs
CC = gcc
FLAGS = -Wall -Wextra -Werror
RM = rm -rf

MAX_SRCS =  maxheap.c \
			maxheap_test.c
MIN_SRCS = 	minheap.c \
			minheap_test.c
MAX_OBJS = $(MAX_SRCS:.c=.o)
MIN_OBJS = $(MIN_SRCS:.c=.o)

all : $(NAME)

$(NAME): $(MAX_OBJS)
	$(CC) $(FLAGS) $(MAX_SRCS)
	$(AR) $(ARFLAGS) $@ $^
	./a.out
	make fclean

max : $(MAX_OBJS)
	$(CC) $(FLAGS) $(MAX_SRCS)
	$(AR) $(ARFLAGS) $(NAME) $^
	./a.out
	make fclean

min : $(MIN_OBJS)
	$(CC) $(FLAGS) $(MIN_SRCS)
	$(AR) $(ARFLAGS) $(NAME) $^
	./a.out
	make fclean

clean :
	$(RM) $(MAX_OBJS) $(MIN_OBJS)
	$(RM) a.out

fclean : clean
	$(RM) $(NAME)
	$(RM) a.out

maxre : fclean max
minre : fclean min

debugmax : $(MAX_SRCS)
	$(CC) $(FLAGS) $(MAX_SRCS) -g -o maxheap_test

debugmin : $(MIN_SRCS)
	$(CC) $(FLAGS) $(MIN_SRCS) -g -o minheap_test

.PHONY : all clean fclean re bonus
.SILENT : all name clean fclean
