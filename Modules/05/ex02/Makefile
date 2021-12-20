NAME		=	bureaucrat

SRCS		=	Bureaucrat.cpp		Form.cpp	main.cpp
OBJS		=	$(SRCS:.cpp=.o)

INCLUDES	=	Bureaucrat.hpp	Form.hpp

CXX			=	c++
CXXFLAGS	=	-std=c++98 -pedantic-errors -Wall -Wextra -Werror -g

all	: $(NAME)

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

%.o : %.cpp $(INCLUDES)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
