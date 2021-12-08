NAME		=	human

SRCS		=	HumanA.cpp	HumanB.cpp	Weapon.cpp	main.cpp
OBJS		=	$(SRCS:.cpp=.o)

HDRS		=	HumanA.hpp	HumanB.hpp	Weapon.hpp	

CXX			=	c++
CXXFLAGS	=	-std=c++98 -pedantic-errors -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

%.o : %.cpp $(HDRS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re
