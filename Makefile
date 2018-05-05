##########
# MAKEFILE FOURNI
#
# En principe: inutile de le modifier !

GCC := gcc -g -Wall -Werror
EXE := exo_partiel

.PHONY: exe execlean

exe: $(EXE)

# executables
debug_lexer: debug_lexer.o lexer.o
	$(GCC) $^ -o $@

# dependencies
list.o: list.c list.h
lexer.o: lexer.c lexer.h
debug_lexer.o: debug_lexer.c lexer.h
exo_partiel.o: exo_partiel.c lexer.h list.h

# modular compilation
%.o: %.c
	$(GCC) -c $< -o $@

# cleaning
execlean:
	$(RM) $(EXE) *.o *~
