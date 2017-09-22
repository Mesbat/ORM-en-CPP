CC = g++
NAME = liborm
SNAME = $(NAME).a
SRC = 	dev/Table.cpp		\
				dev/DB.cpp			\
				dev/Field.cpp		\

OBJ = $(SRC:%.cpp=%.o)
RM = rm -f
CXXFLAGS += -Wall -Wextra -Wpedantic -Werror -std=c++11 -I/usr/include/cppconn -L/usr/lib -lmysqlcppconn

all:	owlorm_static

owlorm_static:	$(SNAME)

exec: $(NAME)

$(NAME):	$(OBJ)
			$(CXX) $(OBJ) -o $(NAME)


$(SNAME):	$(OBJ)
			ar rc $(NAME).a $(OBJ)
			ranlib $(NAME).a

clean:
	$(RM) $(OBJ)

fclean:clean
		$(RM) $(SNAME)

re:	fclean all

.PHONY: all clean fclean re
