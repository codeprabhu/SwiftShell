CC = gcc

CFLAGS = -Wall -Wextra -Iinclude
LDFLAGS = -lcjson -lm

APPS = \
	apps/app_loader.c \
	apps/swifTop/swifTop_app.c \
	apps/swifTop/dashboard/dashboard.c \
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
	apps/spotify/dashboard/dashboard.c \
	apps/spotify/models/spotify_track.c \
	apps/spotify/services/spotify_service.c \
	apps/spotify/spotify_app.c \
	apps/clock/clock_app.c \
	apps/clock/dashboard/dashboard.c \
	apps/calendar/calendar_app.c \
	apps/calendar/dashboard/dashboard.c \
	apps/explorer/dashboard/dashboard.c \
	apps/explorer/services/file_service.c \
	apps/explorer/models/file_entry.c \
	apps/explorer/explorer_app.c

FRAMEWORK = \
	src/main.c \
	src/shell.c \
	src/plugin_manager.c \
	src/parser.c \
	src/dispatcher.c \
	src/executor.c\
	src/app_manager.c \
	src/services/ai/ai.c \
	src/services/http/http.c

PLUGINS = \
	plugins/plugin_loader.c \
	plugins/swiftsays/swiftsays_plugin.c \
	plugins/swiftsays/animals/animals.c \
	plugins/swiftsays/formatter/formatter.c \
	plugins/swiftsays/services/swiftsays_service.c \
	plugins/notes/notes_plugin.c \
	plugins/ask/ask_plugin.c \
	plugins/github/github_plugin.c \
	plugins/github/github_parser.c \
	plugins/github/github_service.c \
	plugins/github/github_formatter.c \
	plugins/github/models/github_user.c \
	plugins/github/models/github_repo.c \
	plugins/github/models/github_issues.c \
	plugins/github/models/github_release.c \
	plugins/weather/weather_formatter.c \
	plugins/weather/weather_parser.c \
	plugins/weather/weather_plugin.c \
	plugins/weather/weather_service.c \
	plugins/weather/weather_model.c \
	plugins/ascii/ascii_formatter.c \
	plugins/ascii/ascii_service.c \
	plugins/ascii/ascii_plugin.c \
	plugins/ascii/ascii_convert.c \
	plugins/ascii/ascii_image.c \
	plugins/ascii/ascii_resize.c \
	plugins/ascii/stb_image.c \
	
SRC = \
	$(APPS) \
	$(FRAMEWORK) \
	$(PLUGINS)

TARGET = swift

all:
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET) $(LDFLAGS)

run: all
	./$(TARGET)

clean:
	rm -f $(TARGET)