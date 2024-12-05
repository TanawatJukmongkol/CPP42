# Basic configs
NAME			= btc
CXX				= c++

# Sources and headers
SRCS			= main.cpp \
				  BitcoinExchange.cpp

HEADERS			= BitcoinExchange.hpp

# Path configuration
SRC_DIR			= .
BUILD_DIR		= build
HEADER_DIR		= .

# Flags and library linking
CXXFLAGS		= $(CXXFLAGS_DEV) \
				  -Wall \
				  -Werror \
				  -Wextra

CXXFLAGS_DEV	= -g \
				  -std=c++98 \
				  -pedantic

INCLUDES		=
INCLUDES_SRC	= $(INCLUDES)
INCLUDES_OBJ	= $(INCLUDES)

# Internal environment variables
OBJS			= ${SRCS:.cpp=.o}
OBJ				= $(addprefix $(BUILD_DIR)/,$(OBJS))
SRC				= $(addprefix $(SRC_DIR)/,$(SRCS))
HEADER			= $(addprefix $(HEADER_DIR)/,$(HEADERS))

SHELL = bash

SPACE := $(subst ,, )

all: $(NAME)

$(NAME): .gitignore $(BUILD_DIR) $(SRC) $(OBJ)
	@ echo "LD $(NAME)"
	@ $(CXX) -o $(NAME) $(OBJ) $(INCLUDES_SRC) $(CXXFLAGS)

$(BUILD_DIR):
	@ echo "MKDIR $(BUILD_DIR)"
	@ mkdir -p $(BUILD_DIR)

clean:
	@ echo "RM $(BUILD_DIR)"
	@ rm -rf $(BUILD_DIR)

fclean: clean
	@ echo "RM $(NAME)"
	@ rm -f $(NAME)

re: clean all

%.class:
	@ echo "Generating class header boilerplate..."
	@ $(eval class_name:=$(subst .class,,$@))
	@ $(eval class_header:=$(HEADER_DIR)/$(class_name).hpp)
	@ $(eval class_header_def:=$(shell echo $(class_name)_HPP | tr '[:lower:]' '[:upper:]'))
	@ echo "#ifndef $(class_header_def)" > $(class_header)
	@ echo -ne "# define $(class_header_def)\n\n" >> $(class_header)
	@ echo -ne "class $(class_name)\n{\n\tpublic:\n" >> $(class_header)
	@ echo -ne "\t\t$(class_name)();\n\t\t~$(class_name)();\n" >> $(class_header)
	@ echo -ne "\t\t$(class_name)($(class_name) const &copy);\n" >> $(class_header)
	@ echo -ne "\t\t$(class_name) &operator=($(class_name) const &assignment);\n" >> $(class_header)
	@ echo -ne "};\n\n#endif\n" >> $(class_header)
	@ echo "Generating class body boilerplate..."
	@ $(eval class_body:=$(SRC_DIR)/$(class_name).cpp)
	@ echo "#include \"../$(class_header)\"" > $(class_body)
	@ echo -ne "#include <iostream>\n\n" >> $(class_body)
	@ echo -ne "$(class_name)::$(class_name)()\n{\n\tstd::cout << \"$(class_name) created\" << std::endl;\n}\n\n" >> $(class_body)
	@ echo -ne "$(class_name)::~$(class_name)()\n{\n\tstd::cout << \"$(class_name) destroyed\" << std::endl;\n}\n\n" >> $(class_body)
	@ echo -ne "$(class_name)::$(class_name)($(class_name) const &copy)\n{\n\t*this = copy;\n}\n\n" >> $(class_body)
	@ echo -ne "$(class_name)\t&$(class_name)::operator=($(class_name) const &assignment)\n{\n\treturn *this;\n}\n" >> $(class_body)

%.class-rm:
	@ $(eval class_name:=$(subst .class-rm,,$@))
	@ $(eval class_header:=$(HEADER_DIR)/$(class_name).hpp)
	@ $(eval class_body:=$(SRC_DIR)/$(class_name).cpp)
	@ echo "Remove class $(class_name)..."
	@ rm -f $(class_header) $(class_body)

$(BUILD_DIR)/%.o:$(SRC_DIR)/%.cpp $(HEADER) Makefile
	@ echo "CXX $<"
	@ $(CXX) $(CXXFLAGS) $(INCLUDES_OBJ) -c $< -o $@

.gitignore: Makefile
	@ echo "Generate .gitignore..."
	@ echo -ne "*\n!*/\n!.gitignore\n!Makefile\n" > .gitignore
	@ echo -ne "$(subst $(SPACE),\n,$(addprefix !,${SRC}))\n" >> .gitignore
	@ echo -ne "$(subst $(SPACE),\n,$(addprefix !,${HEADER}))\n" >> .gitignore
	@ echo "Rebuild tracked files cache..."
	@ git rm -rf --cached . > /dev/null && git add .

.PHONY: all clean fclean re %.class
