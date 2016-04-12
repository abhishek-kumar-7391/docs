all : ipval

ipval : cvm.o getopt.o
	gcc $^ -o $@
	@rm -f *.o

cvm.o : cvm.c	
	gcc -c $^

getopt.o : getopt.c
	gcc -c $^

debug : dcvm

dcvm : dcvm.o dgetopt.o
	gcc $^ -o cvm
	@rm -f *.o

dcvm.o : cvm.c	
	gcc -DDEBUG -c $^ -o $@

dgetopt.o : getopt.c
	gcc -DDEBUG -c $^ -o $@

.PHONY : clean
clean : 
	@rm -f cvm ipval
