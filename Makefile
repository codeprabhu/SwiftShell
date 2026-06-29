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
	apps/swifTop/metrics/cpu.c \
	apps/swifTop/metrics/memory.c \
	apps/swifTop/metrics/threads.c \
	apps/swifTop/metrics/disk.c \
	apps/swifTop/metrics/process.c \
 	apps/swifTop/models/system_stats.c \
	apps/swifTop/history/history.c \
	apps/swifTop/widgets/graph.c \
	apps/swifTop/terminal/terminal.c \
	plugins/plugin_loader.c \
	plugins/hello_plugin.c \
	plugins/notes_plugin.c \
	plugins/ask_plugin.c \
	src/services/ai/ai.c
	

TARGET = swift

all:
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

run: all
	./$(TARGET)

clean:
	rm -f $(TARGET)