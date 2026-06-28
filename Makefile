CC = gcc

CFLAGS = -Wall -Wextra -Iinclude

SRC = \
	src/main.c \
	src/shell.c \
	src/plugin_manager.c \
	src/parser.c \
	src/dispatcher.c \
	src/executor.c\
	src/app_manager.c \
	apps/dashboard/dashboard.c \
	apps/app_loader.c \
	apps/swifTop/swifTop_app.c \
	apps/swifTop/metrics/metrics.c \
	apps/swifTop/models/system_stats.c \
	apps/swifTop/history/history.c \
	apps/swifTop/widgets/graph.c \
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