CC = gcc

CFLAGS = -std=c99 -Wall -Wextra -O2 -c

SDL_CFLAGS = $(shell sdl2-config --cflags)
SDL_LFLAGS = $(shell sdl2-config --libs)

override CFLAGS += $(SDL_CFLAGS)

HEADERDIR = src/
SOURCEDIR = src/

HEADERFILES = screen.h 
SOURCEFILES = main.c screen.c

HEADER_PATHS = $(addprefix $(HEADERDIR),$(HEADERFILES))
SOURCE_PATHS = $(addprefix $(SOURCEDIR),$(SOURCEFILES))

OBJECT_FILES = $(SOURCE_PATHS:.c = .o)

EXECUTABLE = chip8

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECT_FILES)
	$(CC) $(OBJECT_FILES) $(SDL_LFLAGS) -o $(EXECUTABLE)

%.o: %.c $(HEADER_PATHS)
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -rf src/*.o $(EXECUTABLE)