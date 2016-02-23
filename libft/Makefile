# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qduperon <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/27 11:29:17 by qduperon          #+#    #+#              #
#    Updated: 2016/02/08 15:15:49 by qduperon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#===========================================================#
#	   			    //   LIBRARY   \\                       #
#===========================================================#

NAME = libft.a

#===========================================================#
#                    //   SOURCES   \\                      #
#===========================================================#

SRC_TEST	 =	test/ft_isalnum.c \
	  			test/ft_isalpha.c \
	  			test/ft_isascii.c \
	  			test/ft_isdigit.c \
	  			test/ft_isprint.c \
	  			test/ft_isspace.c \

SRC_LIST 	=	list/ft_lstadd.c \
	  			list/ft_lstdel.c \
	  			list/ft_lstdelone.c \
	  			list/ft_lstiter.c \
	  			list/ft_lstmap.c \
	  			list/ft_lstnew.c \

SRC_MEMORY	=	memory/ft_memalloc.c \
	  			memory/ft_memccpy.c \
	  			memory/ft_memchr.c \
	  			memory/ft_memcmp.c \
	  			memory/ft_memcpy.c \
	  			memory/ft_memdel.c \
	  			memory/ft_memmove.c \
	  			memory/ft_memset.c \

SRC_PRINT	=	print/ft_putchar.c \
	  			print/ft_putchar_fd.c \
	  			print/ft_putendl.c \
	  			print/ft_putendl_fd.c \
	  			print/ft_putnbr.c \
	  			print/ft_putnbr_fd.c \
	 			print/ft_putstr.c \
	  			print/ft_putstr_fd.c \

SRC_STRING	=	string/ft_strcat.c \
	  			string/ft_strchr.c \
	  			string/ft_strclr.c \
	  			string/ft_strcmp.c \
	  			string/ft_strcpy.c \
	  			string/ft_strdel.c \
	 			string/ft_strdup.c \
	  			string/ft_strequ.c \
	  			string/ft_striter.c \
	  			string/ft_striteri.c \
	  			string/ft_strjoin.c \
	  			string/ft_strlcat.c \
	  			string/ft_strlen.c \
	  			string/ft_strmap.c \
	  			string/ft_strmapi.c \
	  			string/ft_strncat.c \
	  			string/ft_strncmp.c \
	  			string/ft_strncpy.c \
	  			string/ft_strnequ.c \
	 			string/ft_strnew.c \
	  			string/ft_strnstr.c \
	  			string/ft_strrchr.c \
	  			string/ft_strrev.c \
	  			string/ft_strsplit.c \
	  			string/ft_strstr.c \
	  			string/ft_strsub.c \
	  			string/ft_strtolower.c \
	 			string/ft_strtoupper.c \
	  			string/ft_strtrim.c \

SRC_UTILITY	=	utility/ft_atoi.c \
				utility/ft_bzero.c \
				utility/ft_itoa.c \
				utility/ft_size_base.c \
	  			utility/ft_tolower.c \
	  			utility/ft_toupper.c \
				utility/get_next_line.c \

#================================================================#
#                       //  OBJECTS  \\                          #
#================================================================#

OBJECTS		=	ft_atoi.o \
				ft_bzero.o \
				ft_isalnum.o \
				ft_isalpha.o \
				ft_isascii.o \
				ft_isdigit.o \
				ft_isprint.o \
				ft_itoa.o \
				ft_isspace.o \
				ft_lstadd.o \
				ft_lstdel.o \
				ft_lstdelone.o \
				ft_lstiter.o \
				ft_lstmap.o \
				ft_lstnew.o \
				ft_memalloc.o \
				ft_memccpy.o \
				ft_memchr.o \
				ft_memcmp.o \
				ft_memcpy.o \
				ft_memdel.o \
				ft_memmove.o \
				ft_memset.o \
				ft_putchar.o \
				ft_putchar_fd.o \
				ft_putendl.o \
				ft_putendl_fd.o \
				ft_putnbr.o \
				ft_putnbr_fd.o \
				ft_putstr.o \
				ft_putstr_fd.o \
				ft_size_base.o \
				ft_strcat.o \
				ft_strchr.o \
				ft_strclr.o \
				ft_strcmp.o \
				ft_strcpy.o \
				ft_strdel.o \
				ft_strdup.o \
				ft_strequ.o \
				ft_striter.o \
				ft_striteri.o \
				ft_strjoin.o \
				ft_strlcat.o \
				ft_strlen.o \
				ft_strmap.o \
				ft_strmapi.o \
				ft_strncat.o \
				ft_strncmp.o \
				ft_strncpy.o \
				ft_strnequ.o \
				ft_strnew.o \
				ft_strnstr.o \
				ft_strrchr.o \
				ft_strrev.o \
				ft_strsplit.o \
				ft_strstr.o \
				ft_strsub.o \
				ft_strtolower.o \
				ft_strtoupper.o \
				ft_strtrim.o \
				ft_tolower.o \
				ft_toupper.o \
				get_next_line.o \

#============================================================#
#                      //  FLAGS  \\                         #
#============================================================#

FLAGS = -Werror -Wextra -Wall

#============================================================#
#                   //  COMPILATION  \\                      #
#============================================================#

all: $(NAME)

$(NAME):
	@echo "\033[32mBegin Compilation...\033[00m"
	gcc $(FLAGS) -c $(SRC_TEST) $(SRC_LIST) $(SRC_MEMORY) \
		$(SRC_PRINT) $(SRC_STRING) $(SRC_UTILITY) -I ./includes
	@echo "\033[31mCompilation Sucessfull"
	@echo "\033[32mBegin Library...\033[00m"
	ar -r $(NAME) $(OBJECTS)
	ranlib $(NAME)
	mkdir Temporary
	mv $(OBJECTS) Temporary	
	@echo "\033[31mLibrary Finished\033[00m"

#============================================================#
#                     //  DELETING  \\                       #
#============================================================#

clean:
	@echo "\033[35mDeleting Objects...\033[00m"
	rm -rf Temporary
	@echo "\033[31mDone\033[00m"

fclean: clean
	@echo "\033[35mDeleting Library...\033[00m"
	rm -f $(NAME)
	@echo "\033[31mDone\033[00m"

#============================================================#
#	     			   //  RETRY  \\                         #
#============================================================#

re: fclean all

.PHONY : all clean fclean re
