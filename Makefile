COMPILER 	:= g++
FLAGS 		:= -std=c++11 -Wall -g
SOURCES 	:= $(shell ls *.cpp)
OBJ_DIR		:= ./obj/
OBJECTS 	:= $(SOURCES:%.cpp=$(OBJ_DIR)%.o)

.PHONY : final build rebuild clean create_obj_dir

final : create_obj_dir client server

client : $(filter-out $(OBJ_DIR)main.o,$(OBJECTS))
	@echo Building $@
	@$(COMPILER) $^ -o $@ $(FLAGS)

server : $(filter-out $(OBJ_DIR)client.o,$(OBJECTS))
	@echo Building $@
	@$(COMPILER) $^ -o $@ $(FLAGS)

$(OBJ_DIR)%.o : %.cpp
	@echo Compiling $<
	@$(COMPILER) -c $< -o $@ $(FLAGS)

build : final

rebuild : clean build

clean : 
	@rm -fr $(OBJ_DIR)
	@rm server client

create_obj_dir : 
	@mkdir -p $(OBJ_DIR)