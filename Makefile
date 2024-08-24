CC = clang
CFLAGS = -Wall -Wextra -O2 

TARGET = dynamic_arrays

all: $(TARGET)

dynamic_arrays: main.c
	$(CC) $(CFLAGS) -o $(TARGET) main.c

clean:
	rm -f $(TARGET)

rebuild: clean all
