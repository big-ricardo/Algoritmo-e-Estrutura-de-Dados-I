CC = gcc
CFLAGS = -pedantic-errors -Wall -g
LDFLASGS = -lm

FONTES = $(wildcard *.c)

OBJETOS = $(FONTES:.c=.o)

EXECUTAVEL = programa.exe

all: $(EXECUTAVEL)

$(EXECUTAVEL) : $(OBJETOS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLASGS)

%.o: %.c
	$(CC) -c $(CFLAGS) $^

clean:
	rm -rf *.o *.exe

rmproper: clean
	rm -rf $(EXECUTAVEL)

run: $(EXECUTAVEL)
	./$(EXECUTAVEL)
