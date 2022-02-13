NAME		=	mStack

SRCS		=	main.cpp	Mutantstack.cpp
OBJS		=	$(SRCS:.cpp=.o)

CXX			=	c++	
CXXFLAGS	=	-std=c++98 -pedantic-errors -Wall -Wextra -Werror -g

all : $(NAME)

$(NAME) : $(SRCS)
	$(CXX) $(CXXFLAGS) $^ -o $@

clean :
	@echo "No object file to remove"

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
