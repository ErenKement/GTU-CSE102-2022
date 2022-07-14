all: clear clean compile run

clear:
	@clear
	
clean:
	@rm -f *.o
	@rm -f test

compile:
	@gcc -o test util.c main.c 
	
run:
	@./test
