NAME = Materias

CXX = c++ -fsanitize=address -ggdb
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
OBJS_FOLDER = objs
VPATH = srcs/
RM = rm -rf

SRCS = AMateria.cpp Character.cpp Cure.cpp Ice.cpp MateriaSource.cpp main.cpp
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

.PHONY: 	fclean clean all re
