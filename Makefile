all:
	gcc -o pipes pipes.c
run:
	gcc -o pipes pipes.c
	./pipes
install:
	cp pipes ~/.local/bin/pipes
