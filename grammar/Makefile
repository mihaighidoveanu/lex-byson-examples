# Makefile

OBJS	= bison.o lex.o main.o

CC	= g++
CFLAGS	= -g -Wall -ansi -pedantic

pyparser:		$(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o pyparser -lfl
	

lex.o:		lex.c
		$(CC) $(CFLAGS) -c lex.c -o lex.o

lex.c:		pyparser.lex 
		flex pyparser.lex
		mv lex.yy.c lex.c

bison.o:	bison.c
		$(CC) $(CFLAGS) -c bison.c -o bison.o

bison.c:	pyparser.y
		bison -d -v pyparser.y
		mv pyparser.tab.c bison.c
		mv pyparser.tab.h tok.h

main.o:		main.cc
		$(CC) $(CFLAGS) -c main.cc -o main.o

lex.o yac.o main.o	: heading.h
lex.o main.o		: tok.h

clean:
	rm -f *.o *~ lex.c lex.yy.c bison.c tok.h pyparser.output pyparser

prune:
	rm -f *.0 *~ lex.c lex.yy.c bison.c tok.h pyparser.output pyparser.tab.h