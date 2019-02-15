#Variabile de mediu utile

# Used compiler
CC = gcc
# Compilation flags
CFLAGS = -O2
# fl library needed for default yywrap() function found in libfl.a
LIBS = -lfl
# Output name of executable
NAME = tokenize
# Name of file with lexer rules
RULES = fisier.l
# Name of file to be tokenized
INPUT = alex.cpp

all: build run prune

clean:
	rm -f lex.yy.c $(NAME)

prune:
	rm -f lex.yy.c

build: rules.l
	flex $(RULES)
	$(CC) lex.yy.c -o $(NAME) $(LIBS) $(CFLAGS)

run: $(NAME)
	./$(NAME) $(INPUT)
