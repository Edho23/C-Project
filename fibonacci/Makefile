# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall

# Target executable
TARGET = fibonacci.exe

# Source files
SRCS = inputn.c fibo.c

# Object files
OBJS = $(SRCS:.c=.o)

# Default target
all: $(TARGET)

# Build the target executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Compile source files into object files
%.o: %.c
	$(CC) $(CFLAGS) -c $<

# Clean up the build files
clean:
	del $(TARGET) $(OBJS)
