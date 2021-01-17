.PHONY: clean fclean all re bonus
NAME = libft.a
OBJECT = libft.o
HEADER = libft.h
OBJECTS_P1 = ft_atoi.o ft_bzero.o ft_calloc.o ft_isalnum.o ft_isalpha.o \
			 ft_isascii.o ft_isdigit.o ft_isprint.o ft_itoa.o ft_memccpy.o \
			 ft_memchr.o ft_memcmp.o ft_memcpy.o ft_memmove.o ft_memset.o \
			 ft_putchar_fd.o ft_putendl_fd.o ft_putnbr_fd.o ft_putstr_fd.o \
			 ft_split.o ft_strchr.o ft_strdup.o ft_strjoin.o ft_strlcat.o \
			 ft_strlcpy.o ft_strlen.o ft_strmapi.o ft_strnstr.o\
			 ft_strrchr.o ft_strtrim.o ft_substr.o ft_tolower.o ft_toupper.o \
			 ft_strncmp.o


OBJECTS_BONUS = ft_lstnew.o ft_lstadd_front.o ft_lstsize.o ft_lstlast.o \
				ft_lstadd_back.o ft_lstdelone.o ft_lstclear.o ft_lstiter.o \
				ft_lstmap.o \
				ft_calc_spaces_bonus.o \
				ft_count_words_bonus.o ft_memdel_bonus.o ft_print_memory_bonus.o \
				ft_putchar_bonus.o ft_putendl_bonus.o ft_putnbr_bonus.o \
				ft_putstr_bonus.o  ft_strappend_bonus.o \
				ft_strcat_bonus.o ft_strclr_bonus.o ft_strcmp_bonus.o \
				ft_strcpy_bonus.o ft_strdel_bonus.o ft_strequ_bonus.o \
				ft_striter_bonus.o ft_striteri_bonus.o ft_strmap_bonus.o \
				ft_strncat_bonus.o  ft_strncpy_bonus.o \
				ft_strnequ_bonus.o  \
				ft_stralloc_bonus.o ft_calc_digits_bonus.o ft_islower_bonus.o \
			 	ft_isspace_bonus.o ft_isupper_bonus.o ft_strnew_bonus.o

FLAGS = -Wall -Wextra

all:$(NAME)

$(NAME): $(OBJECTS_P1) $(HEADER)
	ar -rc $(NAME) $(OBJECTS_P1)

bonus : $(NAME) $(OBJECTS_BONUS) $(HEADER)
	ar -rc $(NAME) $(OBJECTS_BONUS)

clean :
	rm -f $(OBJECTS_P1)
	rm -f $(OBJECTS_BONUS)

fclean : clean
	rm -f $(NAME)

re : fclean all

#MANDATORY

ft_strncmp.o: ft_strncmp.c
	gcc $(FLAGS) -c ft_strncmp.c -o ft_strncmp.o

ft_atoi.o : ft_atoi.c
	gcc $(FLAGS) -c ft_atoi.c -o ft_atoi.o

ft_bzero.o : ft_bzero.c
	gcc $(FLAGS) -c ft_bzero.c -o ft_bzero.o

ft_calloc.o : ft_calloc.c
	gcc $(FLAGS) -c ft_calloc.c -o ft_calloc.o

ft_isalnum.o : ft_isalnum.c
	gcc $(FLAGS) -c ft_isalnum.c -o ft_isalnum.o

ft_isalpha.o : ft_isalpha.c
	gcc $(FLAGS) -c ft_isalpha.c -o ft_isalpha.o

ft_isascii.o : ft_isascii.c
	gcc $(FLAGS) -c ft_isascii.c -o ft_isascii.o

ft_isdigit.o : ft_isdigit.c
	gcc $(FLAGS) -c ft_isdigit.c -o ft_isdigit.o

ft_isprint.o : ft_isprint.c
	gcc $(FLAGS) -c ft_isprint.c -o ft_isprint.o

ft_itoa.o : ft_itoa.c
	gcc $(FLAGS) -c ft_itoa.c -o ft_itoa.o

ft_lstadd_back.o : ft_lstadd_back.c
	gcc $(FLAGS) -c ft_lstadd_back.c -o ft_lstadd_back.o

ft_lstadd_front.o : ft_lstadd_front.c
	gcc $(FLAGS) -c ft_lstadd_front.c -o ft_lstadd_front.o

ft_lstclear.o : ft_lstclear.c
	gcc $(FLAGS) -c ft_lstclear.c -o ft_lstclear.o

ft_lstdelone.o : ft_lstdelone.c
	gcc $(FLAGS) -c ft_lstdelone.c -o ft_lstdelone.o

ft_lstiter.o : ft_lstiter.c
	gcc $(FLAGS) -c ft_lstiter.c -o ft_lstiter.o

ft_lstlast.o : ft_lstlast.c
	gcc $(FLAGS) -c ft_lstlast.c -o ft_lstlast.o

ft_lstmap.o : ft_lstmap.c
	gcc $(FLAGS) -c ft_lstmap.c -o ft_lstmap.o

ft_lstnew.o : ft_lstnew.c
	gcc $(FLAGS) -c ft_lstnew.c -o ft_lstnew.o

ft_lstsize.o : ft_lstsize.c
	gcc $(FLAGS) -c ft_lstsize.c -o ft_lstsize.o

ft_memccpy.o : ft_memccpy.c
	gcc $(FLAGS) -c ft_memccpy.c -o ft_memccpy.o

ft_memchr.o : ft_memchr.c
	gcc $(FLAGS) -c ft_memchr.c -o ft_memchr.o

ft_memcmp.o : ft_memcmp.c
	gcc $(FLAGS) -c ft_memcmp.c -o ft_memcmp.o

ft_memcpy.o : ft_memcpy.c
	gcc $(FLAGS) -c ft_memcpy.c -o ft_memcpy.o

ft_memmove.o : ft_memmove.c
	gcc $(FLAGS) -c ft_memmove.c -o ft_memmove.o

ft_memset.o : ft_memset.c
	gcc $(FLAGS) -c ft_memset.c -o ft_memset.o

ft_putchar_fd.o : ft_putchar_fd.c
	gcc $(FLAGS) -c ft_putchar_fd.c -o ft_putchar_fd.o

ft_putendl_fd.o : ft_putendl_fd.c
	gcc $(FLAGS) -c ft_putendl_fd.c -o ft_putendl_fd.o

ft_putnbr_fd.o : ft_putnbr_fd.c
	gcc $(FLAGS) -c ft_putnbr_fd.c -o ft_putnbr_fd.o

ft_putstr_fd.o : ft_putstr_fd.c
	gcc $(FLAGS) -c ft_putstr_fd.c -o ft_putstr_fd.o

ft_split.o : ft_split.c
	gcc $(FLAGS) -c ft_split.c -o ft_split.o

ft_strchr.o : ft_strchr.c
	gcc $(FLAGS) -c ft_strchr.c -o ft_strchr.o

ft_strdup.o : ft_strdup.c
	gcc $(FLAGS) -c ft_strdup.c -o ft_strdup.o

ft_strjoin.o : ft_strjoin.c
	gcc $(FLAGS) -c ft_strjoin.c -o ft_strjoin.o

ft_strlcat.o : ft_strlcat.c
	gcc $(FLAGS) -c ft_strlcat.c -o ft_strlcat.o

ft_strlcpy.o : ft_strlcpy.c
	gcc $(FLAGS) -c ft_strlcpy.c -o ft_strlcpy.o

ft_strlen.o : ft_strlen.c
	gcc $(FLAGS) -c ft_strlen.c -o ft_strlen.o

ft_strmapi.o : ft_strmapi.c
	gcc $(FLAGS) -c ft_strmapi.c -o ft_strmapi.o

ft_strrchr.o : ft_strrchr.c
	gcc $(FLAGS) -c ft_strrchr.c -o ft_strrchr.o

ft_strtrim.o : ft_strtrim.c
	gcc $(FLAGS) -c ft_strtrim.c -o ft_strtrim.o

ft_substr.o : ft_substr.c
	gcc $(FLAGS) -c ft_substr.c -o ft_substr.o

ft_tolower.o : ft_tolower.c
	gcc $(FLAGS) -c ft_tolower.c -o ft_tolower.o

ft_toupper.o : ft_toupper.c
	gcc $(FLAGS) -c ft_toupper.c -o ft_toupper.o

ft_strnstr.o : ft_strnstr.c
	gcc $(FLAGS) -c ft_strnstr.c -o ft_strnstr.o

#BONUSES

ft_calc_digits_bonus.o : ft_calc_digits_bonus.c
	gcc $(FLAGS) -c ft_calc_digits_bonus.c -o ft_calc_digits_bonus.o

ft_calc_spaces_bonus.o : ft_calc_spaces_bonus.c
	gcc $(FLAGS) -c ft_calc_spaces_bonus.c -o ft_calc_spaces_bonus.o

ft_count_words_bonus.o : ft_count_words_bonus.c
	gcc $(FLAGS) -c ft_count_words_bonus.c -o ft_count_words_bonus.o

ft_islower_bonus.o : ft_islower_bonus.c
	gcc $(FLAGS) -c ft_islower_bonus.c -o ft_islower_bonus.o

ft_isspace_bonus.o : ft_isspace_bonus.c
	gcc $(FLAGS) -c ft_isspace_bonus.c -o ft_isspace_bonus.o

ft_isupper_bonus.o : ft_isupper_bonus.c
	gcc $(FLAGS) -c ft_isupper_bonus.c -o ft_isupper_bonus.o

ft_memdel_bonus.o : ft_memdel_bonus.c
	gcc $(FLAGS) -c ft_memdel_bonus.c -o ft_memdel_bonus.o

ft_print_memory_bonus.o : ft_print_memory_bonus.c
	gcc $(FLAGS) -c ft_print_memory_bonus.c -o ft_print_memory_bonus.o

ft_putchar_bonus.o : ft_putchar_bonus.c
	gcc $(FLAGS) -c ft_putchar_bonus.c -o ft_putchar_bonus.o

ft_putendl_bonus.o : ft_putendl_bonus.c
	gcc $(FLAGS) -c ft_putendl_bonus.c -o ft_putendl_bonus.o

ft_putnbr_bonus.o : ft_putnbr_bonus.c
	gcc $(FLAGS) -c ft_putnbr_bonus.c -o ft_putnbr_bonus.o

ft_putstr_bonus.o : ft_putstr_bonus.c
	gcc $(FLAGS) -c ft_putstr_bonus.c -o ft_putstr_bonus.o

ft_stralloc_bonus.o : ft_stralloc_bonus.c
	gcc $(FLAGS) -c ft_stralloc_bonus.c -o ft_stralloc_bonus.o

ft_strappend_bonus.o : ft_strappend_bonus.c
	gcc $(FLAGS) -c ft_strappend_bonus.c -o ft_strappend_bonus.o

ft_strcat_bonus.o : ft_strcat_bonus.c
	gcc $(FLAGS) -c ft_strcat_bonus.c -o ft_strcat_bonus.o

ft_strclr_bonus.o : ft_strclr_bonus.c
	gcc $(FLAGS) -c ft_strclr_bonus.c -o ft_strclr_bonus.o

ft_strcmp_bonus.o : ft_strcmp_bonus.c
	gcc $(FLAGS) -c ft_strcmp_bonus.c -o ft_strcmp_bonus.o

ft_strcpy_bonus.o : ft_strcpy_bonus.c
	gcc $(FLAGS) -c ft_strcpy_bonus.c -o ft_strcpy_bonus.o

ft_strdel_bonus.o : ft_strdel_bonus.c
	gcc $(FLAGS) -c ft_strdel_bonus.c -o ft_strdel_bonus.o

ft_strequ_bonus.o : ft_strequ_bonus.c
	gcc $(FLAGS) -c ft_strequ_bonus.c -o ft_strequ_bonus.o

ft_striter_bonus.o : ft_striter_bonus.c
	gcc $(FLAGS) -c ft_striter_bonus.c -o ft_striter_bonus.o

ft_striteri_bonus.o : ft_striteri_bonus.c
	gcc $(FLAGS) -c ft_striteri_bonus.c -o ft_striteri_bonus.o

ft_strmap_bonus.o : ft_strmap_bonus.c
	gcc $(FLAGS) -c ft_strmap_bonus.c -o ft_strmap_bonus.o

ft_strncat_bonus.o : ft_strncat_bonus.c
	gcc $(FLAGS) -c ft_strncat_bonus.c -o ft_strncat_bonus.o

ft_strncpy_bonus.o : ft_strncpy_bonus.c
	gcc $(FLAGS) -c ft_strncpy_bonus.c -o ft_strncpy_bonus.o

ft_strnequ_bonus.o : ft_strnequ_bonus.c
	gcc $(FLAGS) -c ft_strnequ_bonus.c -o ft_strnequ_bonus.o

ft_strnew_bonus.o : ft_strnew_bonus.c
	gcc $(FLAGS) -c ft_strnew_bonus.c -o ft_strnew_bonus.o
