NAME		=	convert

SRCS		=	Convert.cpp		main.cpp
OBJS		=	$(SRCS:.cpp=.o)

CXX			=	c++	
CXXFLAGS	=	-std=c++98 -pedantic-errors -Wall -Wextra -Werror -g

all : $(NAME)

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

%.o : %.cpp Convert.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

test :
	$(CXX) $(CXXFLAGS) main_tests.cpp Convert.cpp -o convert_tests

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)
	rm -f convert_tests

re : fclean all

.PHONY : all clean fclean re test
