NAME		=	megaphone

SRCS		=	ClassMegaphone.cpp megaphone.cpp
OBJS		=	$(SRCS:.cpp=.o)

CXX			=	c++
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98 -pedantic-errors

all : $(NAME)

$(NAME) : $(OBJS) 
	$(CXX) $(CXXFLAGS) $^ -o $@

%.o : %.cpp ClassMegaphone.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
