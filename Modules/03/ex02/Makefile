NAME		=	fragtrap

SRCS		=	ClapTrap.cpp	FragTrap.cpp	main.cpp	ScavTrap.cpp
OBJS		=	$(SRCS:.cpp=.o)

INCLUDES	=	ClapTrap.hpp	FragTrap.hpp	ScavTrap.hpp

CXX			=	c++
CXXFLAGS	=	-std=c++98 -pedantic-errors -Wall -Werror -Wextra

all : $(NAME)

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
