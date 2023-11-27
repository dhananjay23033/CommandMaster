CC = g++
CFLAGS = -Iinclude
SRC = $(wildcard src/*.cpp)

dbg: CC += -g -DDEBUG
dbg: shell

rel: CC += -O2
rel: shell

shell:
	$(CC) $(CFLAGS) $(SRC) -o shell

clean:
	rm -f shell
