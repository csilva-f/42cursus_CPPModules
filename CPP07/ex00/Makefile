NAME = Conversor

CXX = c++ -fsanitize=address -ggdb
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
OBJS_FOLDER = objs
RM = rm -rf

_FILES = ScalarConverter
OBJS = $(_FILES:%=%.o)
TARGET = $(addprefix $(OBJS_FOLDER)/, $(OBJS))

all : 		${NAME}

${NAME}:	${OBJS_FOLDER} ${TARGET} main.cpp
			${CXX} ${CXXFLAGS} main.cpp ${TARGET} -o ${NAME}

${OBJS_FOLDER}/%.o: %.cpp
			${CXX} ${CXXFLAGS} -c $< -o $@

${OBJS_FOLDER}:
			mkdir -p ${OBJS_FOLDER}

clean:
			${RM} ${OBJS_FOLDER}

fclean: 	clean
			${RM} ${NAME}

re: 		fclean all

.PHONY: 	fclean clean all re
