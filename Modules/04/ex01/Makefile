NAME		=	poly

SRCS		=	Animal.cpp	Brain.cpp	Cat.cpp		Dog.cpp		main.cpp
OBJS		=	$(SRCS:.cpp=.o)

INCLUDES	=	Animal.hpp	Brain.hpp	Cat.hpp		Dog.hpp

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
