NAME = fixed

CXX = c++ -fsanitize=address -ggdb
CXXFLAGS = -Wall -Wextra -Werror -Wshadow -Iincludes -std=c++98
OBJS_FOLDER = objs
VPATH = srcs/
RM = rm -rf

SRCS =	main.cpp Fixed.cpp
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
