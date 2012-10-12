CC = gcc

CFLAGS = -Wall -Wextra -Lsrc -lm

RM = rm -f

OBJS = src/main.c src/crc.c

VALGRIND = valgrind -v --read-var-info=yes --tool=memcheck --leak-check=yes --show-reachable=yes --track-origins=yes
#VALGRIND = valgrind  --read-var-info=yes --tool=memcheck --leak-check=yes -v
#VALGRIND = valgrind  --track-origins=yes --tool=memcheck --leak-check=yes -v
#VALGRIND = valgrind  --tool=memcheck

MAIN = crc

$(MAIN): $(OBJS)
	@echo ""
	@echo "------------------------"
	@echo " Compilando programa..."
	@echo "------------------------"
	@$(CC) $(OBJS) -g3 -std=c99 -o $(MAIN) $(CFLAGS)
	@echo "------------------------"
	@echo " Compilacao feita com sucesso!"
	@echo "------------------------"

%.o: %.c %.h
	@echo "------------------------"
	@echo " Compilando objeto \"$@\""
	@echo "------------------------"
	@$(CC) $(CFLAGS) $< -c

clean:
	$(RM) $(MAIN) *.o *~ testes/*~
	$(RM) entrada/ent* saida/sai* tempo/*
	clear

val: $(MAIN)
	$(VALGRIND) ./$(MAIN) arquivo.txt 0

run: $(MAIN)
	@echo " Executando programa..."
	@echo "------------------------"
	@echo ""
	./$(MAIN) arquivo.txt 0

all: clean run val
