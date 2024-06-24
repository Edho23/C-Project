# Define the compiler
CC = gcc

# Define flags for compilation (feel free to customize)
CFLAGS = -Wall -Wextra -g

# Define all source files
SRC_FILES = Main.c fungsi1.c fungsi2.c fungsi3.c fungsi4.c

# Define the executable name
EXEC_NAME = kalkulator_biner

# Target to build the executable
all: $(EXEC_NAME)

$(EXEC_NAME): $(SRC_FILES)
	$(CC)	$(CFLAGS)	-o	$(EXEC_NAME)	$^

# Target to clean up object files
clean:
	rm-f	$(EXEC_NAME)	*.o

# Target to run the executable (if desired)
run: $(EXEC_NAME)
	./$(EXEC_NAME)
