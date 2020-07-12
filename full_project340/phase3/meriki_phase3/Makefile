all:
	flex --outfile=al.c al.l
	bison -v --yacc --defines --output=parser.c parser.y
	gcc -g -o calc.out al.c parser.c SymTable.h

clean:
	rm -rf *.out

	