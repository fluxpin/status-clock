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

%.d: %.c
	$(CC) $(CFLAGS) -MM -MP $< -MF $@
	sed -i 's/$(@:.d=.o)/$@ &/' $@

-include $(OBJECTS:.o=.d)

.PHONY: clean
clean:
	rm -f clock $(OBJECTS) $(OBJECTS:.o=.d)

.PHONY: install
install: all
	install -d '$(DESTDIR)$(PREFIX)/bin'
	install -t '$(DESTDIR)$(PREFIX)/bin' clock
