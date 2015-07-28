CC=clang
BIN=evenet
SDIR=src
OBJS:=$(shell find src -name '*.c' -exec basename {} \; | sed 's/\.c/.o/')
LIBS=-lssh
CFLAGS=-std=c99 -Wall -I/usr/local/include -Iinih/ -Isrc/

all: $(BIN)

$(BIN): $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

%.o: $(SDIR)/%.c $(SDIR)/%.h
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm -rf $(BIN) *.o
