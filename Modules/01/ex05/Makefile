NAME		=	karen

SRCS		=	Karen.cpp main.cpp
OBJS		=	$(SRCS:.cpp=.o)

CXX			=	c++
CXXFLAGS	=	-std=c++98 -pedantic-errors	-Wall -Wextra -Werror

all	: $(NAME)

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

%.o : %.cpp Karen.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
