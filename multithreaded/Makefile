CC = g++ -std=c++20
CFLAGS = -Iinclude
SRC = $(wildcard src/*.cpp)

dbg: CC += -g -W -DDEBUG
dbg: shell

rel: CC += -O2
rel: shell

shell:
	$(CC) $(CFLAGS) $(SRC) -o shell

clean:
	rm -f shell
