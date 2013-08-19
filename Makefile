CC = gcc
CFLAGS = -O2 -march=native
CFLAGS += -Wall -Wextra -pedantic -std=c89
CFLAGS += -Wpadded -Wwrite-strings
OBJECTS = clock.o util.o
PREFIX ?= /usr/local

.PHONY: all
all: clock

clock: $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $<

.PHONY: clean
clean:
	rm -f clock $(OBJECTS)

.PHONY: install
install: all
	install -d '$(DESTDIR)$(PREFIX)/bin'
	install -t '$(DESTDIR)$(PREFIX)/bin' clock
