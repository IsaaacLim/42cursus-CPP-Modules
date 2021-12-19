NAME		=	interface

SRCS		=	AMateria.cpp	Character.cpp		Cure.cpp	Ice.cpp		\
				main.cpp		MateriaSource.cpp
OBJS		=	$(SRCS:.cpp=.o)

INCLUDES	=	AMateria.hpp	Character.hpp		Cure.hpp	Ice.hpp		\
				ICharacter.hpp	IMateriaSource.hpp	MateriaSource.hpp

CXX			=	c++
CXXFLAGS	= 	-std=c++98 -pedantic-errors -Wall -Wextra -Werror -g

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
