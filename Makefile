CC = gcc

CFLAGS = -Wall -Wextra -Iinclude

SRC = \
	src/main.c \
	src/shell.c \
	src/plugin_manager.c \
	plugins/hello_plugin.c

TARGET = swift

all:
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

run: all
	./$(TARGET)

clean:
	rm -f $(TARGET)