NAME = Animals

CXX = c++ -fsanitize=address -ggdb
CXXFLAGS = -Wall -Wextra -Werror -Wshadow -Wno-shadow -Iincludes -std=c++98 -pedantic
OBJS_FOLDER = objs
VPATH = srcs/
RM = rm -rf

SRCS =	main.cpp Dog.cpp Cat.cpp Brain.cpp Animal.cpp WrongCat.cpp WrongAnimal.cpp
OBJS = ${SRCS:%.cpp=${OBJS_FOLDER}/%.o}

${NAME}:	${OBJS_FOLDER} ${OBJS}
			${CXX} ${OBJS} -o ${NAME}

${OBJS_FOLDER}:
			mkdir -p objs

${OBJS_FOLDER}/%.o: %.cpp
			$(CXX) $(CXXFLAGS) -c $< -o $@ 

clean:
			${RM} ${OBJS_FOLDER}

fclean: 	clean
			${RM} ${NAME}

all : 		${NAME}

re: 		fclean all

.PHONY: 	${NAME} fclean clean all re

.SILENT:
