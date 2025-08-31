CC = clang
CFLAGS = -Wall -Wextra -O2 

TARGET = main 

all: $(TARGET)

main: main.c
	$(CC) $(CFLAGS) -o $(TARGET) main.c dray.c

clean:
	rm -f $(TARGET)

rebuild: clean all
