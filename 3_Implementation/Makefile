# Name of executable file
PROJECT_NAME = bank

# All source files
 
SRC = src/menu.c\
src/edit.c\
src/erase.c\
src/close.c\
src/new_acc.c\
src/see.c\
src/transact.c\
src/view_list.c\
src/interest.c\
bank.c\

#Including all source files

INC = -Iinc\

ifdef OS
	RM = del /q
	FixPath = $(subst /,\,$1)
	EXEC = exe
else
	ifeq ($(shell uname), Linux)
		RM = rm -rf
		FixPath = $1
		EXEC = out
	endif
endif

$(PROJECT_NAME): $(SRC)
	gcc $(INC) $(SRC)  -o bank.$(EXEC)

#run command to run the executable file

run: $(PROJECT_NAME).$(EXEC)
	$(PROJECT_NAME).$(EXEC)









