# Name of executable file
PROJECT_NAME = bank

# Output Directory
BUILD = build

$(BUILD):
	mkdir build

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

# All test source files
TEST_SRC = test/bank_test.c\
src/interest.c\
unity/unity.c\

# To Check OS is Windows or Linux

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

TEST_OUTPUT = $(BUILD)/Test_$(PROJECT_NAME).$(EXEC)

#Including all source files

INC = -Iinc\
-Iunity\

# Project Output name
PROJECT_OUTPUT = $(BUILD)/$(PROJECT_NAME).$(EXEC)

all: $(BUILD)
	gcc $(SRC) $(INC) -o $(PROJECT_OUTPUT).$(EXEC)

#run command to run the executable file
run:all
	./$(PROJECT_OUTPUT).$(EXEC)

# Build and run the unit tests
test:$(BUILD)
	gcc $(TEST_SRC) $(INC) -o $(TEST_OUTPUT)
	./$(TEST_OUTPUT)

# Remove all the built files, invoke by `make clean`
clean:
	rm -rf $(BUILD)








