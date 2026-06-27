CC = gcc

CFLAGS = -Wall -Wextra -Iinclude

SRC = \
	src/main.c \
	src/shell.c \
	src/plugin_manager.c \
	src/parser.c \
	src/dispatcher.c \
	src/executor.c\
	plugins/plugin_loader.c \
	plugins/hello_plugin.c \
	plugins/notes_plugin.c

TARGET = swift

all:
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

run: all
	./$(TARGET)

clean:
	rm -f $(TARGET)