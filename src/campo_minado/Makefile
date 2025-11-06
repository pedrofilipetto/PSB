CC=gcc
CFLAGS=-Wall -Wextra -std=c99 -O2
SRC=src
OBJS=$(SRC)/main.o $(SRC)/game.o $(SRC)/board.o $(SRC)/score.o

all: campo_minado
campo_minado: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

clean:
	rm -f $(SRC)/*.o campo_minado
