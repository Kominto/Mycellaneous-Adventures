.PHONY: all clean mrproper run rebuild

NAME = Test
CPP = g++
RM = rm -f
LDFLAGS = -lSDL2 -lSDL2_image
CFLAGS := -Wall
SOURCES = $(wildcard src/*.cpp) $(wildcard src/*/*.cpp)
HEADERS = $(wildcard src/*.h) $(wildcard src/*/*.h)
OBJECTS = $(foreach source, $(SOURCES), build/$(patsubst src/%.cpp,%.o,$(source)))
BINARY = bin/$(NAME)

all: $(BINARY)

clean:
	$(RM) $(OBJECTS)
	$(RM) Makefile.deps
	$(RM) build/?*.*

mrproper: clean
	$(RM) $(BINARY)

rebuild:
	@make mrproper
	@make

run: all
	./$(BINARY)

include Makefile.deps
Makefile.deps: $(SOURCES) $(HEADERS)
	@echo "Computing dependencies"
	@$(RM) Makefile.deps
	@for file in $(SOURCES); do echo "`echo $$file | sed 's|^src/|build/|' | sed 's|[^/]*$$||'``g++ $(CFLAGS) -M $$file`" >> Makefile.deps; done

$(BINARY): $(OBJECTS)
	$(CPP) $(CFLAGS) $(LDFLAGS) -o $@ $^

build/%.o: src/%.cpp
	$(CPP) $(CFLAGS) -o $@ -c $<

