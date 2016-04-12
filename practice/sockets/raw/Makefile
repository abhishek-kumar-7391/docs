CC=gcc
LDFLAGS=
CFLAGS= -Wall -g
CPPFLAGS= -DDEBUG
BIN= sniffer

all: $(BIN)

$(BIN): sniffer.o parse_cmdline.o
	$(CC) $(CFLAGS) $(CPPFLAGS) $^ -o $@

sniffer.o: sniffer.c sniffer.h
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $^

parse_cmdline.o: parse_cmdline.c parse_cmdline.h
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $^

.PHONY: clean
clean:
	@rm -rf ./*.o ./*.gch ./$(BIN)

