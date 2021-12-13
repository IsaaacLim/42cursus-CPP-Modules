NAME		=	diamondtrap

SRCS		=	ClapTrap.cpp	DiamondTrap.cpp		FragTrap.cpp	\
				main.cpp	ScavTrap.cpp
OBJS		=	$(SRCS:.cpp=.o)

INCLUDES	=	ClapTrap.hpp	DiamondTrap.hpp		FragTrap.hpp	ScavTrap.hpp

CXX			=	c++
CXXFLAGS	=	-std=c++98 -pedantic-errors -Wall -Werror -Wextra -Wshadow

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
