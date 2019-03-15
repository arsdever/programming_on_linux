COMPILER 	:= g++
FLAGS 		:= -std=c++11 -Wall
SOURCES 	:= $(shell ls *.cpp)
OBJ_DIR		:= ./obj/
OBJECTS 	:= $(SOURCES:%.cpp=$(OBJ_DIR)%.o)
NAME 		:= app

.PHONY : final build rebuild clean create_obj_dir

final : create_obj_dir $(NAME)

$(NAME) : $(OBJECTS)
	@echo Building $@
	@$(COMPILER) $^ -o $@ $(FLAGS)

$(OBJ_DIR)%.o : %.cpp
	@echo Compiling $<
	@$(COMPILER) -c $< -o $@ $(FLAGS)

build : final

rebuild : clean build

clean : 
	@rm -fr $(OBJ_DIR)
	@rm $(NAME)

create_obj_dir : 
	@mkdir -p $(OBJ_DIR)